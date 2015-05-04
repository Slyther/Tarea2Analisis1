#ifndef KNIGHT_H
#define KNIGHT_H
#include "chesspiece.h"

class Knight : public ChessPiece
{
public:
    Knight(Board* parentWid, QString TileName, Player* player);
    ~Knight();
    inline virtual bool isKing() { return false; }
    inline virtual bool isPawn() { return false; }
private:
    virtual void calculateMovements();
};

#endif // KNIGHT_H
