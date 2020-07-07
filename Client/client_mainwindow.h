#ifndef CLIENT_MAINWINDOW_H
#define CLIENT_MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtNetwork/qsctpsocket.h>
#include <qlabel.h>
#include <QTextCursor>
#include <QKeyEvent>
#include <qframe.h>
#include "login.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Client_MainWindow; class login;}

QT_END_NAMESPACE

class Client_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Client_MainWindow(QWidget *parent = nullptr);
    ~Client_MainWindow();
	QTcpSocket *tcpClient;

protected:
	bool eventFilter(QObject *target, QEvent *event);//事件过滤器


private:
	Ui::Client_MainWindow* ui;
	QLabel  *LabSocketState;  //状态栏显示标签
	QString password;
	bool    connectedToHost;
	void printMessage(QString message);

	// 自定义槽函数
	void    onConnected();  // 连接响应函数
	void    onDisconnected(); //断开连接响应函数
	void    onSocketStateChange(QAbstractSocket::SocketState socketState);
	void    onSocketReadyRead();//读取socket传入的数据

	void on_actConnect_triggered(); //连接
	void on_actDisconnect_triggered(); //断开连接

	void on_btnSend_clicked(); //点击发送
	void on_btnClear_clicked(); //点击清除
	void movetoEnd();
	void receiveData(QString data, QString data2);//接收登录窗口数据


};

#endif // CLIENT_MAINWINDOW_H
