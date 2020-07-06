#ifndef SQLCONNECT_H
#define SQLCONNECT_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include <QDebug>
#include<QtSql>
class SqlConnect:public QObject
{
    Q_OBJECT
public:
    explicit SqlConnect(QObject *parent=nullptr);
    bool startConnect();
    bool signIn(QString usrname,QString password,QString &usrid);
    bool logIn(QString usrid,QString usrname,QString password);

};

#endif // SQLCONNECT_H
