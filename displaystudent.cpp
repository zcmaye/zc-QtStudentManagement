#include "displaystudent.h"
#include "ui_displaystudent.h"
#include"database.h"
#include<QModelIndex>
#include<QItemDelegate>

class ReadOnlyDelegate:public QItemDelegate
{
public:
    ReadOnlyDelegate(QWidget* parent = nullptr):QItemDelegate(parent){}
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override
    {
        Q_UNUSED(parent);
        Q_UNUSED(option);
        Q_UNUSED(index);
        return nullptr;
    }
};

DisplayStudent::DisplayStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayStudent)
{
    ui->setupUi(this);

    model = new QStandardItemModel;
    this->setHeader();
    ui->tableView->setModel(model);

}

DisplayStudent::~DisplayStudent()
{
    delete ui;
}

void DisplayStudent::setHeader()
{
    model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    model->setHorizontalHeaderItem(1,new QStandardItem("学号"));
    model->setHorizontalHeaderItem(2,new QStandardItem("性别"));
    model->setHorizontalHeaderItem(3,new QStandardItem("年龄"));
    model->setHorizontalHeaderItem(4,new QStandardItem("院系"));

    ui->tableView->setColumnWidth(2,50);
    ui->tableView->setColumnWidth(3,50);
    ui->tableView->setItemDelegateForColumn(1,new ReadOnlyDelegate); //设置第二列为只读
}

void DisplayStudent::displayAll()
{
    model->clear();
    this->setHeader();
    QStringList* result = database::getInstance()->readStudentInfo();
    for(QString& info : *result)
    {
        //qDebug()<<info<<endl;
       QStringList item =  info.split(" ");     //把一条学生信息，按空格分开
        int row = model->rowCount();
       for (int i=0 ;i<item.size();i++)
       {
             model->setItem(row,i,new QStandardItem(item[i]));
       }

      // cout<< model->rowCount()<<"  "<<model->columnCount()<<endl;

    }
}
