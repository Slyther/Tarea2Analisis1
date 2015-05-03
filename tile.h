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
    ~Tile();
private:
    Board* parentWid;
    QString TileName;
    virtual void paintEvent(QPaintEvent *ev);
    virtual void mousePressEvent(QMouseEvent *ev);
    bool isActive;
};

#endif // TILE_H
