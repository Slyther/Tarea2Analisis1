#include "pawn.h"
#include "../player.h"
#include "../board.h"
#include <QDebug>
Pawn::Pawn(Board *parentWid, QString TileName, Player *player) : ChessPiece(parentWid, TileName, player)
{
    if(player->player == Player::Player1){
        setPixmap(QPixmap(":/Images/pawn_black.svg"));
    }else{
        setPixmap(QPixmap(":/Images/pawn_white.svg"));
    }
}

Pawn::~Pawn()
{

}

void Pawn::calculateMovements()
{
    parentWid->possibleMoves.clear();
    char letter = TileName.at(0).toLatin1();
    char number = TileName.at(1).toLatin1();
    QVector<ChessPiece*> EnemyPieceList;
    QVector<ChessPiece*> AllyPieceList = player->chessPieceList;
    if(parentWid->player1->player == player->player)
        EnemyPieceList = parentWid->player2->chessPieceList;
    else
        EnemyPieceList = parentWid->player1->chessPieceList;


    ACTION:
    QString movement = QString("").append(letter).append((player->player == Player::Player1 ? number-1 : number+1));
    foreach(ChessPiece* chesspiece, EnemyPieceList){
        if(chesspiece->TileName == movement){
            parentWid->possibleMoves.push_back(movement);
            return;
        }
    }
    foreach(ChessPiece* chesspiece, AllyPieceList){
        if(chesspiece->TileName == movement){
            return;
        }
    }
    parentWid->possibleMoves.push_back(movement);
    if(number == '7' || number == '2'){
        switch(number){
        case '7':
            number--;
            break;
        case '2':
            number++;
            break;
        }
        goto ACTION;
    }
}

