#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QVector>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    void startServer();
    void sendMessageToClients(QString message);
    void sendStatusToClients(QString messageToClient, QString ipAddress);

    //为了便于理解使用名称取代数字标识符
    const static int CONNECTDATABASEFAIL=0;
    const static int OPERASUCCESS=1;
    const static int SIGNINFLAG=1;
    const static int SAMEUSRNAME=2;
    const static int LOGINFAIL=2;
    const static int LOGINFLAG=2;
    const static int SENDMESSAGEFLAG=3;


signals:

public slots:
    void newClientConnection();
    void socketDisconnected();
    void socketReadyRead();
    void socketStateChanged(QAbstractSocket::SocketState state);

private:
    QTcpServer*             chatServer;
    QVector<QTcpSocket*>*   allClients;
    //维护一个list存储在线人员的id
    QList<QString> onlineClient;
};

#endif // SERVER_H
