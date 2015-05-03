#include "chesspiece.h"
#include "../board.h"
#include "../player.h"
#include <QDebug>
ChessPiece::ChessPiece(Board *parentWid, QString TileName, Player *player) : QLabel(parentWid)
{
    this->TileName = TileName;
    this->player = player;
    this->parentWid = parentWid;
}

ChessPiece::~ChessPiece()
{

}

void ChessPiece::mousePressEvent(QMouseEvent *ev)
{
    if(player->isPlayerTurn(parentWid->getTurn())){
        if(parentWid->isMoving())
            parentWid->togglePossibleMoves();
        calculateMovements();
        validateTileNames();
        if(!parentWid->possibleMoves.isEmpty()){
            parentWid->togglePossibleMoves();
            parentWid->selectedPiece = this;
        }
    }else{
        if(parentWid->isMoving()){
            if(parentWid->selectedPiece->isPawn()){
                char letter = parentWid->possibleMoves.at(0).at(0).toLatin1();
                char number = parentWid->possibleMoves.at(0).at(1).toLatin1();
                QString diagonal1 = QString("").append(letter+1).append(number);
                QString diagonal2 = QString("").append(letter-1).append(number);
                if(TileName == diagonal1 || TileName == diagonal2){
                    parentWid->doMovement(this);
                }
            }else{
                foreach(QString TL, parentWid->possibleMoves){
                    if(TileName == TL){
                        parentWid->doMovement(this);
                    }
                }
            }
        }
    }
}

void ChessPiece::validateTileNames()
{
    for(int i = 0; i < parentWid->possibleMoves.length(); i++){
        char letter = parentWid->possibleMoves.at(i).at(0).toLatin1();
        char number = parentWid->possibleMoves.at(i).at(1).toLatin1();
        if(letter > 'H' || letter < 'A' || number > '8' || number < '1'){
            parentWid->possibleMoves.remove(i);
            i=0;
        }
    }
}

