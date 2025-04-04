#include<iostream>
#include "tic_tac_toe.hpp"

using namespace std;

int main()
{
    TicTacToe game;
    system("cls");
    game.drawBoard();

    while (game.getChoice() == GameChoice::GAME_CONTINUE)
    {
        game.playerMove();
        system("cls");
        game.drawBoard();
        game.checkWinner();
        game.setPlayer(( 
            ( game.getPlayer() == PLAYER1 )
            ? PLAYER2 
            : PLAYER1 )
        );
    }

    return 0;
}