/*
game.cpp

cpp file for handling game logic
*/
#include "game.h"
#include <unordered_map>
#include <string>

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
        unsigned int row = kv.second[0] - 'a';
        unsigned int col = kv.second[1] - '0';
        
        // printf("color: %c, type: %c, position: %s, row: %d, col: %d\n", 
            // color, type, position.c_str(), row, col);

        unsigned int bitpos = row * col;
        // printf("bitpos: %d\n", bitpos);

        // fillout board positions
        GameManager::bitboard &= bitpos;
        GameManager::bitboard |= bitpos;

        GameManager::refboard[row][col] = type;
    }

    GameManager::display.setBitboard(GameManager::bitboard);
    GameManager::display.setRefboard(GameManager::refboard);
}

