#include "login.h"
#include "ui_login.h"
#include<QDebug>
#include"database.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_registerbtn_clicked()
{
    //点击注册按钮，来到注册界面
    ui->loginWidget->setCurrentIndex(1);
}

void login::on_loginbtn_clicked()
{
    //点击登录按钮，查看用户名和密码是否在数据库中存在
    bool isok = database::getInstance()->checkUser(ui->userName->text(),ui->passwd->text());
    if(!isok)
    {
        cout<<"登录失败";
        return;
    }
    cout<<"登录成功";
    emit loginSucceed();    //发送登录成功信号
}

void login::on_backLogin_clicked()
{
    //在注册页面，按下返回登录按钮，返回登录界面
    ui->loginWidget->setCurrentIndex(0);
}

void login::on_reg_btn_clicked()
{  
    //注册账号，往数据库中添加账户名和密码
    if(ui->reg_passwd->text() == ui->reg_affirmpasswd->text())
    {
        database::getInstance()->adduser(ui->reg_userName->text(),ui->reg_passwd->text());
        qDebug()<<"注册成功";
    }
}
