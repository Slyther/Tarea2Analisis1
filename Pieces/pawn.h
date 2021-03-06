#ifndef PAWN_H
#define PAWN_H
#include "chesspiece.h"

class Pawn : public ChessPiece
{
public:
    Pawn(Board* parentWid, QString TileName, Player* player);
    inline virtual bool isKing() { return false; }
    inline virtual bool isPawn() { return true; }
private:
    virtual void calculateMovements();
};

#endif // PAWN_H
