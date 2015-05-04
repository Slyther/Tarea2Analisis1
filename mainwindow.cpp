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
    connect(gameBoard, SIGNAL(endGame()), this, SLOT(newGame()));
    setFixedSize(700, 560);
    score = new QLabel(ui->centralWidget);
    score->move(590, 25);
    score->setFixedSize(100, 20);
    score->show();
    update();
}

MainWindow::~MainWindow()
{
    delete gameBoard;
    delete score;
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
        newGame();
    }
}

void MainWindow::newGame()
{
    delete gameBoard;
    gameBoard = new Board(ui->centralWidget);
    gameBoard->show();
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
    QMainWindow::paintEvent(ev);
    score->setText(QString("Turn: %1").arg(gameBoard->getTurn()));
}
