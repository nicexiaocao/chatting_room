
#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QTcpSocket>
#include <QString>
#include <QMouseEvent>
#include <QSettings>
#include <QMessageBox>

//发送标记宏
#define SIGN  "sign:"
#define LOG   "log:"
#define SEND  "send:"

//接收标记宏
#define CONNECTDATABASEFAIL "CONNECTDATABASEFAIL"
#define SAMENAMEERROR	"SAMENAMEERROR"
#define SUCCEEDSIGNIN	"SUCCEEDSIGNIN"
#define LOGINFAIL "LOGINFAIL"
#define SUCCEEDLOGIN "SUCCEEDLOGIN"

//网络连接宏
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
	QTcpSocket *tcpClient; // 让其他窗口可以访问
	

signals:
	void sendData(QString, QString); // 变量传递


private:
	Ui::login *ui;
	bool	m_moving = false;
	QPoint	m_lastPos;
	QString	m_user = "user";
	QString	password;
	
	QString	ip = serverIp; //定义ip和端口号
	qint16	const port = serverPort;

	void    readSettings(); //读取设置,从注册表
	void    writeSettings();//写入设置，从注册表
	

protected:
	bool	eventFilter(QObject * target, QEvent * event);
	

private slots:
	void	on_btnEnter_clicked();
	void	on_btnRegister_clicked();
	void	on_btnCancel_clicked();

	void	mousePressEvent(QMouseEvent * event);//鼠标按下事件
	void	mouseMoveEvent(QMouseEvent * event);//鼠标移动事件
	void	mouseReleaseEvent(QMouseEvent * event);//鼠标释放事件
	
public slots:
	void	onSocketReadyRead();//读取socket传入的数据,主窗口会用到，所以声明public类型

public:
	QString get_id() { return m_user; }
	QString get_password() { return password; }

	
	
	
};
#endif //LOGIN_H


