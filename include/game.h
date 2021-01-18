/*
game.h

Header file for the game manager
*/
#ifndef GAME_H
#define GAME_H
#include <unordered_map>
#include <string>
#include "display.h"

/*
The game manager is the source of truth for the current game state of the board
It parses the input from the user and generates the current game state.
*/
class GameManager 
{
    /*
    The game manager can handle rules enforcement (WIP), graphics, and external input. 
    */
    public:
        void setBoard(std::unordered_map<std::string, std::string> pieces);

        unsigned long long getBitboard() { return bitboard; };
        // here we return a pointer to an array of unsigned chars
        // a 2d array decays to a pointer pointing to the first element of the array
        // the rule is that array names decay into pointers
        // for example, an array decays into a pointer to its first element
        unsigned char (*getRefBoard())[8] { return refboard; };
        void showBoard() { display.showGraphicBoard(); };
    private:
        unsigned long long bitboard = 0;
        unsigned char refboard[8][8];
        DisplayManager display = DisplayManager();

};

#endif 