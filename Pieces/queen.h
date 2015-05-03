#ifndef QUEEN_H
#define QUEEN_H
#include "chesspiece.h"

class Queen : public ChessPiece
{
public:
    Queen(Board* parentWid, QString TileName, Player* player);
    ~Queen();
    inline virtual bool isQueen(){ return true; }
    inline virtual bool isPawn() { return false; }
private:
    virtual void calculateMovements();
};

#endif // QUEEN_H
