#include "controller.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controller c;
    c.show();
    return a.exec();
}
