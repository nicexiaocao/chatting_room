/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *userLabel;
    QLineEdit *idEdit;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passLabel;
    QLineEdit *passEdit;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *BtnLogin;
    QSpacerItem *horizontalSpacer;
    QPushButton *BtnRegister;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *BtnCancel;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(933, 491);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/client_rsc/login_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        login->setWindowIcon(icon);
        login->setStyleSheet(QString::fromUtf8("#login{border-image:url(:/icon/client_rsc/login.png)}\n"
"*{font: 12pt \"Microsoft YaHei UI\";}\n"
"QPushButton{border: 2px groove gray;\n"
"border-radius: 5px;background-color:rgb(161, 187, 215)}\n"
"QGroupBox{border:none}\n"
""));
        horizontalLayout_3 = new QHBoxLayout(login);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widget = new QWidget(login);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(300, 48));
        groupBox->setFlat(false);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        userLabel = new QLabel(groupBox);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        horizontalLayout->addWidget(userLabel);

        idEdit = new QLineEdit(groupBox);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        horizontalLayout->addWidget(idEdit);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(300, 48));
        groupBox_2->setFlat(false);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        passLabel = new QLabel(groupBox_2);
        passLabel->setObjectName(QString::fromUtf8("passLabel"));

        horizontalLayout_2->addWidget(passLabel);

        passEdit = new QLineEdit(groupBox_2);
        passEdit->setObjectName(QString::fromUtf8("passEdit"));

        horizontalLayout_2->addWidget(passEdit);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        BtnLogin = new QPushButton(groupBox_4);
        BtnLogin->setObjectName(QString::fromUtf8("BtnLogin"));
        sizePolicy.setHeightForWidth(BtnLogin->sizePolicy().hasHeightForWidth());
        BtnLogin->setSizePolicy(sizePolicy);
        BtnLogin->setMinimumSize(QSize(80, 35));

        horizontalLayout_4->addWidget(BtnLogin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        BtnRegister = new QPushButton(groupBox_4);
        BtnRegister->setObjectName(QString::fromUtf8("BtnRegister"));
        sizePolicy.setHeightForWidth(BtnRegister->sizePolicy().hasHeightForWidth());
        BtnRegister->setSizePolicy(sizePolicy);
        BtnRegister->setMinimumSize(QSize(80, 35));

        horizontalLayout_4->addWidget(BtnRegister);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        BtnCancel = new QPushButton(groupBox_4);
        BtnCancel->setObjectName(QString::fromUtf8("BtnCancel"));
        sizePolicy.setHeightForWidth(BtnCancel->sizePolicy().hasHeightForWidth());
        BtnCancel->setSizePolicy(sizePolicy);
        BtnCancel->setMinimumSize(QSize(80, 35));

        horizontalLayout_4->addWidget(BtnCancel);


        gridLayout->addWidget(groupBox_4, 1, 0, 1, 2);


        horizontalLayout_3->addWidget(widget);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "ChattingRoom", nullptr));
        groupBox->setTitle(QString());
        userLabel->setText(QCoreApplication::translate("login", "\347\224\250\346\210\267\345\220\215:", nullptr));
        groupBox_2->setTitle(QString());
        passLabel->setText(QCoreApplication::translate("login", "\345\257\206\347\240\201:", nullptr));
        groupBox_4->setTitle(QString());
        BtnLogin->setText(QCoreApplication::translate("login", "\347\231\273\351\231\206", nullptr));
        BtnRegister->setText(QCoreApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        BtnCancel->setText(QCoreApplication::translate("login", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
