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
        tempboard[row][col] = refboard[8][8];
    }

    // render the board
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%c", tempboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}