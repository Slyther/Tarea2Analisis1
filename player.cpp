#include "player.h"
#include "board.h"
#include <QDebug>
Player::Player(PlayerType player, Board *board)
{
    this->player = player;
    this->board = board;
    initializePlayer();
}

Player::~Player()
{

}

void Player::initializePlayer()
{
    char row1;
    char row2;
    if(player == Player1){
        row1 = '8';
        row2 = '7';
    }else{
        row1 = '1';
        row2 = '2';
    }

    for(char i = 65; i < 73; i++){
        QString TN = QString("").append(i).append(row2);
        chessPieceList.push_back(new Pawn(board, TN, this));
        chessPieceList.at(chessPieceList.length()-1)->move(board->tileMap[TN]->pos());
    }

    QString TN = QString("").append('A').append(row1);
    chessPieceList.push_back(new Rook(board, TN, this));
    chessPieceList.at(chessPieceList.length()-1)->move(board->tileMap[TN]->pos());
    TN = QString("").append('H').append(row1);
    chessPieceList.push_back(new Rook(board, TN, this));
    chessPieceList.at(chessPieceList.length()-1)->move(board->tileMap[TN]->pos());

    TN = QString("").append('B').append(row1);
    chessPieceList.push_back(new Knight(board, TN, this));
    chessPieceList.at(chessPieceList.length()-1)->move(board->tileMap[TN]->pos());
    TN = QString("").append('G').append(row1);
    chessPieceList.push_back(new Knight(board, TN, this));
    chessPieceList.at(chessPieceList.length()-1)->move(board->tileMap[TN]->pos());

    TN = QString("").append('C').append(row1);
    chessPieceList.push_back(new Bishop(board, TN, this));
    chessPieceList.at(chessPieceList.length()-1)->move(board->tileMap[TN]->pos());
    TN = QString("").append('F').append(row1);
    chessPieceList.push_back(new Bishop(board, TN, this));
    chessPieceList.at(chessPieceList.length()-1)->move(board->tileMap[TN]->pos());

    TN = QString("").append('D').append(row1);
    chessPieceList.push_back(new Queen(board, TN, this));
    chessPieceList.at(chessPieceList.length()-1)->move(board->tileMap[TN]->pos());

    TN = QString("").append('E').append(row1);
    chessPieceList.push_back(new King(board, TN, this));
    chessPieceList.at(chessPieceList.length()-1)->move(board->tileMap[TN]->pos());
}

