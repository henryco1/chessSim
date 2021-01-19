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

        // here we can't index chess board positions
        // i think we need to make a table here that references the correct board position
        // need a % mod multiplier probably
        // http://pages.cs.wisc.edu/~psilord/blog/data/chess-pages/rep.html
        unsigned int bitpos = 8 * (rank) + file;
        printf("bitpos: %d\n", bitpos);

        // fillout board positions
        uint64_t one = 1;
        bitboard &= ~(one << bitpos);
        bitboard |= (one << bitpos);

        refboard[file][rank] = type;
        // printf("refboard at %d, %d: %c\n", rank, file, type);
        // break;
    }

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

    // display.bitboard = GameManager::bitboard;
    // printf("game bitboard: %llu\n", bitboard);
    display.bitboard += 1;
    display.setRefboard(refboard);
}