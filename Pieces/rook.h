#ifndef ROOK_H
#define ROOK_H
#include "chesspiece.h"

class Rook : public ChessPiece
{
public:
    Rook(Board* parentWid, QString TileName, Player* player);
    inline virtual bool isKing() { return false; }
    inline virtual bool isPawn() { return false; }
private:
    virtual void calculateMovements();
};

#endif // ROOK_H
