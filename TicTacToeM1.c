 #include <stdio.h>
#include <stdbool.h>

// The game board
char board[3][3];

// Function to initialize game/board
void initialize() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to check if there is any empty cell in game/board
bool isMovesLeft() {
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            if (board[i][j]==' ')
                return true;
        }
    }
    return false;
}

// Function to check if a player has won
bool checkWin() {
    for(int i=0; i<3; i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' ')
            return false;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ')
            return false;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
        return false;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ')
        return false;
    return true;
}

// Function to make a move for the AI player
void makeAIMove() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

// Function to draw the Tic Tac Toe board
void drawBoard() {
    printf("\n");
    for(int i=0; i<3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

// The main function
int main() {
    int x, y;
    initialize();
    drawBoard();
    while(isMovesLeft() && checkWin()) {
        printf("\nPlayer 1 (X), Enter your move (row[1-3] and column[1-3]): ");
        scanf("%d %d", &x, &y);
        x--; y--;
        if(board[x][y] != ' ') {
            printf("Invalid move, try again.\n");
        } else {
            board[x][y] = 'X';
            drawBoard();
            if(!checkWin()) {
                printf("Player 1 wins!\n");
                break;
            }
            if(isMovesLeft()) {
                makeAIMove();
                drawBoard();
                if(!checkWin()) {
                    printf("AI wins!\n");
                    break;
                }
            }
        }
    }
    if(checkWin()) {
        printf("It's a draw.\n");
    }
    return 0;
}
