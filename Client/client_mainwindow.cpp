#include "client_mainwindow.h"
#include "ui_client_mainwindow.h"
#include "qdebug.h"
#include <QTextBlock>


Client_MainWindow::Client_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client_MainWindow)
{
	
	ui->setupUi(this);

    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon); //设置工具栏显示文字和图标

	//设置背景颜色
	QPalette palette;
	QPixmap pixmap(":/icon/client_rsc/background.png");
	palette.setBrush(QPalette::Window, QBrush(pixmap));
	this->setPalette(palette);

	connectedToHost = false;  // 初始化连接状态

	tcpClient = new QTcpSocket(this); //创建socket变量

	LabSocketState = new QLabel("Socket状态：");//状态栏标签
	LabSocketState->setMinimumWidth(250);
	ui->statusbar->addWidget(LabSocketState);

	// 建立信号和槽之间的联系
	connect(tcpClient, &QTcpSocket::connected, this, &Client_MainWindow::onConnected);
	connect(tcpClient, &QTcpSocket::disconnected, this, &Client_MainWindow::onDisconnected);

	connect(tcpClient, &QTcpSocket::stateChanged,this, &Client_MainWindow::onSocketStateChange);
	connect(tcpClient, &QTcpSocket::readyRead, this, &Client_MainWindow::onSocketReadyRead);

	connect(ui->actConnect, &QAction::triggered, this, &Client_MainWindow::on_actConnect_triggered);
	connect(ui->actDisconnect, &QAction::triggered, this, &Client_MainWindow::on_actDisconnect_triggered);

	connect(ui->btnSend, &QAbstractButton::clicked, this, &Client_MainWindow::on_btnSend_clicked);
	connect(ui->btnClear, &QAbstractButton::clicked, this, &Client_MainWindow::on_btnClear_clicked);

}


Client_MainWindow::~Client_MainWindow()
{
    delete ui;
}

void Client_MainWindow::onConnected()
{
	//connected()信号槽函数
	QString id = ui->editName->text();
	printMessage(id + "成功连接服务器");
	ui->display_message->setAlignment(Qt::AlignCenter);
	ui->actConnect->setEnabled(false);
	ui->actDisconnect->setEnabled(true);

	//发送到服务器信息
	tcpClient->write(id.toUtf8() + " has joined the chat room." + "\n");
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
	while (tcpClient->canReadLine())
	{
		printMessage(tcpClient->readAll());
		ui->display_message->setAlignment(Qt::AlignLeft);
	}
}

void Client_MainWindow::on_actConnect_triggered()
{
	//连接到服务器
	QString     addr = ui->ip_box->currentText();
	QString     str = ui->Spinport->currentText();
	qint16		port = str.toInt();
	tcpClient->connectToHost(addr, port);
}

void Client_MainWindow::on_actDisconnect_triggered()
{
	//断开连接
	if (tcpClient->state() == QAbstractSocket::ConnectedState)
		tcpClient->disconnectFromHost();
}

void Client_MainWindow::on_btnSend_clicked()
{
	//发送数据

	QTextBlock textBlock;
	QString id = ui->editName->text();
	QTextDocument *doc = ui->send_text->document(); // 文本对象
	int cnt = doc->blockCount(); // 回车符是一个block
	
	//for (int i = 0; i < cnt; i++)
	//{
	//	//显示自己发送的数据
	//	QTextBlock textline = doc->findBlockByNumber(i);
	//	QString message = textline.text();
	//	if (i == 0)
	//		printMessage(message.toUtf8() + "[" + id + "]");
	//	else
	//		printMessage(message.toUtf8());
	//	ui->display_message->setAlignment(Qt::AlignRight); // 设置右对齐
	//}

	for (int i = 0; i < cnt; i++)
	{
		//服务器发消息
		QTextBlock textline = doc->findBlockByNumber(i);
		QString message_send = textline.text();
		tcpClient->write("[" + id.toUtf8() + "]" + message_send.toUtf8() + "\n");
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

void Client_MainWindow::printMessage(QString message)
{
	ui->display_message->append(message);
}