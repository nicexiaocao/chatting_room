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
