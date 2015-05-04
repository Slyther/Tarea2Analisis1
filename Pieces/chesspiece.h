#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QLabel>
class Player;
class Board;
class ChessPiece : public QLabel
{
public:
    ChessPiece(Board* parentWid, QString TileName, Player* player);
    ~ChessPiece();
    QString TileName;
    Player* player;
    virtual bool isQueen() = 0;
    virtual bool isPawn() = 0;
protected:
    virtual void mousePressEvent(QMouseEvent *ev);
    void beginMovementLogic();
    virtual void calculateMovements() = 0;
    void validateTileNames();
    virtual void enterEvent(QEvent *e);
    virtual void leaveEvent(QEvent *e);
    Board* parentWid;
};

#endif // CHESSPIECE_H
