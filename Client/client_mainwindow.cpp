#include "client_mainwindow.h"
#include "ui_client_mainwindow.h"
#include "qdebug.h"
#include <QTextBlock>

extern login* dlg;
Client_MainWindow::Client_MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Client_MainWindow)
{

	ui->setupUi(this);

	//窗口之间传递
	connect(dlg, &login::sendData, this, &Client_MainWindow::receiveData);

	//登录窗口槽函数解绑
	disconnect(dlg->tcpClient, &QTcpSocket::readyRead, dlg, &login::onSocketReadyRead);

	
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon); //设置工具栏显示文字和图标
	
	id = dlg->get_id();
	password = dlg->get_password();

	//password = "123456";
	//id = "xiaocao";
	ui->editName->setText(id);
	
	ui->send_text->setFocusPolicy(Qt::ClickFocus); //使能按键响应
	ui->send_text->setFocus();
	ui->send_text->installEventFilter(this);

	//设置提示音
	QString path = QDir::currentPath() + "/sound1.wav";
	noticeSound = new QSound (path.toUtf8());

	tcpClient = dlg->tcpClient;

	//tcpClient = new QTcpSocket(this); //创建socket变量
	//tcpClient->connectToHost(serverIp, serverPort);

	ui->actConnect->setEnabled(false); //进入时已经连接成功，设为不能触发

	LabSocketState = new QLabel("Socket状态：");//状态栏标签
	LabSocketState->setMinimumWidth(250);
	LabSocketState->setText("scoket状态：ConnectedState"); //进入时已经成功
	ui->statusbar->addWidget(LabSocketState);



	//按钮信号和槽绑定, 会自动识别，不注释的话需要声明qt::uniqueconnection，否则会触发两次槽函数
	//connect(ui->actConnect, &QAction::triggered, this, &Client_MainWindow::on_actConnect_triggered);
	//connect(ui->actDisconnect, &QAction::triggered, this, &Client_MainWindow::on_actDisconnect_triggered);
	//connect(ui->btnSend, &QAbstractButton::clicked, this, &Client_MainWindow::on_btnSend_clicked);
	//connect(ui->btnClear, &QAbstractButton::clicked, this, &Client_MainWindow::on_btnClear_clicked);
	//connect(ui->btnBeep, &QAbstractButton::clicked, this, &Client_MainWindow::on_btnBeep_clicked);

	//TCP连接状态
	connect(tcpClient, &QTcpSocket::connected, this, &Client_MainWindow::onConnected);
	connect(tcpClient, &QTcpSocket::disconnected, this, &Client_MainWindow::onDisconnected);
	connect(tcpClient, &QTcpSocket::stateChanged, this, &Client_MainWindow::onSocketStateChange);
	connect(tcpClient, &QTcpSocket::readyRead, this, &Client_MainWindow::onSocketReadyRead);

	//显示界面设置
	connect(ui->display_message, &QTextEdit::textChanged, this, &Client_MainWindow::movetoEnd);
	
}


Client_MainWindow::~Client_MainWindow()
{
	tcpClient->write(SEND + id.toUtf8() + ":left");
	tcpClient->disconnectFromHost();
	delete ui;
}

void Client_MainWindow::onConnected()
{
	//connected()信号槽函数
	QString id = ui->editName->text();
	ui->display_message->setAlignment(Qt::AlignCenter);
	printMessage(id + "成功连接服务器");
	ui->actConnect->setEnabled(false);
	ui->actDisconnect->setEnabled(true);
}

void Client_MainWindow::onDisconnected()
{
	//disConnected()信号槽函数
	QString id = ui->editName->text();
	printMessage(id + "断开与服务器的连接");
	ui->display_message->setAlignment(Qt::AlignCenter);
	ui->actConnect->setEnabled(true);
	ui->actDisconnect->setEnabled(false);
}

void Client_MainWindow::onSocketReadyRead()
{
	// readyRead()信号槽函数 读取服务器信息
	QString id = ui->editName->text();
	QString Message_received;
	QStringList Message_list;
	while (tcpClient->bytesAvailable())
	{
		Message_received = tcpClient->readAll();
		Message_list = Message_received.split(":");

		//qDebug() << Message_received;
		qDebug() << Message_list;

		if (Message_list[0] == id)
		{
			ui->display_message->setAlignment(Qt::AlignRight);
			printMessage(Message_list[1]);
		}
		else
		{
			ui->display_message->setAlignment(Qt::AlignLeft);
			printMessage(Message_received);
			if (beep)
			{
				noticeSound->play();
			}
		}
	}
}

void Client_MainWindow::on_actConnect_triggered()
{
	//连接到服务器
	QString id = ui->editName->text();
	tcpClient->connectToHost(serverIp, serverPort);
	QString LogMessage = LOG + id + ":" + password;
	qDebug() << "主窗口:" + LogMessage;
	tcpClient->write(LogMessage.toUtf8());
}

void Client_MainWindow::on_actDisconnect_triggered()
{
	//断开连接
	QString id = ui->editName->text();
	if (tcpClient->state() == QAbstractSocket::ConnectedState)
	{
		tcpClient->write(SEND + id.toUtf8() + ":left"); // 直接发送用户名字作为下线指令
		tcpClient->disconnectFromHost();
	}
		
}

void Client_MainWindow::on_btnSend_clicked()
{
	//发送数据

	QTextBlock textBlock;
	QString id = ui->editName->text();
	QTextDocument *doc = ui->send_text->document(); // 文本对象
	int cnt = doc->blockCount(); // 回车符是一个block

	QString message_send = "";
	for (int i = 0; i < cnt; i++)
	{
		//服务器发消息
		QTextBlock textline = doc->findBlockByNumber(i);
		if (textline.text() != "")
			message_send = message_send.append(textline.text()+ "\n");
	}
	if (message_send != "")
	{
		tcpClient->write(SEND + id.toUtf8() + ":" + message_send.toUtf8());
	}
	
	ui->send_text->clear();
	ui->send_text->setFocus();
}

void Client_MainWindow::on_btnClear_clicked()
{
	//清空对话框
	ui->display_message->clear();
}

void Client_MainWindow::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
	//连接状态
	switch (socketState)
	{
	case QAbstractSocket::UnconnectedState:
		LabSocketState->setText("scoket状态：UnconnectedState");
		break;
	case QAbstractSocket::HostLookupState:
		LabSocketState->setText("scoket状态：HostLookupState");
		break;
	case QAbstractSocket::ConnectingState:
		LabSocketState->setText("scoket状态：ConnectingState");
		break;

	case QAbstractSocket::ConnectedState:
		LabSocketState->setText("scoket状态：ConnectedState");
		break;

	case QAbstractSocket::BoundState:
		LabSocketState->setText("scoket状态：BoundState");
		break;

	case QAbstractSocket::ClosingState:
		LabSocketState->setText("scoket状态：ClosingState");
		break;

	case QAbstractSocket::ListeningState:
		LabSocketState->setText("scoket状态：ListeningState");
	}
}

void Client_MainWindow::movetoEnd()
{
	//光标移动到最后
	ui->display_message->moveCursor(QTextCursor::End);
}

void Client_MainWindow::receiveData(QString data, QString data2)
{
	ui->editName->setText(data);
	this->password = data2;
}

void Client_MainWindow::on_btnBeep_clicked()
{
	beep = !beep;

}


bool Client_MainWindow::eventFilter(QObject *target, QEvent *event)
{
	if (target == ui->send_text)
	{
		if (event->type() == QEvent::KeyPress)//按键事件
		{
			QKeyEvent *k = static_cast<QKeyEvent *>(event);
			if ((k->modifiers() == Qt::ControlModifier) && (k->key() == Qt::Key_Return))
			{
				ui->send_text->append("");
				return true; //事件处理完毕
			}
			else if (k->key() == Qt::Key_Return)
			{
				this->on_btnSend_clicked();
				return true;
			}
			else
				return QMainWindow::eventFilter(target, event); //其他按键默认处理
		}
		
	}

	return QMainWindow::eventFilter(target, event);  //其他目标默认处理
}
void Client_MainWindow::printMessage(QString message)
{
	ui->display_message->append(message);
}