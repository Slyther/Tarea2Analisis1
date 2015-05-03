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
    virtual void calculateMovements() = 0;
    void validateTileNames();
    Board* parentWid;
};

#endif // CHESSPIECE_H
