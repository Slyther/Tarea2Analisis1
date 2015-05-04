#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QLabel>

class Player;
class Board;
class ChessPiece : public QLabel
{
public:
    ChessPiece(Board* parentWid, QString TileName, Player* player);
    QString TileName;
    Player* player;
    virtual bool isKing() = 0;
    virtual bool isPawn() = 0;
protected:
    void beginMovementLogic();
    void validateTileNames();
    virtual void calculateMovements() = 0;
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void enterEvent(QEvent *e);
    virtual void leaveEvent(QEvent *e);
    Board* parentWid;
};

#endif // CHESSPIECE_H
