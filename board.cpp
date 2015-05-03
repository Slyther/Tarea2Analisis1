#include "board.h"
#include <QDebug>
Board::Board(QWidget *parentWid) : QLabel(parentWid)
{
    move(0, 0);
    setFixedSize(512, 512);
    for(char i = 65; i < 73; i++ ){//letter code in ASCII
        for(char j = 49; j < 57; j++ ){//number code in ASCII
            QString tileName = QString("").append(i).append(j);
            tileMap.insert(tileName, new Tile(this, tileName));
        }
    }
    turn = 1;
    selectedPiece = 0;
    moving = false;
    setTilePositions();
    player1 = new Player(Player::Player1, this);
    player2 = new Player(Player::Player2, this);
    update();
}

void Board::validateClickedTile(QString TileName)
{
    if(selectedPiece == 0)
        return;
    foreach(QString TName, possibleMoves){
        if(TName == TileName){
            selectedPiece->move(tileMap[TileName]->pos());
            selectedPiece->TileName = TileName;
            selectedPiece = 0;
            togglePossibleMoves();
            possibleMoves.clear();
            turn++;
            return;
        }
    }
}

void Board::togglePossibleMoves()
{
    foreach(QString TName, possibleMoves){
        tileMap[TName]->toggle();
    }
    if(possibleMoves.length() != 0)
        moving = !moving;
}

void Board::doMovement(ChessPiece *toDie)
{
    selectedPiece->move(tileMap[toDie->TileName]->pos());
    selectedPiece->TileName = toDie->TileName;
    for(int i = 0; i < toDie->player->chessPieceList.length(); i++){
        if(toDie->player->chessPieceList.at(i) == toDie){
            toDie->player->chessPieceList.remove(i);
            if(toDie->isQueen()){
                //do endgame scenario here
                return;
            }
            delete toDie;
            turn++;
            togglePossibleMoves();
            break;
        }
    }
}

Board::~Board()
{

}

void Board::setTilePositions()
{
    QMap<char, int> positionMap;
    positionMap.insert('A', 0);
    positionMap.insert('B', 64);
    positionMap.insert('C', 128);
    positionMap.insert('D', 192);
    positionMap.insert('E', 256);
    positionMap.insert('F', 320);
    positionMap.insert('G', 384);
    positionMap.insert('H', 448);
    positionMap.insert('8', 0);
    positionMap.insert('7', 64);
    positionMap.insert('6', 128);
    positionMap.insert('5', 192);
    positionMap.insert('4', 256);
    positionMap.insert('3', 320);
    positionMap.insert('2', 384);
    positionMap.insert('1', 448);
    foreach(Tile* tl, tileMap){
        char letter = tl->getTileName().at(0).toLatin1();
        char number = tl->getTileName().at(1).toLatin1();
        tl->move(positionMap[letter], positionMap[number]);
    }
}

