#ifndef KING_H
#define KING_H
#include "chesspiece.h"

class King : public ChessPiece
{
public:
    King(Board* parentWid, QString TileName, Player* player);
    ~King();
    inline virtual bool isKing() { return true; }
    inline virtual bool isPawn() { return false; }
private:
    virtual void calculateMovements();
};

#endif // KING_H
