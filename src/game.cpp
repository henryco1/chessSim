/*
game.cpp

cpp file for handling game logic
*/
#include "game.h"
#include <unordered_map>
#include <string>
#include <stdint.h>

void GameManager::setBoard(std::unordered_map<std::string, std::string> init_pieces) {
    /*
    pieces looks like this
    pieces = {
        wr1: a1,
        wk1: b1,
        ...
    }

    bitboard holds the position
    refboard identifies the pieces at each position
    */

    for (auto kv: init_pieces) {
        char color = kv.first[0];
        char type = kv.first[1];
        std::string position = kv.second;
        unsigned int file = position[0] - 'a';
        unsigned int rank = position[1] - '0' - 1;
        
        printf("color: %c, type: %c, position: %s, rank: %d, file: %d\n", 
            color, type, position.c_str(), rank, file);

        // here we can't just index for our piece position.
        // the bitpos formula generates the correct bit position based on the table in the 
        // documentation:  http://pages.cs.wisc.edu/~psilord/blog/data/chess-pages/rep.html
        unsigned int bitpos = 8 * (rank) + file;
        printf("bitpos: %d\n", bitpos);

        // fillout board positions
        uint64_t one = 1;
        bitboard &= ~(one << bitpos);
        bitboard |= (one << bitpos);

        refboard[rank][file] = type;
        // printf("refboard at %d, %d: %c\n", rank, file, type);
    }

    // uint64_t temp = bitboard;
    // for (int i=64; i>0; i--) {
    //     if (temp & 1) {
    //         printf("1");
    //     }
    //     else {
    //         printf("0");
    //     }
    //     temp >>= 1;
    // }
    // printf("\n");

    display.bitboard = bitboard;
    display.setRefboard(refboard);
}