#include "king.h"
#include "../board.h"

King::King(Board *parentWid, QString TileName, Player *player) : ChessPiece(parentWid, TileName, player)
{
    if(player->player == Player::Player1){
        setPixmap(QPixmap(":/Images/king_black.svg"));
    }else{
        setPixmap(QPixmap(":/Images/king_white.svg"));
    }
}

King::~King()
{

}

void King::calculateMovements()
{

}

