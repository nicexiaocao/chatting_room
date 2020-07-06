
#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QTcpSocket>
#include <QString>
#include <QMouseEvent>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class login; };
QT_END_NAMESPACE

class login : public QDialog
{
	Q_OBJECT

public:
	login(QWidget *parent = Q_NULLPTR);
	~login();
	QTcpSocket *tcpClient; // 让其他窗口可以访问

private:
	Ui::login *ui;
	bool m_moving = false;
	QPoint m_lastPos;
	QString m_user = "user";
	
	QString ip = "118.89.192.223"; //定义ip和端口号
	qint16 const port = 8001;

	void    readSettings(); //读取设置,从注册表
	void    writeSettings();//写入设置，从注册表

private slots:
	void on_btnEnter_clicked();
	void on_btnRegister_clicked();
	void on_btnCancel_clicked();
	void onSocketReadyRead();

	void mousePressEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);
	//读取socket传入的数据
};
#endif //LOGIN_H


