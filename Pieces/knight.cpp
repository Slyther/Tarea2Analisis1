#include "knight.h"
#include "../board.h"

Knight::Knight(Board *parentWid, QString TileName, Player *player) : ChessPiece(parentWid, TileName, player)
{
    if(player->player == Player::Player1){
        setPixmap(QPixmap(":/Images/knight_black.svg"));
    }else{
        setPixmap(QPixmap(":/Images/knight_white.svg"));
    }
}

Knight::~Knight()
{

}

void Knight::calculateMovements()
{

}

