#include "rank.h"
#include "ui_rank.h"

Rank::Rank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rank)
{
    ui->setupUi(this);
    ui->tableWidget->setWindowTitle("排行榜");
    ui->tableWidget->setRowCount(10);//设置行数为10
    ui->tableWidget->setColumnCount(3);//设置列数为10

}

Rank::~Rank()
{
    delete ui;
}
