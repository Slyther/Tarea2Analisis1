#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "board.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_Game_triggered();
    void newGame();

private:
    virtual void paintEvent(QPaintEvent *ev);
    Ui::MainWindow *ui;
    Board* gameBoard;
    QLabel* score;
};

#endif // MAINWINDOW_H
