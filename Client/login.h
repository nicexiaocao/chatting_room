
#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QTcpSocket>
#include <QString>
#include <QMouseEvent>
#include <QSettings>
#include <QMessageBox>

//���ͱ�Ǻ�
#define SIGN  "sign:"
#define LOG   "log:"
#define SEND  "send:"

//���ձ�Ǻ�
#define CONNECTDATABASEFAIL "CONNECTDATABASEFAIL"
#define SAMENAMEERROR	"SAMENAMEERROR"
#define SUCCEEDSIGNIN	"SUCCEEDSIGNIN"
#define LOGINFAIL "LOGINFAIL"
#define SUCCEEDLOGIN "SUCCEEDLOGIN"

//�������Ӻ�
#define	serverIp	"118.89.192.223"
#define serverPort	8001

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
	

signals:
	void sendData(QString, QString); // ��������


private:
	Ui::login *ui;
	bool	m_moving = false;
	QPoint	m_lastPos;
	QString	m_user = "user";
	QString	password;
	
	QString	ip = serverIp; //����ip�Ͷ˿ں�
	qint16	const port = serverPort;

	void    readSettings(); //��ȡ����,��ע���
	void    writeSettings();//д�����ã���ע���
	

protected:
	bool	eventFilter(QObject * target, QEvent * event);
	

private slots:
	void	on_btnEnter_clicked();
	void	on_btnRegister_clicked();
	void	on_btnCancel_clicked();

	void	mousePressEvent(QMouseEvent * event);//��갴���¼�
	void	mouseMoveEvent(QMouseEvent * event);//����ƶ��¼�
	void	mouseReleaseEvent(QMouseEvent * event);//����ͷ��¼�
	
public slots:
	void	onSocketReadyRead();//��ȡsocket���������,�����ڻ��õ�����������public����

public:
	QString get_id() { return m_user; }
	QString get_password() { return password; }

	
	
	
};
#endif //LOGIN_H


