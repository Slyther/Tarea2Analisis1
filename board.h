#ifndef BOARD_H
#define BOARD_H
#include <QLabel>
#include <QVector>
#include <QMap>
#include "tile.h"
#include "Pieces/chesspiece.h"
#include "player.h"

class Board : public QLabel
{
public:
    Board(QWidget* parentWid);
    QVector<QString> possibleMoves;
    void validateClickedTile(QString TileName);
    void togglePossibleMoves();
    void doMovement(ChessPiece* toDie);
    inline bool isMoving(){ return moving; }
    inline int getTurn(){ return turn; }
    QMap<QString, Tile*> tileMap;
    Player* player1,* player2;
    ChessPiece* selectedPiece;
    ~Board();
private:
    void setTilePositions();
    bool moving;
    int turn;
};

#endif // BOARD_H
