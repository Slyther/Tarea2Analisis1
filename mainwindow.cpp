#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Team Python's Chess");
    gameBoard = new Board(ui->centralWidget);
    gameBoard->show();
    setFixedSize(700, 560);
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Game_triggered()
{
    QMessageBox *msg = new QMessageBox(QMessageBox::Question, "New Game",
                                       "Are you sure you want to start a new game?",
                                       QMessageBox::Yes | QMessageBox::No, this, Qt::Popup);
    msg->setWindowModality(Qt::NonModal);
    int reply = msg->exec();
    if(reply == QMessageBox::Yes){
        delete gameBoard;
        gameBoard = new Board(ui->centralWidget);
        gameBoard->show();
    }
}
