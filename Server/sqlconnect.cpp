#include"sqlconnect.h"
SqlConnect::SqlConnect(QObject *parent):QObject(parent)
{

}

void showError(const QSqlError &err)
{
      qDebug()<< "Unable to initialize DatabaseError initializing database: " + err.text();
}

bool SqlConnect::startConnect(){
    if (!QSqlDatabase::drivers().contains("QSQLITE"))
        qDebug()<<this, "Unable to load database", "This demo needs the SQLITE driver";
    else
        qDebug()<<"success load driver";

    //initialize the database
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("usrinfo.db");       //这里输入数据库名
    if (!db.open()){
        qDebug()<<"不能打开";
        return false;
    }


    return true;
}

bool SqlConnect::logIn(QString usrname,QString password)
{
    QSqlQuery query;
    QString sqlSelect=QString("select usrname from loginInfo where password='%1' and usrname='%2';").arg(password).arg(usrname);
    query.prepare(sqlSelect);
    query.exec();
    while(query.next()){
        if(usrname==query.value(0).toString()){
            return true;
        }
    }
    return false;
}

bool SqlConnect::signIn(QString usrname,QString password){
    //首先查重名
    QSqlQuery selectQuery;
    QString sqlSelect=QString("select usrname from loginInfo where usrname='%1';").arg(usrname);
    selectQuery.prepare(sqlSelect);
    selectQuery.exec();
    selectQuery.next();
    if(selectQuery.value(0).toString()==usrname){
        //重名
        qDebug()<<"重名";
        return false;
    }


    QSqlQuery query;

    //插入用户的数据
    QString sqlInsert=QString("insert into loginInfo(usrname,password) values(?,?);");
    if(!query.prepare(sqlInsert)){
        qDebug()<<"插入失败";
        return false;
    }
    query.addBindValue(usrname);
    query.addBindValue(password);
    query.exec();
    qDebug()<<"成功插入";
    return true;
}
