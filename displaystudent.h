#ifndef DISPLAYSTUDENT_H
#define DISPLAYSTUDENT_H

#include <QWidget>
#include<QStandardItem>
#include<QStandardItemModel>


namespace Ui {
class DisplayStudent;
}

class DisplayStudent : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayStudent(QWidget *parent = nullptr);
    ~DisplayStudent();

    void setHeader();       //设置表头
    void displayAll();      //显示所有学生信息

private:
    Ui::DisplayStudent *ui;
    QStandardItemModel* model = nullptr;
};

#endif // DISPLAYSTUDENT_H
