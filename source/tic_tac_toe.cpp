#include <iostream>
#include "tic_tac_toe.hpp"

using namespace std;

int TicTacToe::moveCount{ MIN_MOVE_COUNT };
bool TicTacToe::choice{ GAME_CONTINUE };

void TicTacToe::drawBoard()
{
    cout << "Tic-Tac-Toe!" << endl << endl;
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
    cout << endl;
}

void TicTacToe::resetBoard(void)
{
    for (int i = MIN_MOVE_COUNT; i < MAX_MOVE_COUNT; ++i){
        board[i] = (i + 1) + '0';
    }
    moveCount = MIN_MOVE_COUNT;
}

void TicTacToe::gameChoice(void)
{
    cout << "0. Exit" << endl;
    cout << "1. Reset" << endl;
    int userChoice;
    cout << "Enter your choice: ";
    cin >> userChoice;
    choice = static_cast<GameChoice>( userChoice );
    
    if(choice == GameChoice::GAME_EXIT){
        cout << "Thanks for playing!" << endl << endl;
        exit(0);
    }
    else if(choice == GameChoice::GAME_CONTINUE){
        resetBoard();
        system("cls");
        setPlayer(PLAYER1);
        drawBoard();
    }
}

void TicTacToe::playerMove()
{
    int boardIndex;
    
    cout << "Player " << this->player << ", enter a number: ";
    cin >> boardIndex;
    if (boardIndex < 1 || boardIndex > 9) {
        cout << "Invalid input! Please enter a number between 1 and 9." << endl;
        playerMove();
        return;
    }

    char chBoardIndex = '0' + boardIndex; // Convert to char
    if ((board[chBoardIndex - '1'] == 'X') || (board[chBoardIndex - '1'] == 'O')) {
        cout << "Invalid move! The cell is already occupied." << endl;
        playerMove();
        return;
    }
    board[(chBoardIndex - '1')] = (this->player == PLAYER1) ? 'X': 'O';
    moveCount++;
}

bool TicTacToe::checkWinningConditions(void)
{
    // Check rows
    for (int i = 0; i < MAX_MOVE_COUNT; i += 3) {
        if ((board[i] == board[i + 1]) && (board[i + 1] == board[i + 2]))
            return true;
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i] == board[i + 3]) && (board[i + 3] == board[i + 6]))
            return true;
    }
    // Check diagonals
    if ((board[0] == board[4]) && (board[4] == board[8]))
        return true;
    if ((board[2] == board[4]) && (board[4] == board[6]))
        return true;
    return false;
}

void TicTacToe::checkWinner()
{
    if(checkWinningConditions()){        
        cout << "Player " << this->player << " wins!" << endl;
        cout << "Game Over !!!" << endl << endl;          
        gameChoice();
    }
    else if (moveCount == MAX_MOVE_COUNT){        
        cout << "Game Over !!!" << endl;
        cout << "It's a draw!" << endl << endl;        
        gameChoice();
    }
}
