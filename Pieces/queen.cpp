#include "queen.h"
#include "../board.h"

Queen::Queen(Board *parentWid, QString TileName, Player *player) : ChessPiece(parentWid, TileName, player)
{
    if(player->player == Player::Player1){
        setPixmap(QPixmap(":/Images/queen_white.svg"));
    }else{
        setPixmap(QPixmap(":/Images/queen_black.svg"));
    }
}

Queen::~Queen()
{

}

void Queen::calculateMovements()
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

    int numero = (int) number;
       int numero2 = numero;
       for(char i = letter; i <= 'H'; i++){

           QString horizontal = QString("").append(i).append(numero2++);
           foreach(ChessPiece* chesspiece, EnemyPieceList){
               if(chesspiece->TileName == horizontal){
                   parentWid->possibleMoves.push_back(horizontal);
                   goto AFTERFOR1;
               }
           }
           foreach(ChessPiece* chesspiece, AllyPieceList){
               if(chesspiece->TileName == horizontal && chesspiece != this){
                   goto AFTERFOR1;
               }
           }
           parentWid->possibleMoves.push_back(horizontal);

       }
       AFTERFOR1:;
       int numero3=numero;
       for(char i = letter; i >= 'A'; i--){
           QString horizontal = QString("").append(i).append(numero3--);
           foreach(ChessPiece* chesspiece, EnemyPieceList){
               if(chesspiece->TileName == horizontal){
                   parentWid->possibleMoves.push_back(horizontal);
                   goto AFTERFOR2;
               }
           }
           foreach(ChessPiece* chesspiece, AllyPieceList){
               if(chesspiece->TileName == horizontal && chesspiece != this){
                   goto AFTERFOR2;
               }
           }
           parentWid->possibleMoves.push_back(horizontal);
       }
       AFTERFOR2:;

       int numero4= numero;
       for(char i = letter; i <= 'H'; i++){

           QString horizontal = QString("").append(i).append(numero4--);
           foreach(ChessPiece* chesspiece, EnemyPieceList){
               if(chesspiece->TileName == horizontal){
                   parentWid->possibleMoves.push_back(horizontal);
                   goto AFTERFOR3;
               }
           }
           foreach(ChessPiece* chesspiece, AllyPieceList){
               if(chesspiece->TileName == horizontal && chesspiece != this){
                   goto AFTERFOR3;
               }
           }
           parentWid->possibleMoves.push_back(horizontal);

       }
       AFTERFOR3:;
       int numero5=numero;
       for(char i = letter; i >= 'A'; i--){
           QString horizontal = QString("").append(i).append(numero5++);
           foreach(ChessPiece* chesspiece, EnemyPieceList){
               if(chesspiece->TileName == horizontal){
                   parentWid->possibleMoves.push_back(horizontal);
                    goto AFTERFOR4;
               }
           }
           foreach(ChessPiece* chesspiece, AllyPieceList){
               if(chesspiece->TileName == horizontal && chesspiece != this){
                  goto AFTERFOR4;
               }
           }
           parentWid->possibleMoves.push_back(horizontal);
       }

       /*------------------------------------------------------------*/
       AFTERFOR4:;
       for(char i = letter; i <= 'H'; i++){
           QString horizontal = QString("").append(i).append(number);
           foreach(ChessPiece* chesspiece, EnemyPieceList){
               if(chesspiece->TileName == horizontal){
                   parentWid->possibleMoves.push_back(horizontal);
                   goto AFTERFOR5;
               }
           }
           foreach(ChessPiece* chesspiece, AllyPieceList){
               if(chesspiece->TileName == horizontal && chesspiece != this){
                   goto AFTERFOR5;
               }
           }
           parentWid->possibleMoves.push_back(horizontal);
       }
       AFTERFOR5:;
       for(char i = letter; i >= 'A'; i--){
           QString horizontal = QString("").append(i).append(number);
           foreach(ChessPiece* chesspiece, EnemyPieceList){
               if(chesspiece->TileName == horizontal){
                   parentWid->possibleMoves.push_back(horizontal);
                   goto AFTERFOR6;
               }
           }
           foreach(ChessPiece* chesspiece, AllyPieceList){
               if(chesspiece->TileName == horizontal && chesspiece != this){
                   goto AFTERFOR6;
               }
           }
           parentWid->possibleMoves.push_back(horizontal);
       }
       AFTERFOR6:;
       for(char i = number; i <= '8'; i++){
           QString vertical = QString("").append(letter).append(i);
           foreach(ChessPiece* chesspiece, EnemyPieceList){
               if(chesspiece->TileName == vertical){
                   parentWid->possibleMoves.push_back(vertical);
                   goto AFTERFOR7;
               }
           }
           foreach(ChessPiece* chesspiece, AllyPieceList){
               if(chesspiece->TileName == vertical && chesspiece != this){
                   goto AFTERFOR7;
               }
           }
           parentWid->possibleMoves.push_back(vertical);
       }
       AFTERFOR7:;
       for(char i = number; i >= '1'; i--){
           QString vertical = QString("").append(letter).append(i);
           foreach(ChessPiece* chesspiece, EnemyPieceList){
               if(chesspiece->TileName == vertical){
                   parentWid->possibleMoves.push_back(vertical);
                   return;
               }
           }
           foreach(ChessPiece* chesspiece, AllyPieceList){
               if(chesspiece->TileName == vertical && chesspiece != this){
                   return;
               }
           }
           parentWid->possibleMoves.push_back(vertical);
       }


}

