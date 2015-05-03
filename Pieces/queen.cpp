#include "queen.h"
#include "../board.h"

Queen::Queen(Board *parentWid, QString TileName, Player *player) : ChessPiece(parentWid, TileName, player)
{
    if(player->player == Player::Player1){
        setPixmap(QPixmap(":/Images/queen_black.svg"));
    }else{
        setPixmap(QPixmap(":/Images/queen_white.svg"));
    }
}

Queen::~Queen()
{

}

void Queen::calculateMovements()
{

}

