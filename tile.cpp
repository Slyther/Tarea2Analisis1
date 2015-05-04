#include "tile.h"
#include "board.h"
#include <QDebug>

Tile::Tile(Board* parentWid, QString TileName) : QLabel(parentWid)
{
    this->parentWid = parentWid;
    this->TileName = TileName;
    isActive = false;
    underMouse = false;
    setFixedSize(64, 64);
    raise();
    update();
    this->setStyleSheet("QLabel {background-color: rgba(0,0,0,0%)}:hover{background-color: rgb(170,85,127);}");
}

void Tile::toggle()
{
    isActive = !isActive;
    update();
}

Tile::~Tile()
{

}

void Tile::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    if(isActive){
        p.fillRect(QRect(0, 0, width(), height()), QBrush(QColor(0, 237, 16)));
    }else if(underMouse){
        p.fillRect(QRect(0, 0, width(), height()), QBrush(QColor(170,85,127)));
    }else{
        int letter = TileName.at(0).toLatin1();
        int number = TileName.at(1).toLatin1();
        int letterOrder = letter % 2;
        int numberOrder = number % 2;
        if(letterOrder == numberOrder){
            p.fillRect(QRect(0, 0, width(), height()), QBrush(QColor(105, 105, 105)));
        }else{
            p.fillRect(QRect(0, 0, width(), height()), QBrush(QColor(255, 255, 255)));
        }
    }

    p.setPen(QPen(QBrush(QColor(0, 0, 0)), 1));
    p.drawLine(0, 0, width(), 0);
    p.drawLine(0, 0, 0, height());
    p.drawLine(width(), 0, width(), height());
    p.drawLine(0, height(), width(), height());
}

void Tile::mousePressEvent(QMouseEvent *ev){
    Q_UNUSED(ev);
    parentWid->validateClickedTile(TileName);
}

void Tile::enterEvent(QEvent *e)
{
    underMouse = true;
    update();
}

void Tile::leaveEvent(QEvent *e)
{
    underMouse = false;
    update();
}
