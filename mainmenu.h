#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include"addstudent.h"
#include"displaystudent.h"

namespace Ui {
class MainMenu;
}
/**登录之后的界面***/
class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    //右上角退出按钮
    void on_quit_btn_clicked();
    //添加学生按钮
    void on_btn_addStu_clicked();

    //显示学生按钮
    void on_btn_display_clicked();
    //查询学生按钮
    void on_btn_query_clicked();

private:
    Ui::MainMenu *ui;

    AddStudent *addStudent; //添加学生窗口
    DisplayStudent *displayStu; //显示学生窗口
};

#endif // MAINMENU_H
