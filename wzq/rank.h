#ifndef RANK_H
#define RANK_H

#include <QDialog>
#include <QMap>
#include <QString>
#include <QTableWidgetItem>

namespace Ui {
class Rank;
}

class Rank : public QDialog
{
    Q_OBJECT

public:
    explicit Rank(QWidget *parent = nullptr);
    ~Rank();

    void updateRank();

private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_delButton_clicked();

    void on_pushButton_clicked();

    void cardinalSort(QVector<Qpair<Qstring, int>>& sortedArray, int start, int end, bool isAscend = false);
    void cardinalSortNoSign(QVector<Qpair<Qstring, int>>& sortedArray, int start, int end, bool isAscend = false);

private:
    Ui::Rank *ui;
    QMap<QString,int> m;
    QTableWidgetItem* delitem;
};

#endif // RANK_H
