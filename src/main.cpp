#include <stdio.h>
// #include "display.h"
#include "game.h"
#include "input.h"


int main() {
    GameManager game = GameManager();
    InputManager input = InputManager();
    game.setBoard(input.getPieces());

    game.showBoard();

    // unsigned char board[8][8] = {
    //     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    //     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    //     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    //     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    //     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    //     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    //     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    //     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    // };

    // for (int i=0; i<8; i++) {
    //     for (int j=0; j<8; j++) {
    //         printf("%c", board[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // printf("Hello World\n");
    return 0;
}