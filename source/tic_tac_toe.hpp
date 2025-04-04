#pragma once

enum class GameChoice : bool {
    GAME_EXIT = false,
    GAME_CONTINUE = true 
};

constexpr int PLAYER1 = 1U;
constexpr int PLAYER2 = 2U;
constexpr int MIN_MOVE_COUNT = 0U;
constexpr int MAX_MOVE_COUNT = 9U;

class TicTacToe {
    private:
        char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        static int moveCount;
        static GameChoice choice;
        int player;

    public:
        // constructor
        TicTacToe(): player (PLAYER1) {}

        // member functions
        void drawBoard();
        void resetBoard(void);
        void gameChoice(void);
        void playerMove();
        bool checkWinningConditions(void);
        void checkWinner();

        // static member functions
        static GameChoice getChoice(void) { return choice; }

        // getters and setters
        int getPlayer(void) const { return this->player; }
        void setPlayer(int player) { this->player = player; }
    };