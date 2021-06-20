#include "controller.h"

controller::controller(QObject *parent) : QObject(parent)
{
    registerSngnalsAndSlots();
}

void controller::registerSngnalsAndSlots()
{
    connect(&userLogin,&login::loginSucceed,this,[=]()
    {
        menu = new MainMenu;
        menu->show();
        userLogin.hide();
    });
}

void controller::show()
{
    userLogin.show();
}
