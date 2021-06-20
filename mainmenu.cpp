#include "mainmenu.h"
#include "ui_mainmenu.h"
#include"database.h"
#include<QDebug>
#include<QApplication>
#include<QAction>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);


    ui->uname_label->setText(database::getInstance()->getUserName());

    ui->page->setToolTip("功能选择");


     addStudent = new AddStudent(ui->tab);
     addStudent->hide();
     displayStu = new DisplayStudent(ui->tab);
     displayStu->hide();
}


MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_quit_btn_clicked()
{
    QApplication::quit();
}


//添加学生
void MainMenu::on_btn_addStu_clicked()
{
    displayStu->hide();
    addStudent ->show();
    addStudent->raise();
}
//显示所有学生信息
void MainMenu::on_btn_display_clicked()
{
    addStudent->hide();
    displayStu->show();
    displayStu->raise();
    displayStu->displayAll();
}
//查询学生信息
void MainMenu::on_btn_query_clicked()
{

}
