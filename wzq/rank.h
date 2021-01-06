#ifndef RANK_H
#define RANK_H

#include <QDialog>

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

private:
    Ui::Rank *ui;
};

#endif // RANK_H
