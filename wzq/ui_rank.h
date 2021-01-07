/********************************************************************************
** Form generated from reading UI file 'rank.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANK_H
#define UI_RANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Rank
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QPushButton *delButton;
    QPushButton *pushButton;

    void setupUi(QDialog *Rank)
    {
        if (Rank->objectName().isEmpty())
            Rank->setObjectName(QStringLiteral("Rank"));
        Rank->resize(444, 544);
        tableWidget = new QTableWidget(Rank);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 40, 431, 441));
        label = new QLabel(Rank);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 20, 81, 18));
        delButton = new QPushButton(Rank);
        delButton->setObjectName(QStringLiteral("delButton"));
        delButton->setGeometry(QRect(120, 500, 93, 28));
        pushButton = new QPushButton(Rank);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 500, 93, 28));

        retranslateUi(Rank);

        QMetaObject::connectSlotsByName(Rank);
    } // setupUi

    void retranslateUi(QDialog *Rank)
    {
        Rank->setWindowTitle(QApplication::translate("Rank", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Rank", "\346\216\222\350\241\214\346\246\234", Q_NULLPTR));
        delButton->setText(QApplication::translate("Rank", "Delect", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Rank", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Rank: public Ui_Rank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANK_H
