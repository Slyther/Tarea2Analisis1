#ifndef BISHOP_H
#define BISHOP_H
#include "chesspiece.h"

class Bishop : public ChessPiece
{
public:
    Bishop(Board* parentWid, QString TileName, Player* player);
    ~Bishop();
    inline virtual bool isQueen() { return false; }
    inline virtual bool isPawn() { return false; }
private:
    virtual void calculateMovements();
};

#endif // BISHOP_H
