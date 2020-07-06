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
#include <QtWidgets/QComboBox>
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
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *ip_label;
    QComboBox *ip_box;
    QLabel *ip_label_2;
    QComboBox *Spinport;
    QLabel *label;
    QLineEdit *editName;
    QLabel *label_onlie;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
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
    QMenuBar *menubar;
    QMenu *menu_2;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Client_MainWindow)
    {
        if (Client_MainWindow->objectName().isEmpty())
            Client_MainWindow->setObjectName(QString::fromUtf8("Client_MainWindow"));
        Client_MainWindow->resize(1178, 773);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Client_MainWindow->sizePolicy().hasHeightForWidth());
        Client_MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/client_rsc/chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        Client_MainWindow->setWindowIcon(icon);
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
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ip_label = new QLabel(groupBox);
        ip_label->setObjectName(QString::fromUtf8("ip_label"));
        ip_label->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ip_label->sizePolicy().hasHeightForWidth());
        ip_label->setSizePolicy(sizePolicy1);
        ip_label->setMinimumSize(QSize(115, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        ip_label->setFont(font1);
        ip_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ip_label->setWordWrap(true);

        horizontalLayout->addWidget(ip_label);

        ip_box = new QComboBox(groupBox);
        ip_box->addItem(QString());
        ip_box->addItem(QString());
        ip_box->setObjectName(QString::fromUtf8("ip_box"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ip_box->sizePolicy().hasHeightForWidth());
        ip_box->setSizePolicy(sizePolicy2);
        ip_box->setFont(font1);
        ip_box->setFocusPolicy(Qt::ClickFocus);
        ip_box->setEditable(true);

        horizontalLayout->addWidget(ip_box);

        ip_label_2 = new QLabel(groupBox);
        ip_label_2->setObjectName(QString::fromUtf8("ip_label_2"));
        ip_label_2->setFont(font1);
        ip_label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(ip_label_2);

        Spinport = new QComboBox(groupBox);
        Spinport->addItem(QString());
        Spinport->addItem(QString());
        Spinport->setObjectName(QString::fromUtf8("Spinport"));
        Spinport->setFont(font1);
        Spinport->setFocusPolicy(Qt::ClickFocus);
        Spinport->setEditable(true);

        horizontalLayout->addWidget(Spinport);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        editName = new QLineEdit(groupBox);
        editName->setObjectName(QString::fromUtf8("editName"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(editName->sizePolicy().hasHeightForWidth());
        editName->setSizePolicy(sizePolicy3);
        editName->setFont(font1);
        editName->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(editName);

        label_onlie = new QLabel(groupBox);
        label_onlie->setObjectName(QString::fromUtf8("label_onlie"));
        label_onlie->setFont(font1);

        horizontalLayout->addWidget(label_onlie);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(groupBox);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy4);
        widget->setMinimumSize(QSize(960, 600));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        listView = new QListView(widget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy5);
        listView->setMinimumSize(QSize(40, 300));
        QFont font2;
        font2.setPointSize(10);
        listView->setFont(font2);
        listView->setContextMenuPolicy(Qt::DefaultContextMenu);
        listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        horizontalLayout_3->addWidget(listView);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(7);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        display_message = new QTextEdit(widget_3);
        display_message->setObjectName(QString::fromUtf8("display_message"));
        display_message->setEnabled(true);
        sizePolicy4.setHeightForWidth(display_message->sizePolicy().hasHeightForWidth());
        display_message->setSizePolicy(sizePolicy4);
        display_message->setMinimumSize(QSize(300, 192));
        QFont font3;
        font3.setPointSize(11);
        display_message->setFont(font3);
        display_message->setFocusPolicy(Qt::TabFocus);
        display_message->setFrameShape(QFrame::StyledPanel);
        display_message->setFrameShadow(QFrame::Raised);
        display_message->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout_3->addWidget(display_message);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy3.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy3);
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        send_text = new QTextEdit(widget_2);
        send_text->setObjectName(QString::fromUtf8("send_text"));
        send_text->setEnabled(true);
        sizePolicy4.setHeightForWidth(send_text->sizePolicy().hasHeightForWidth());
        send_text->setSizePolicy(sizePolicy4);
        send_text->setMaximumSize(QSize(16777215, 100));
        send_text->setFont(font3);
        send_text->setFocusPolicy(Qt::TabFocus);
        send_text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout->addWidget(send_text);

        buttons = new QGroupBox(widget_2);
        buttons->setObjectName(QString::fromUtf8("buttons"));
        QSizePolicy sizePolicy6(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(buttons->sizePolicy().hasHeightForWidth());
        buttons->setSizePolicy(sizePolicy6);
        horizontalLayout_2 = new QHBoxLayout(buttons);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnClear = new QPushButton(buttons);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        sizePolicy.setHeightForWidth(btnClear->sizePolicy().hasHeightForWidth());
        btnClear->setSizePolicy(sizePolicy);
        btnClear->setFont(font2);

        horizontalLayout_2->addWidget(btnClear);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnSend = new QPushButton(buttons);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        sizePolicy.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy);
        btnSend->setFont(font2);

        horizontalLayout_2->addWidget(btnSend);


        verticalLayout->addWidget(buttons);


        verticalLayout_3->addWidget(widget_2);


        horizontalLayout_3->addWidget(widget_3);


        verticalLayout_2->addWidget(widget);

        Client_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Client_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1178, 26));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Client_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Client_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        sizePolicy3.setHeightForWidth(statusbar->sizePolicy().hasHeightForWidth());
        statusbar->setSizePolicy(sizePolicy3);
        Client_MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(Client_MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setFont(font);
        toolBar->setAllowedAreas(Qt::TopToolBarArea);
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
        groupBox->setTitle(QString());
        ip_label->setText(QCoreApplication::translate("Client_MainWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        ip_box->setItemText(0, QCoreApplication::translate("Client_MainWindow", "118.89.192.223", nullptr));
        ip_box->setItemText(1, QCoreApplication::translate("Client_MainWindow", "192.168.1.1", nullptr));

        ip_label_2->setText(QCoreApplication::translate("Client_MainWindow", "\347\253\257\345\217\243\357\274\232", nullptr));
        Spinport->setItemText(0, QCoreApplication::translate("Client_MainWindow", "8001", nullptr));
        Spinport->setItemText(1, QCoreApplication::translate("Client_MainWindow", "3306", nullptr));

        label->setText(QCoreApplication::translate("Client_MainWindow", "\346\230\265\347\247\260\357\274\232", nullptr));
        editName->setText(QCoreApplication::translate("Client_MainWindow", "xiaocao", nullptr));
        label_onlie->setText(QCoreApplication::translate("Client_MainWindow", "\345\234\250\347\272\277\344\272\272\346\225\260:", nullptr));
        send_text->setHtml(QCoreApplication::translate("Client_MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        buttons->setTitle(QString());
        btnClear->setText(QCoreApplication::translate("Client_MainWindow", "\346\270\205\351\231\244", nullptr));
        btnSend->setText(QCoreApplication::translate("Client_MainWindow", "\345\217\221\351\200\201", nullptr));
#if QT_CONFIG(shortcut)
        btnSend->setShortcut(QCoreApplication::translate("Client_MainWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
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
