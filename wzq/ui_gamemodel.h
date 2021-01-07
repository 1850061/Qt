/********************************************************************************
** Form generated from reading UI file 'gamemodel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMODEL_H
#define UI_GAMEMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_GameModel
{
public:

    void setupUi(QDialog *GameModel)
    {
        if (GameModel->objectName().isEmpty())
            GameModel->setObjectName(QStringLiteral("GameModel"));
        GameModel->resize(400, 300);

        retranslateUi(GameModel);

        QMetaObject::connectSlotsByName(GameModel);
    } // setupUi

    void retranslateUi(QDialog *GameModel)
    {
        GameModel->setWindowTitle(QApplication::translate("GameModel", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameModel: public Ui_GameModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMODEL_H
