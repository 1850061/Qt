#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamemodel.h"
#include <QLabel>
#include "login.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void receiveName(const QString &name){
        qDebug()<<"receive name:"<<name;
        this->username=name;
        qDebug()<<this->username;
    }

protected:
    // 绘制
    void paintEvent(QPaintEvent *event);
    // 监听鼠标移动情况，方便落子
    void mouseMoveEvent(QMouseEvent *event);
    // 实际落子
    void mouseReleaseEvent(QMouseEvent *event);

private:
    GameModel *game; // 游戏指针
    GameType game_type; // 存储游戏类型
    int clickPosRow, clickPosCol; // 存储将点击的位置
    void initGame();
    void checkGame(int y, int x);
    Ui::MainWindow *ui;
    QLabel *score;
    Login login;
    QString username;


private slots:
    void chessOneByPerson(); // 人执行
    void chessOneByAI(); // AI下棋

    void initPVPGame();
    void initPVEGame();
};
#endif // MAINWINDOW_H
