#include "king.h"
#include "../board.h"

King::King(Board *parentWid, QString TileName, Player *player) : ChessPiece(parentWid, TileName, player)
{
    if(player->player == Player::Player1){
        setPixmap(QPixmap(":/Images/king_white.svg"));
    }else{
        setPixmap(QPixmap(":/Images/king_black.svg"));
    }
}

void King::calculateMovements()
{
    parentWid->possibleMoves.clear();
    char letter = TileName.at(0).toLatin1();
    char number = TileName.at(1).toLatin1();
    QVector<ChessPiece*> AllyPieceList = player->chessPieceList;
    QString movement;
    movement = QString("").append(letter-1).append(number-1);
    parentWid->possibleMoves.push_back(movement);
    movement = QString("").append(letter-1).append(number+1);
    parentWid->possibleMoves.push_back(movement);
    movement = QString("").append(letter+1).append(number-1);
    parentWid->possibleMoves.push_back(movement);
    movement = QString("").append(letter+1).append(number+1);
    parentWid->possibleMoves.push_back(movement);
    movement = QString("").append(letter-1).append(number);
    parentWid->possibleMoves.push_back(movement);
    movement = QString("").append(letter+1).append(number);
    parentWid->possibleMoves.push_back(movement);
    movement = QString("").append(letter).append(number+1);
    parentWid->possibleMoves.push_back(movement);
    movement = QString("").append(letter).append(number-1);
    parentWid->possibleMoves.push_back(movement);

    foreach(ChessPiece* cp, AllyPieceList){
        for(int i = 0; i < parentWid->possibleMoves.length(); i++){
            if(cp->TileName == parentWid->possibleMoves.at(i)){
                parentWid->possibleMoves.remove(i);
                i = -1;
            }
        }
    }
}

