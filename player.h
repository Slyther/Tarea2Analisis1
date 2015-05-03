#ifndef PLAYER_H
#define PLAYER_H
#include <QVector>

#include "Pieces/bishop.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/queen.h"
#include "Pieces/rook.h"
class Board;
class Player
{
public:
    enum PlayerType{
        Player1 = 1, Player2 = 2
    };

    Player(PlayerType player, Board* board);
    ~Player();
    inline bool isPlayerTurn(int turn){ int playerStance = player%2;
                                        int turnStance = turn%2;
                                        return playerStance == turnStance; }
    QVector< ChessPiece * > chessPieceList;
    PlayerType player;
private:
    Board* board;
    void initializePlayer();
};

#endif // PLAYER_H
