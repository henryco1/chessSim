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
        char fileor = kv.first[0];
        char type = kv.first[1];
        std::string position = kv.second;
        unsigned int file = kv.second[0] - 'a';
        unsigned int rank = kv.second[1] - '0' - 1;
        
        printf("fileor: %c, type: %c, position: %s, rank: %d, file: %d\n", 
            fileor, type, position.c_str(), rank, file);

        // here we can't index chess board positions
        // i think we need to make a table here that references the correct board position
        // need a % mod multiplier probably
        // http://pages.cs.wisc.edu/~psilord/blog/data/chess-pages/rep.html
        unsigned int bitpos = rank+1 * file;
        printf("bitpos: %d\n", bitpos);

        // fillout board positions
        bitboard &= ~(1 << bitpos);
        bitboard |= (1 << bitpos);

        refboard[file][rank] = type;

        // printf("refboard at %d, %d: %c\n", rank, file, type);
    }

        uint64_t temp = bitboard;
        for (int i=0; i<64; i++) {
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