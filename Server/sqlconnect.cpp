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

bool SqlConnect::logIn(QString usrid,QString usrname,QString password)
{
    QSqlQuery query;
    QString sqlSelect=QString("select usrid,nickname from loginInfo where (password='%1' and usrid=%2) "
                              "or (nickname='%3' and usrid='%4');").arg(password).arg(usrid).arg(usrname).arg(usrid);
    query.prepare(sqlSelect);
    query.exec();
    while(query.next()){
        if(usrid==query.value(0).toString()||usrname==query.value(1).toString())
            return true;
    }

    return false;
}

bool SqlConnect::signIn(QString usrname,QString password,QString &usrid){
    QSqlQuery query;
    //首先获取表中行数，这样可以按顺序分配id
    int adminId=2020000;
    QString sqlCountRow=QString("select count(*) from loginInfo;");
    if(!query.prepare(sqlCountRow))
    {
        qDebug()<<"计算行数失败";
        return false;
    }
    query.exec();
    query.next();
    adminId+=query.value(0).toInt();
    usrid=QString("%1").arg(adminId);

    //重名的情况
    QSqlQuery selectQuery;
    QString sqlSelect=QString("select nickname from loginInfo where nickname='%1';").arg(usrname);
    selectQuery.prepare(sqlSelect);
    selectQuery.exec();
    selectQuery.next();
    if(selectQuery.value(0).toString()==usrname){
        //重名
        qDebug()<<"重名";
        return false;
    }
    //插入用户的数据
    QString sqlInsert=QString("insert into loginInfo(usrid,nickname,password) values(?,?,?);");
    if(!query.prepare(sqlInsert)){
        qDebug()<<"插入失败";
        return false;//3代表插入失败
    }
    query.addBindValue(usrid);
    query.addBindValue(usrname);
    query.addBindValue(password);
    query.exec();
    qDebug()<<"成功插入";
    return true;
}
