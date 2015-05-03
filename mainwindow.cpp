#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    delete gameBoard;
    gameBoard = new Board(ui->centralWidget);
    gameBoard->show();
}
