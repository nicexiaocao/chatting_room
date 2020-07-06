
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
	QTcpSocket *tcpClient; // ���������ڿ��Է���

private:
	Ui::login *ui;
	bool m_moving = false;
	QPoint m_lastPos;
	QString m_user = "user";
	
	QString ip = "118.89.192.223"; //����ip�Ͷ˿ں�
	qint16 const port = 8001;

	void    readSettings(); //��ȡ����,��ע���
	void    writeSettings();//д�����ã���ע���

private slots:
	void on_btnEnter_clicked();
	void on_btnRegister_clicked();
	void on_btnCancel_clicked();
	void onSocketReadyRead();

	void mousePressEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);
	//��ȡsocket���������
};
#endif //LOGIN_H


