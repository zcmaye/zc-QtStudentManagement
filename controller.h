#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include"login.h"
#include "mainmenu.h"
/**主要控制类**/
class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(QObject *parent = nullptr);
    //对用户登录进行处理
    void registerSngnalsAndSlots();
    void show();
signals:
private:
    login userLogin;
    MainMenu *menu;
};

#endif // CONTROLLER_H
