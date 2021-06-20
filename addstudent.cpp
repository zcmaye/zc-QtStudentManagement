#include "addstudent.h"
#include "ui_addstudent.h"
#include<QMessageBox>
#include<QIcon>
#include<QStringList>
#include"database.h"

AddStudent::AddStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudent)
{
    ui->setupUi(this);
    ui->lineEdit_name->setPlaceholderText("请输入姓名");
    //年龄下拉框
    QStringList age_list;
    for (int i =0;i<120;i++)
    {
        age_list.push_back(QString("%1").arg(i));
    }
    //ui->cBox_age->addItem("1");
    ui->cBox_age->addItems(age_list);
}

AddStudent::~AddStudent()
{
    delete ui;
}
//确定添加
void AddStudent::on_btn_ok_clicked()
{
    //获取添加学生页面的所有数据
    QString name = ui->lineEdit_name->text();
    QString classId = ui->lineEdit_classId->text();
    QString sex = ui->SexGroup->checkedButton()->text();    //返回被选中的按钮,如果没有选中会返回nullptr
    QString age = ui->cBox_age->currentText();
    QString dpt = ui->cBox_dpt->currentText();

    QString content = name+"\n"+ classId+'\n'+sex +"\n" +age + "\n"+dpt;

    QMessageBox msgBox(this);
    msgBox.setText(content);
    auto def = msgBox.addButton("确定",QMessageBox::AcceptRole);
    msgBox.addButton("取消",QMessageBox::RejectRole);
    msgBox.setDefaultButton(def);

    int ret = msgBox.exec();
    //如果点击确定，把数据保存到文件中去
    if(ret == 0)
    {
        cout<<content.replace("\n"," ");    //把所有'\n'替换成空格
        database::getInstance()->saveStudentInfo(content);
    }
}
