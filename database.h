#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include<QSqlDatabase>
#include<QDebug>

#include<QFile>
#include<QTextStream>
#include<QIODevice>
#include<QStringList>

#define cout qDebug()<<"[file:"<<__FILE__<<" line:"<<__LINE__<<"]"
/**数据库接口**/
class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = nullptr);
    bool  checkUser(QString username,QString passwd);      //检查用户输入的账号密码是否正确
    bool  adduser(QString username,QString passwd);         //往数据库中添加注册的账号和密码
    QString getUserName();
    static  database* getInstance();                       //获取单例

public: //文件操作
    bool saveStudentInfo(const QString& info);      //保存指定的学生星系
    QStringList* readStudentInfo();                 //读取所有学生信息

signals:
private:
    QSqlDatabase db;
    inline static database *instance=nullptr;
    QString userName;
};

#endif // DATABASE_H
