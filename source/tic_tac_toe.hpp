#pragma once

enum GameChoice {
    GAME_EXIT = false,
    GAME_CONTINUE = true 
};

enum NOS_OF_PLAYERS {
    PLAYER1 = 1U,
    PLAYER2 = 2U
};

enum MOVE_COUNT {
    MIN_MOVE_COUNT = 0U,
    MAX_MOVE_COUNT = 9U
};

class TicTacToe {
    private:
        // member variables
        char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        // static member variables
        static int moveCount;
        static bool choice;
        int player{ PLAYER1};

    public:
        // constructor
        TicTacToe() = default;
        // member functions
        void drawBoard();
        void resetBoard(void);
        void gameChoice(void);
        void playerMove();
        bool checkWinningConditions(void);
        void checkWinner();
        // static member functions
        static bool getChoice(void) { return choice; }
        int getPlayer(void) { return this->player; }
        void setPlayer(int player) { this->player = player; }
    };