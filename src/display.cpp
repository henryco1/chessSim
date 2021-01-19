/*
display.cpp

Cpp file for the display manager
*/
#include "display.h"
#include <string>
#include <stdint.h>

void DisplayManager::showGraphicBoard() {
    /*
    The board is modeled by two data structures which are
        1. the bitboard, which holds positional data
        2. the refbaord, which tells us what piece is at each position.
    */

    // unsigned long long bitboard = DisplayManager::bitboard;
    // unsigned char (*refboard)[8] = DisplayManager::refboard;

    // for (int i=0; i<8; i++) {
    //     for (int j=0; j<8; j++) {
    //         printf("%c", refboard[i][j]);
    //     }
    //     printf("\n");
    // }


    int row = 0;
    int col = 0;
    // printf("bitboard: %d\n", bitboard);
    printf("\n");
    while (bitboard) 
    {
        printf("%lu\n", bitboard);
        uint64_t temp = bitboard;
        for (int i=64; i>0; i--) {
            if (temp & 1) {
                printf("1");
            }
            else {
                printf("0");
            }
            temp >>= 1;
        }
        printf("\n");


        // get the piece position
        unsigned char curr = bitboard & 1;
        bitboard >>= 1;          

        // printf("row: %d, col: %d\n", row, col);
        if (col % 8 == 0) 
        {
            // get the type of piece
            // tempboard[col][row] = **refboard + row + col;
            if (curr) {
                gfxboard[col][row] = refboard[col][row];
            }
            row++;
            col = 0;
        }
        else 
        {
            // get the type of piece
            // tempboard[col][row] = **refboard + row + col;
            if (curr) {
                gfxboard[col][row] = refboard[col][row];
            }
            col++;
        }


    }

    // render the board
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%c", gfxboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    // unsigned char arr[3] = {'1', '2', '3'};
    // traditional array iteration
    // for (int i=0; i<3; i++) {
    //     printf("%c\n", arr[i]);
    // }

    // iterate through a 1d array via pointer notation
    // for (unsigned char* tmp = arr, i=0; i<3; i++) {
    //     printf("%c\n", *tmp++);
    // }

    // unsigned char graph[3][3] = {
    //     {1, 1, 1},
    //     {4, 5, 6},
    //     {7, 8, 9}
    // };
    // traditional 2d array traversal
    // for (int i=0; i<3; i++) {
    //     for (int j=0; j<3; j++) {
    //         printf("%d ", graph[i][j]);
    //     }
    //     printf("\n");
    // }

    // 2d pointer array traversal
    // unsigned char* tmp = *graph;
    // for (int i=0; i<3; i++) {
    //     for (int j=0; j<3; j++) {
    //         printf("%d ", *tmp + j);
    //     } 
    //     tmp += 3;
    //     printf("\n");
    // }    

}
void DisplayManager::setRefboard(unsigned char input_refboard[8][8]) {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            DisplayManager::refboard[i][j] = input_refboard[i][j];
        }
    }
}