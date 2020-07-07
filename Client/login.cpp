#include "login.h"
#include "ui_login.h"

//表示使用的宏
#define SIGN  "sign:"
#define LOG   "log:"
#define SEND  "send:"

login::login(QWidget *parent): QDialog(parent), ui(new Ui::login)
{
	
	ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	ui->passEdit->setEchoMode(QLineEdit::Password);

	tcpClient = new QTcpSocket; // 建立一个socket连接，在login类中生效
	readSettings(); //读取存储的用户名

	//连接信号和槽
	connect(ui->BtnLogin, &QPushButton::clicked, this, &login::on_btnEnter_clicked);
	connect(ui->BtnRegister, &QPushButton::clicked, this, &login::on_btnRegister_clicked);
	connect(ui->BtnCancel, &QPushButton::clicked, this, &login::on_btnCancel_clicked);


}

login::~login()
{
	delete ui;
}


void login::on_btnEnter_clicked()
{
	this->accept();
	tcpClient->connectToHost(ip, port);
	QString id = ui->idEdit->text();
	QString password = ui->passEdit->text();
	QString LogMessage = LOG + id +":" +  password;
	tcpClient->write(LogMessage.toUtf8());
}

void login::on_btnRegister_clicked()
{
	tcpClient->connectToHost(ip, port);
	QString id = ui->idEdit->text();
	QString password = ui->passEdit->text();
	QString RegMessage = SIGN + id + ":" + password;
	tcpClient->write(RegMessage.toUtf8());
}
void login::on_btnCancel_clicked()
{
	this->close(); // 关闭对话框
}
void login::onSocketReadyRead()
{
	;

}

void login::mousePressEvent(QMouseEvent *event)
{ //鼠标按键被按下
	if (event->button() == Qt::LeftButton)
	{
		m_moving = true;
		//记录下鼠标相对于窗口的位置
		//event->globalPos()鼠标按下时，鼠标相对于整个屏幕位置
		//pos() this->pos()鼠标按下时，窗口相对于整个屏幕位置
		m_lastPos = event->globalPos() - pos();
	}
	return QDialog::mousePressEvent(event);  //
}

void login::mouseMoveEvent(QMouseEvent *event)
{//鼠标按下左键移动
	//(event->buttons() && Qt::LeftButton)按下是左键
	//鼠标移动事件需要移动窗口，窗口移动到哪里呢？就是要获取鼠标移动中，窗口在整个屏幕的坐标，然后move到这个坐标，怎么获取坐标？
	//通过事件event->globalPos()知道鼠标坐标，鼠标坐标减去鼠标相对于窗口位置，就是窗口在整个屏幕的坐标
	if (m_moving && (event->buttons() && Qt::LeftButton)
		&& (event->globalPos() - m_lastPos).manhattanLength() > QApplication::startDragDistance())
	{
		move(event->globalPos() - m_lastPos);
		m_lastPos = event->globalPos() - pos();
	}
	return QDialog::mouseMoveEvent(event);
}

void login::mouseReleaseEvent(QMouseEvent *event)
{//鼠标按键释放
	Q_UNUSED(event);
	m_moving = false; //停止移动
}

void login::readSettings()
{
	//读取存储的用户名和密码, 密码是经过加密的
	QString organization = "Chatting_Roomm-Qt";//用于注册表，
	QString appName = "ChattingRoom"; //HKEY_CURRENT_USER/Software/WWB-Qt/amp6_5

	QSettings   settings(organization, appName);//创建

	bool saved = settings.value("saved", false).toBool();//读取 saved键的值
	m_user = settings.value("Username", "user").toString();//读取 Username 键的值，缺省为“user”

	if (saved)
		ui->idEdit->setText(m_user);
}

void login::writeSettings()
{
	QSettings   settings("Chatting_Roomm-Qt", "ChattingRoom"); //注册表键组
	settings.setValue("Username", m_user); //用户名
}
