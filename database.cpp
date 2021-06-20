#include "database.h"
#include<QDebug>
#include<QSqlError>
#include<QSqlQuery>
#include<QDateTime>
database::database(QObject *parent) : QObject(parent)
{
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Stu.db");
    if(!db.open())
    {
        qDebug()<<"数据库Stu.db打开失败:"<<db.lastError();
    }
    QSqlQuery query(db);
    //如果没有用户表则创建
    if(!query.exec("create table if not exists user(userID bigint,"
               "username varchar(20) not null,"
               "passwd varchar(20) not null,primary key(userID))"))
    {
        qDebug()<<tr("表user创建失败")<<query.lastError();
    }
    //插入初始的账户名和密码 admin
    if(!query.exec("insert into user (userID,username,passwd) values (0,'admin','admin')"))
    {
        qDebug()<<tr("admin insert false")<<query.lastError();
    }
}


bool database::checkUser(QString username, QString passwd)
{
    QSqlDatabase::database();   //获取当前操作的数据库
    QSqlQuery query;
    query.exec(QString("select *from user where username = '%1'").arg(username));
    if(query.next())
    {
         cout<<query.value("username").toString()<<query.value("passwd").toString()<<endl;
         userName=query.value("username").toString();
         return true;
    }

    return false;
}

bool database::adduser(QString username, QString passwd)
{
    //随机产生一个userID
    QDateTime curTime = QDateTime::currentDateTime();
    QString  id = curTime.toString("yyMMddhhmmss");
    //qDebug()<<id<<id.toULongLong()<< endl;

    QSqlQuery query(db);
    if(!query.exec(QString("insert into user values(%1,%2,%3)").arg(id.toULongLong()).arg(username).arg(passwd)))
    {
        qDebug()<<"注册失败...err"<<query.lastError();
        return false;
    }
    return true;
}

QString database::getUserName()
{
    return userName;
}
//database单例
database *database::getInstance()
{
    if(instance==nullptr)
    {
        instance = new database;
    }
    return instance;
}
//保存一个学生的信息
bool database::saveStudentInfo(const QString &info)
{
    QFile save("student.txt");
    save.open(QIODevice::Append | QIODevice::Text);
    if(!save.isOpen())
    {
        cout <<"student.txt 打开失败"<<endl;
        return false;
    }
    QTextStream out(&save);
    out<<info<<"\n";
    save.close();
    return true;
}
//读取所有学生信息
QStringList *database::readStudentInfo()
{
    QFile read("student.txt");
    if(!read.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cout<<"student.txt 读取时打开失败"<<endl;
        return nullptr;
    }
    QStringList * result =new QStringList;
    QTextStream in(&read);
    while(!in.atEnd())
    {
       QString t = in.readLine();
       t = t.trimmed();             //去除掉开头和末尾的'\t', '\n', '\v', '\f', '\r', and ' '
       result->append(t);
    }

    read.close();
    return result;
}

























