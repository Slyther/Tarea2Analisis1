#include "bishop.h"
#include "../board.h"

Bishop::Bishop(Board *parentWid, QString TileName, Player *player) : ChessPiece(parentWid, TileName, player)
{
    if(player->player == Player::Player1){
        setPixmap(QPixmap(":/Images/bishop_black.svg"));
    }else{
        setPixmap(QPixmap(":/Images/bishop_white.svg"));
    }
}

Bishop::~Bishop()
{

}

void Bishop::calculateMovements()
{

}

