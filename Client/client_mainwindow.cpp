#include "client_mainwindow.h"
#include "ui_client_mainwindow.h"
#include "qdebug.h"
#include <QTextBlock>

extern login* dlg;

Client_MainWindow::Client_MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Client_MainWindow)
{
	ui->setupUi(this);

    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon); //设置工具栏显示文字和图标

	connectedToHost = false;  // 初始化连接状态
	ui->actConnect->setEnabled(false); //进入时已经连接成功

	
	ui->send_text->setFocusPolicy(Qt::ClickFocus); //使能按键响应
	ui->send_text->setFocus();
	ui->send_text->installEventFilter(this);

	dlg->tcpClient->disconnectFromHost(); //断开登录窗口的连接
	tcpClient = new QTcpSocket(this); //创建socket变量
	tcpClient->connectToHost(serverIp, serverPort);
	
	LabSocketState = new QLabel("Socket状态：");//状态栏标签
	LabSocketState->setMinimumWidth(250);
	ui->statusbar->addWidget(LabSocketState);


	// 建立信号和槽之间的联系，省略好像不起效果，难顶
	connect(tcpClient, &QTcpSocket::connected, this, &Client_MainWindow::onConnected);
	connect(tcpClient, &QTcpSocket::disconnected, this, &Client_MainWindow::onDisconnected);

	connect(tcpClient, &QTcpSocket::stateChanged,this, &Client_MainWindow::onSocketStateChange);
	connect(tcpClient, &QTcpSocket::readyRead, this, &Client_MainWindow::onSocketReadyRead);

	connect(ui->actConnect, &QAction::triggered, this, &Client_MainWindow::on_actConnect_triggered);
	connect(ui->actDisconnect, &QAction::triggered, this, &Client_MainWindow::on_actDisconnect_triggered);

	connect(ui->btnSend, &QAbstractButton::clicked, this, &Client_MainWindow::on_btnSend_clicked);
	connect(ui->btnClear, &QAbstractButton::clicked, this, &Client_MainWindow::on_btnClear_clicked);

	connect(ui->display_message, &QTextEdit::textChanged, this, &Client_MainWindow::movetoEnd);
	connect(dlg, &login::sendData, this, &Client_MainWindow::receiveData);
}


Client_MainWindow::~Client_MainWindow()
{
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
	QString Message_received = tcpClient->readAll();
	QStringList Message_list; 

	while (tcpClient->bytesAvailable())
	{
		Message_received = tcpClient->readAll();
		qDebug() << Message_received;
		Message_list = Message_received.split(":");
		qDebug() << Message_list[0];
		
		if (Message_list[0] == id)
		{
			ui->display_message->setAlignment(Qt::AlignRight);
			printMessage(Message_list[1]);
		}
		else
		{
			ui->display_message->setAlignment(Qt::AlignLeft);
			printMessage(Message_received);
		}
	}
}

void Client_MainWindow::on_actConnect_triggered()
{
	//连接到服务器
	QString id = ui->editName->text();
	tcpClient->connectToHost(serverIp, serverPort);
	QString LogMessage = LOG + id + ":" + password;
	tcpClient->write(LogMessage.toUtf8());
}

void Client_MainWindow::on_actDisconnect_triggered()
{
	//断开连接
	QString id = ui->editName->text();
	if (tcpClient->state() == QAbstractSocket::ConnectedState)
	{
		tcpClient->write(id.toUtf8()); // 直接发送用户名字作为下线指令
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


	for (int i = 0; i < cnt; i++)
	{
		//服务器发消息
		QTextBlock textline = doc->findBlockByNumber(i);
		QString message_send = textline.text();
		if (message_send != "")
			tcpClient->write(SEND + id.toUtf8() + ":" + message_send.toUtf8() + "\n");
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
	qDebug() << password;
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