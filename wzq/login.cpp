#include "login.h"
#include "ui_login.h"
#include<QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    //当用户没有输入用户名时弹窗提醒输入
    if(this->ui->lineEdit->text().isEmpty()){
        QMessageBox::information(NULL, "提醒", "请先输入用户名");
    }
    else{
        this->send();
        this->close();
    }
}

void Login::on_lineEdit_textChanged(const QString &arg1)
{
    this->name=arg1;
}
