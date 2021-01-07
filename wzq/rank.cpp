#include "rank.h"
#include "ui_rank.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPair>
#include <QVector>
#include <QString>
#include <QTabWidget>
#include <QAbstractItemView>

Rank::Rank(QWidget *parent) :
    QDialog(parent) ,
    ui(new Ui::Rank),
    delitem(nullptr)
{
    ui->setupUi(this);
    ui->tableWidget->setWindowTitle("排行榜");
    ui->tableWidget->setRowCount(10);//设置行数为10
    ui->tableWidget->setColumnCount(3);//设置列数为10
    QHeaderView* headerView=ui->tableWidget->verticalHeader();
    headerView->setHidden(true);
    QStringList header;
    header<<"排名"<<"用户名"<<"积分";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    //设置整行选取
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    updateRank();
}

Rank::~Rank()
{
    delete ui;
}

bool cmp(const QPair<QString,int>& x,const QPair<QString,int>& y){
    return x.second>y.second;
}

void sortMapByValue(QMap<QString,int>&m,QVector<QPair<QString,int>>& v){
    for(auto curr=m.begin();curr!=m.end();curr++)
        v.push_back(qMakePair(curr.key(),curr.value()));
    std::sort(v.begin(),v.end(),cmp);
}


void Rank::updateRank(){
    //清空map中的内容
    this->m.clear();
    ui->tableWidget->clearContents();
     QFile file("D:\\GitHub\\Qt\\wzq\\rank.txt");
    //打开文件读取数据并排序
     if(file.open(QIODevice::ReadOnly)){
       qDebug()<<"成功打开文件";
       QTextStream in(&file);
       QString name,score;
       in>>name>>score;
       while (!name.isEmpty()&&!score.isEmpty()) {
             qDebug()<<name<<score;
             int s=score.toInt();
             if(m.count(name)){
                 if(m[name]<s){
                      m[name]=s;
                 }
             }
             else
                 m.insert(name,s);

             in>>name>>score;
       }
       file.close();
       QVector<QPair<QString,int>> vec;
       //通过value排序
       sortMapByValue(this->m,vec);
       qDebug()<<"成功排序";
       for(int i=0;i<vec.size();i++)
           qDebug()<<vec[i].first<<vec[i].second;


       //只显示排名前十
       for(int i=0;i<vec.size()&&i<10;i++){
           ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));
           ui->tableWidget->setItem(i,1,new QTableWidgetItem(vec[i].first));
           ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(vec[i].second)));
       }
     }
     else{
         qDebug()<<"打开文件失败";
     }

}

void Rank::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    this->delitem=item;
    qDebug()<<"删除元素选择成功";
}

void Rank::on_delButton_clicked()
{
    if(this->delitem==nullptr)
        return;
    int r=this->delitem->row();
    qDebug()<<r;
    QString str=ui->tableWidget->item(r,1)->text();
    if(m.find(str)==m.end()){
        qDebug()<<"删除失败";
        return;
    }
    this->m.erase(m.find(str));
    qDebug()<<str;

    QFile file("D:\\GitHub\\Qt\\wzq\\rank.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        qDebug()<<"成功打开文件";
        QTextStream out(&file);
        for(auto curr=this->m.begin();curr!=this->m.end();curr++){
            out<<curr.key()<<'\n';
            out<<curr.value()<<'\n';
        }
        qDebug()<<"成功写入";
    }
    else{
        qDebug()<<"打开文件失败";
    }
    this->delitem=nullptr;
    updateRank();
}

void Rank::on_pushButton_clicked()
{
    this->close();
}
