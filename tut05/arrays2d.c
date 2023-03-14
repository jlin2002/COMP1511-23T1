// A demonstration of 2D arrays using tic tac toe.
// Joanna Lin, October 2022

#include <stdio.h>

#define SIZE 5
#define FALSE 0
#define TRUE 1

int did_player_win(char player, char board[SIZE][SIZE]);
int check_columns(char player, char board[SIZE][SIZE]);
int check_rows(char player, char board[SIZE][SIZE]);
int check_diagonal(char player, char board[SIZE][SIZE]);
int check_off_diagonal(char player, char board[SIZE][SIZE]);

int main(void) {
    char no_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'X', 'O', 'O', 'O'},
        {'X', ' ', ' ', ' ', 'O'},
    };

    char x_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'O', ' ', 'X', ' '},
        {' ', 'X', 'X', ' ', ' '},
        {'O', 'X', 'O', 'X', 'O'},
        {'X', 'X', ' ', ' ', 'X'},
    };
    char o_wins_board[SIZE][SIZE] = {
        {'O', 'X', ' ', ' ', 'X'},
        {' ', 'X', ' ', ' ', ' '},
        {' ', 'X', 'O', ' ', ' '},
        {'O', 'O', 'O', 'O', 'O'},
        {'X', 'X', ' ', ' ', 'O'},
    };

    if (did_player_win('X', x_wins_board)) {
        printf("X Won This Board!\n");
    } else if (did_player_win('O', x_wins_board)) {
        printf("O Won This Board!\n");
    } else {
        printf("Nobody has won this board!\n");
    }
}

// Determines whether 'player' won; that is, the board has
// a complete row, column or diagonal filled with the given
// 'player' character
// Inputs
// - player: either 'X' or 'O'
// - board: a 2D array, each entry either 'X', 'O' or ' '
// Returns 1 if 'player' won and 0 otherwise
int did_player_win(char player, char board[SIZE][SIZE]) {
    return check_columns(player, board) || check_rows(player, board)
        || check_diagonal(player, board) || check_off_diagonal(player, board);
}

// Determine whether there is a consecutive column of 'player' 
// characters on the board
int check_columns(char player, char board[SIZE][SIZE]) {
    // Loop through columns
    int col = 0;
    while (col < SIZE) {
        // For each column, 
        int player_has_won = TRUE;
        int row = 0;
        while (row < SIZE) {
            // check if all the row numbers
            // hold the right character
            if (board[row][col] != player) {
                player_has_won = FALSE;
            }
            row++;
        }
        if (player_has_won) {
            return TRUE;
        }
        col++;
    }
    return FALSE;
}

// Determine whether there is a consecutive row of 'player' 
// characters on the board
int check_rows(char player, char board[SIZE][SIZE]) {
    // Loop through rows
    int row = 0;
    while (row < SIZE) {
        // For each row, 
        int player_has_won = TRUE;
        int col = 0;
        while (col < SIZE) {
            // check if all the column numbers
            // hold the right character
            if (board[row][col] != player) {
                player_has_won = FALSE;
            }
            col++;
        }
        if (player_has_won) {
            return TRUE;
        }
        row++;
    }
    return FALSE; 
}

// Determine whether the diagonal is filled with 'player'
// characters on board.
int check_diagonal(char player, char board[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        if (board[row][row] != player) {
            return FALSE;
        }
        row++;
    }
    return TRUE;
}

// Determine whether the off-diagonal is filled with 'player'
// characters on board.
int check_off_diagonal(char player, char board[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        if (board[row][SIZE - 1 - row] != player) {
            return FALSE;
        }
        row++;
    }
    return TRUE;
}
