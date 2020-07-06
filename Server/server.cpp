#include "server.h"
#include"sqlconnect.h"
Server::Server(QObject *parent) : QObject(parent)
{

}

void Server::startServer()
{
    // store all the connected clients
    allClients = new QVector<QTcpSocket*>;
    // created a QTcpServer object called chatServer
    chatServer = new QTcpServer();
    // limit the maximum pending connections to 20 clients.
    chatServer->setMaxPendingConnections(20);
    // The chatServer will trigger the newConnection() signal whenever a client has connected to the server.
    connect(chatServer, SIGNAL(newConnection()), this, SLOT(newClientConnection()));
    // made it constantly listen to port 8001.
    if (chatServer->listen(QHostAddress::Any, 8001))
    {
        qDebug() << "Server has started. Listening to port 8001.";
    }
    else
    {
        qDebug() << "Server failed to start. Error: " + chatServer->errorString();
    }

}

void Server::sendMessageToClients(QString message)
{
    if (allClients->size() > 0)
    {
        // we simply loop through the allClients array and pass the message data to all the connected clients.
        for (int i = 0; i < allClients->size(); i++)
        {
            if (allClients->at(i)->isOpen() && allClients->at(i)->isWritable())
            {
                allClients->at(i)->write(message.toUtf8());
            }
        }
    }

}

void Server::newClientConnection()
{
    // Every new client connected to the server is a QTcpSocket object,
    // which can be obtained from the QTcpServer object by calling nextPendingConnection().
    QTcpSocket* client = chatServer->nextPendingConnection();
    // You can obtain information about the client
    // such as its IP address and port number by calling peerAddress() and peerPort(), respectively.
    QString ipAddress = client->peerAddress().toString();
    int port = client->peerPort();
    // connect the client's disconnected(),readyRead() and stateChanged() signals to its respective slot function.
    // 1、When a client is disconnected from the server, the disconnected() signal will be triggered
    connect(client, &QTcpSocket::disconnected, this, &Server::socketDisconnected);
    // 2、whenever a client is sending in a message to the server, the readyRead() signal will be triggered.
    connect(client, &QTcpSocket::readyRead, this, &Server::socketReadyRead);
    // 3、 connected another signal called stateChanged() to the socketStateChanged() slot function.
    connect(client, &QTcpSocket::stateChanged, this, &Server::socketStateChanged);
    // store each new client into the allClients array for future use.
    allClients->push_back(client);
    qDebug() << "Socket connected from " + ipAddress + ":" + QString::number(port);
}

// When a client is disconnected from the server, the disconnected() signal will be triggered
void Server::socketDisconnected()
{
    // displaying the message on the server console whenever it happens, and nothing more.
    QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());
    QString socketIpAddress = client->peerAddress().toString();
    int port = client->peerPort();
    QString name=QString(client->readAll());
    QString message="<font color=\"Purple\">" + name.toUtf8() + " has left the chat room.</font>";
    sendMessageToClients(message);
    qDebug() << "Socket disconnected from " + socketIpAddress + ":" + QString::number(port);
}

//传送登录状态,其他人收不到
//根据ip地址选择用户，暂时没想到好办法，可能可以根据用户id
void Server::sendStatusToClients(QString messageToClient,QString ipAddress)
{
    if (allClients->size() > 0)
    {
        // we simply loop through the allClients array and pass the message data to all the connected clients.
        for (int i = 0; i < allClients->size(); i++)
        {
            if (allClients->at(i)->isOpen() && allClients->at(i)->isWritable()
                    &&allClients->at(i)->peerAddress().toString()==ipAddress)
            {
                allClients->at(i)->write(messageToClient.toUtf8());
            }
        }
    }
}

// whenever a client is sending in a message to the server, the readyRead() signal will be triggered.
void Server::socketReadyRead()
{
    // use QObject::sender() to get the pointer of the object that emitted the readyRead signal
    // and convert it to the QTcpSocket class so that we can access its readAll() function.
    QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());
    SqlConnect* sqlcon=new SqlConnect();
    QString socketIpAddress = client->peerAddress().toString();
    int port = client->peerPort();
    QString data = QString(client->readAll());

    //收到的消息为 标识符:名字:密码/消息
    QStringList list = data.split(":");
    qDebug() << "Message: " + data + " (" + socketIpAddress + ":" + QString::number(port) + ")";

    QString messageToClient;//传送给客户端的消息 格式 标识符:消息
    // redirect the message, just passing the message to all connected clients.
    if(list[0]==QString("sign")){
        //注册
        //传来的数据：flag:name:password
        QString usrname=list[1];
        QString password=list[2];
        QString status="CONNECTDATABASEFAIL";
        if(!sqlcon->startConnect()){
            //打开数据库失败
            qDebug()<<"cant open database";
        }
        else if(!sqlcon->signIn(usrname,password)){
            //重名了，发送一个标识
            status="SAMNAMEERROR";
            messageToClient=QString("%1:重名").arg(status);

        }
        else{
            status="SUCCEEDSIGNIN";//成功
            messageToClient=QString("%1:succeed").arg(status);
        }
        sendStatusToClients(messageToClient, socketIpAddress);

    }else if(list[0]==QString("log")){
        //登录，传来flag:ame:password
        QString usrname=list[1];
        QString password=list[2];
        //返回name，进入list
        QString status="CONNECTDATABASEFAIL";
        if(!sqlcon->startConnect()){
            //打开数据库失败
            qDebug()<<"cant open database";
        }

        else if(!sqlcon->logIn(usrname,password)){
            //密码错误,或验证错误
            qDebug()<<"error password";
            status="LOGINFAIL";
            messageToClient=QString("%1:密码或验证错误").arg(status);
        }else{
            qDebug()<<"success log in";
            status="SUCCEEDLOGIN";
            messageToClient=QString("%1:succeed").arg(status);
        }
        sendStatusToClients(messageToClient, socketIpAddress);

    }else{
        //群发消息
        qDebug()<<"send";
        QString message=QString("%1:%2").arg(list[1]).arg(list[2]);
        sendMessageToClients(message);
    }

}

// This function gets triggered whenever a client's network state has changed,
// such as connected, disconnected, listening, and so on.
void Server::socketStateChanged(QAbstractSocket::SocketState state)
{
    QTcpSocket* client = qobject_cast<QTcpSocket*>(QObject::sender());
    QString socketIpAddress = client->peerAddress().toString();
    int port = client->peerPort();
    QString desc;

    // simply print out a relevant message according to its new state
    if (state == QAbstractSocket::UnconnectedState)
        desc = "The socket is not connected.";
    else if (state == QAbstractSocket::HostLookupState)
        desc = "The socket is performing a host name lookup.";
    else if (state == QAbstractSocket::ConnectingState)
        desc = "The socket has started establishing a connection.";
    else if (state == QAbstractSocket::ConnectedState)
        desc = "A connection is established.";
    else if (state == QAbstractSocket::BoundState)
        desc = "The socket is bound to an address and port.";
    else if (state == QAbstractSocket::ClosingState)
        desc = "The socket is about to close (data may still be waiting to be written)."; 
    else if (state == QAbstractSocket::ListeningState)
        desc = "For internal use only.";
    qDebug() << "Socket state changed (" + socketIpAddress + ":" + QString::number(port) + "): " + desc;
}
