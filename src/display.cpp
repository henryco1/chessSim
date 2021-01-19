/*
display.cpp

Cpp file for the display manager
*/
#include "display.h"
#include <string>

void DisplayManager::showGraphicBoard() 
{
    /*
    The board is modeled by two data structures which are
        1. the bitboard, which holds positional data
        2. the refbaord, which tells us what piece is at each position.
    */

    unsigned long long bitboard = DisplayManager::getBitboard();
    unsigned char (*refboard)[8] = DisplayManager::getRefboard();

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%c", (*refboard)[j]);
        }
        printf("\n");
    }

    unsigned char tempboard[8][8];
    int row = 0;
    int col = 0;
    while (bitboard) 
    {
        if (col % 8 == 0) 
        {
            row++;
            col = 0;
        }
        else 
        {
            col++;
        }
        // get the piece position
        unsigned char curr = bitboard & 1;
        bitboard >>= 1;          

        // if nothing as at the position, continue
        if (!curr) continue;

        // get the type of piece
        tempboard[row][col] = **refboard + row + col;
        // printf("%c\n," *refboard[row] + col);
        // printf("%c\n," refboard[row][col]);
        // tempboard[row][col] = curr;
    }

    // render the board
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%c", *tempboard[i] + j);
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

// void DisplayManager::setBoard() {
    // DisplayManager::bitboard = 
// }