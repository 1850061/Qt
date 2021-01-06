#include "login.h"
#include "ui_login.h"

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
    this->send();
    this->close();
}

void Login::on_lineEdit_textChanged(const QString &arg1)
{
    this->name=arg1;
}
