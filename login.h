#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
/**登录和注册**/
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    //登录页面注册按钮
    void on_registerbtn_clicked();
    //登录按钮
    void on_loginbtn_clicked();
    //返回登录页面按钮
    void on_backLogin_clicked();
    //注册页面注册按钮
    void on_reg_btn_clicked();
signals:
    //登录成功信号
    void loginSucceed();
private:
    Ui::login *ui;
};

#endif // LOGIN_H
