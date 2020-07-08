#include "login.h"
#include "ui_login.h"



login::login(QWidget *parent): QDialog(parent), ui(new Ui::login)
{
	
	ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	ui->passEdit->setEchoMode(QLineEdit::Password);

	tcpClient = new QTcpSocket; // 建立一个socket连接，在login类中生效
	tcpClient->connectToHost(serverIp, serverPort);
	
	readSettings(); //读取存储的用户名

	//连接信号和槽

	connect(tcpClient, &QTcpSocket::readyRead, this, &login::onSocketReadyRead);

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
	tcpClient->connectToHost(ip, port);
	QString id = ui->idEdit->text();
	QString password = ui->passEdit->text();
	if (id == "" || password == "")
	{
		QMessageBox::critical(this, "错误","用户名或密码为空",
			QMessageBox::Ok, QMessageBox::NoButton);
	}
	else
	{
		QString LogMessage = LOG + id + ":" + password;
		tcpClient->write(LogMessage.toUtf8());
	}
	
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
	this->setAttribute(Qt::WA_DeleteOnClose); //关闭时删除
	this->close(); // 关闭对话框
}

void login::onSocketReadyRead()
{	
	//消息处理，主要功能实现函数
	QString Message_received;
	qDebug() << "登录窗口" << tcpClient->bytesAvailable();
	
	while (tcpClient->bytesAvailable())
	{
		Message_received = tcpClient->readAll();
		qDebug() << Message_received;
		QStringList  Message_list = Message_received.split(":");
		QString flag = Message_list[0];
		// qDebug() << Message_received;//打印消息
		if (flag == SAMENAMEERROR)
		{
			//注册重名处理
			QString	diag_title = "错误";
			QString	info = Message_list[1];
			QMessageBox::critical(this, diag_title, info,
				QMessageBox::Ok, QMessageBox::NoButton); // 弹出警报窗口
		}
		else if (flag == CONNECTDATABASEFAIL)
		{
			//数据库连接错误警报
			QString	diag_title = "错误";
			QString	info = Message_list[1];
			QMessageBox::critical(this, diag_title, info,
				QMessageBox::Ok, QMessageBox::NoButton); // 弹出警报窗口
		}
		else if (flag == LOGINFAIL)
		{
			//登录失败处理
			QString	diag_title = "错误";
			QString	info = Message_list[1];
			QMessageBox::critical(this, diag_title, info,
				QMessageBox::Ok, QMessageBox::NoButton); // 弹出警报窗口
		}
		else if (flag == SUCCEEDSIGNIN)
		{
			//注册成功
			QString	diag_title = "消息";
			QString	info = "注册成功，请登陆";
			QMessageBox::information(this, diag_title, info,
				QMessageBox::Ok, QMessageBox::NoButton); // 弹出警报窗口
		}
		else if (flag == SUCCEEDLOGIN)
		{
			//登录成功，写注册表，跳转主窗口
			this->m_user = ui->idEdit->text();
			this->writeSettings();
			password = ui->passEdit->text();
			emit sendData(m_user, password);
			this->accept();
		}
	}
	

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
bool login::eventFilter(QObject *target, QEvent *event)
{
	if (target == this)
	{
		if (event->type() == QEvent::KeyPress)//按键事件
		{
			QKeyEvent *k = static_cast<QKeyEvent *>(event);
			if (k->key() == Qt::Key_Return)
			{
				this->on_btnEnter_clicked();  
				return true;
			}
			else
				return QDialog::eventFilter(target, event); //其他按键默认处理
		}

	}

	return QDialog::eventFilter(target, event);  //其他目标默认处理
}

void login::readSettings()
{
	//读取存储的用户名和密码, 密码是经过加密的
	QString organization = "Chatting_Roomm-Qt";//用于注册表，
	QString appName = "ChattingRoom"; //HKEY_CURRENT_USER/Software/Chatting_Roomm-Qt/ChattingRoom

	QSettings   settings(organization, appName);//创建

	m_user = settings.value("Username", "user").toString();//读取 Username 键的值，缺省为“user”
	ui->idEdit->setText(m_user);
}

void login::writeSettings()
{
	QSettings   settings("Chatting_Roomm-Qt", "ChattingRoom"); //注册表键组
	settings.setValue("Username", m_user); //用户名
}

