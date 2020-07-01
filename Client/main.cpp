#include "client_mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client_MainWindow w;
    w.show();
    return a.exec();
	//神奇的github,有点厉害
}
