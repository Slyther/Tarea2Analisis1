#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"

class Queen : public ChessPiece
{
public:
    Queen(Board* parentWid, QString TileName, Player* player);
    inline virtual bool isKing() { return false; }
    inline virtual bool isPawn() { return false; }
private:
    virtual void calculateMovements();
};

#endif // QUEEN_H
