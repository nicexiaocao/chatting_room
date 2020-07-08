/********************************************************************************
** Form generated from reading UI file 'client_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_MAINWINDOW_H
#define UI_CLIENT_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client_MainWindow
{
public:
    QAction *action;
    QAction *actionqingkong;
    QAction *actConnect;
    QAction *actDisconnect;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *editName;
    QLabel *label_onlie;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_1;
    QHBoxLayout *horizontalLayout_3;
    QListView *listView;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *display_message;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *send_text;
    QGroupBox *buttons;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClear;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnSend;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnBeep;
    QMenuBar *menubar;
    QMenu *menu_2;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Client_MainWindow)
    {
        if (Client_MainWindow->objectName().isEmpty())
            Client_MainWindow->setObjectName(QString::fromUtf8("Client_MainWindow"));
        Client_MainWindow->resize(982, 788);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Client_MainWindow->sizePolicy().hasHeightForWidth());
        Client_MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/client_rsc/chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        Client_MainWindow->setWindowIcon(icon);
        Client_MainWindow->setStyleSheet(QString::fromUtf8(""));
        action = new QAction(Client_MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        actionqingkong = new QAction(Client_MainWindow);
        actionqingkong->setObjectName(QString::fromUtf8("actionqingkong"));
        actConnect = new QAction(Client_MainWindow);
        actConnect->setObjectName(QString::fromUtf8("actConnect"));
        actConnect->setCheckable(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/client_rsc/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actConnect->setIcon(icon1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        actConnect->setFont(font);
        actConnect->setAutoRepeat(true);
        actConnect->setVisible(true);
        actDisconnect = new QAction(Client_MainWindow);
        actDisconnect->setObjectName(QString::fromUtf8("actDisconnect"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/client_rsc/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actDisconnect->setIcon(icon2);
        actDisconnect->setFont(font);
        centralwidget = new QWidget(Client_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{border-image:url(:/icon/client_rsc/background.png)}\n"
"QPushButton{border: 2px groove gray;\n"
"border-radius: 5px;background-color:rgb(161, 187, 215);\n"
"}\n"
"*{font: 11pt \"Microsoft YaHei UI\";}\n"
"QGroupBox{border:none}\n"
"#display_message{background-color:rgba(255, 255, 255, 200)}\n"
"#listView{background-color:rgba(255, 255, 255, 200)}"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        editName = new QLineEdit(widget);
        editName->setObjectName(QString::fromUtf8("editName"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editName->sizePolicy().hasHeightForWidth());
        editName->setSizePolicy(sizePolicy1);
        editName->setFont(font1);
        editName->setFocusPolicy(Qt::ClickFocus);
        editName->setReadOnly(true);

        horizontalLayout->addWidget(editName);

        label_onlie = new QLabel(widget);
        label_onlie->setObjectName(QString::fromUtf8("label_onlie"));
        label_onlie->setFont(font1);

        horizontalLayout->addWidget(label_onlie);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMinimumSize(QSize(20, 0));
        lineEdit->setMaximumSize(QSize(60, 16777215));
        lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget);

        widget_1 = new QWidget(centralwidget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        sizePolicy.setHeightForWidth(widget_1->sizePolicy().hasHeightForWidth());
        widget_1->setSizePolicy(sizePolicy);
        widget_1->setMinimumSize(QSize(960, 600));
        horizontalLayout_3 = new QHBoxLayout(widget_1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        listView = new QListView(widget_1);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy3);
        listView->setMinimumSize(QSize(40, 300));
        listView->setFont(font1);
        listView->setContextMenuPolicy(Qt::DefaultContextMenu);
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        horizontalLayout_3->addWidget(listView);

        widget_3 = new QWidget(widget_1);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(7);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        display_message = new QTextEdit(widget_3);
        display_message->setObjectName(QString::fromUtf8("display_message"));
        display_message->setEnabled(true);
        sizePolicy.setHeightForWidth(display_message->sizePolicy().hasHeightForWidth());
        display_message->setSizePolicy(sizePolicy);
        display_message->setMinimumSize(QSize(300, 192));
        display_message->setFont(font1);
        display_message->setFocusPolicy(Qt::TabFocus);
        display_message->setStyleSheet(QString::fromUtf8(""));
        display_message->setFrameShape(QFrame::StyledPanel);
        display_message->setFrameShadow(QFrame::Raised);
        display_message->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_3->addWidget(display_message);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        send_text = new QTextEdit(widget_2);
        send_text->setObjectName(QString::fromUtf8("send_text"));
        send_text->setEnabled(true);
        sizePolicy.setHeightForWidth(send_text->sizePolicy().hasHeightForWidth());
        send_text->setSizePolicy(sizePolicy);
        send_text->setMaximumSize(QSize(16777215, 100));
        send_text->setFont(font1);
        send_text->setFocusPolicy(Qt::TabFocus);
        send_text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout->addWidget(send_text);

        buttons = new QGroupBox(widget_2);
        buttons->setObjectName(QString::fromUtf8("buttons"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(buttons->sizePolicy().hasHeightForWidth());
        buttons->setSizePolicy(sizePolicy4);
        buttons->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(buttons);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnClear = new QPushButton(buttons);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        sizePolicy2.setHeightForWidth(btnClear->sizePolicy().hasHeightForWidth());
        btnClear->setSizePolicy(sizePolicy2);
        btnClear->setMinimumSize(QSize(70, 0));
        btnClear->setFont(font1);

        horizontalLayout_2->addWidget(btnClear);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnSend = new QPushButton(buttons);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        sizePolicy2.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy2);
        btnSend->setMinimumSize(QSize(70, 0));
        btnSend->setFont(font1);

        horizontalLayout_2->addWidget(btnSend);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btnBeep = new QPushButton(buttons);
        btnBeep->setObjectName(QString::fromUtf8("btnBeep"));
        sizePolicy2.setHeightForWidth(btnBeep->sizePolicy().hasHeightForWidth());
        btnBeep->setSizePolicy(sizePolicy2);
        btnBeep->setMinimumSize(QSize(0, 0));
        btnBeep->setMaximumSize(QSize(28, 28));
        btnBeep->setStyleSheet(QString::fromUtf8("border-image:url(:/icon/client_rsc/\351\235\231\351\237\263.png)"));
        btnBeep->setCheckable(true);
        btnBeep->setChecked(true);
        btnBeep->setAutoRepeat(false);
        btnBeep->setAutoExclusive(true);

        horizontalLayout_2->addWidget(btnBeep);


        verticalLayout->addWidget(buttons);


        verticalLayout_3->addWidget(widget_2);


        horizontalLayout_3->addWidget(widget_3);


        verticalLayout_2->addWidget(widget_1);

        Client_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Client_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 982, 26));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Client_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Client_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        sizePolicy1.setHeightForWidth(statusbar->sizePolicy().hasHeightForWidth());
        statusbar->setSizePolicy(sizePolicy1);
        Client_MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(Client_MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setFont(font);
        toolBar->setAllowedAreas(Qt::TopToolBarArea);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        Client_MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu_2->addAction(action);
        menu_2->addAction(actionqingkong);
        toolBar->addAction(actConnect);
        toolBar->addAction(actDisconnect);

        retranslateUi(Client_MainWindow);

        QMetaObject::connectSlotsByName(Client_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *Client_MainWindow)
    {
        Client_MainWindow->setWindowTitle(QCoreApplication::translate("Client_MainWindow", "ChattingRoom", nullptr));
        action->setText(QCoreApplication::translate("Client_MainWindow", "\346\274\253\346\270\270", nullptr));
        actionqingkong->setText(QCoreApplication::translate("Client_MainWindow", "\346\270\205\347\251\272", nullptr));
        actConnect->setText(QCoreApplication::translate("Client_MainWindow", "\350\277\236\346\216\245\345\210\260\346\234\215\345\212\241\345\231\250", nullptr));
#if QT_CONFIG(tooltip)
        actConnect->setToolTip(QCoreApplication::translate("Client_MainWindow", "\350\277\236\346\216\245\345\210\260TCP\346\234\215\345\212\241\345\231\250", nullptr));
#endif // QT_CONFIG(tooltip)
        actDisconnect->setText(QCoreApplication::translate("Client_MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
#if QT_CONFIG(tooltip)
        actDisconnect->setToolTip(QCoreApplication::translate("Client_MainWindow", "\346\226\255\345\274\200TCP\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("Client_MainWindow", "\346\230\265\347\247\260\357\274\232", nullptr));
        editName->setText(QCoreApplication::translate("Client_MainWindow", "xiaoliang", nullptr));
        label_onlie->setText(QCoreApplication::translate("Client_MainWindow", "\345\234\250\347\272\277\344\272\272\346\225\260:", nullptr));
        send_text->setHtml(QCoreApplication::translate("Client_MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p></body></html>", nullptr));
        buttons->setTitle(QString());
        btnClear->setText(QCoreApplication::translate("Client_MainWindow", "\346\270\205\351\231\244", nullptr));
        btnSend->setText(QCoreApplication::translate("Client_MainWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        btnSend->setShortcut(QCoreApplication::translate("Client_MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        btnBeep->setText(QString());
        menu_2->setTitle(QCoreApplication::translate("Client_MainWindow", "\345\216\206\345\217\262\346\266\210\346\201\257", nullptr));
        menu->setTitle(QCoreApplication::translate("Client_MainWindow", "\346\277\200\346\203\205\350\201\212\345\244\251", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Client_MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client_MainWindow: public Ui_Client_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_MAINWINDOW_H
