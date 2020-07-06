#include "client_mainwindow.h"
#include "login.h"
#include <QApplication>

login *dlg; // 给主窗口调用

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	dlg = new login;
	if (dlg->exec() == QDialog::Accepted)
	{
		Client_MainWindow w;
		w.show();
		return a.exec();
	}
	else
		return 0;


}