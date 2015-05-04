#ifndef TILE_H
#define TILE_H
#include <QLabel>
#include <QPainter>

class Board;
class Tile : public QLabel
{
public:
    Tile(Board *parentWid, QString TileName);
    void toggle();
    inline QString getTileName(){ return TileName; }
    virtual void enterEvent(QEvent *e);
    virtual void leaveEvent(QEvent *e);
private:
    Board* parentWid;
    QString TileName;
    virtual void paintEvent(QPaintEvent *ev);
    virtual void mousePressEvent(QMouseEvent *ev);
    bool isActive, underMouse;
};

#endif // TILE_H
