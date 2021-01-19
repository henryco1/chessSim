/*
display.h

Header file for the display manager
*/
#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>

/*
Display manager handles the processing of game state into a visualization
*/
class DisplayManager 
{
    /*
    Game state is modeled by two separate data structures:
        1. The position of pieces on the board are modeled by a bitboard, which is a 
            64-bit data structure. A bitboard allows for quick access to positional
            properties of the board through bit manipulation techniques
        2. A drawback of the bitboard is that each bit can only be 2 states. So we 
            need some other structure in order to identify the piece at each bit position.
            We don't really need  chess piece class objects if we only need to 
            display, so we use chars to hold info at each position.
    Together, the bitboard and 2d char array allow fast positional operations and provide 
    information about the type of piece at each position and its owner. 
    */
    public:
        void showGraphicBoard(); 
        void setBoard(unsigned long long bitboard);

        unsigned long long getBitboard() { return bitboard; };
        // here we return a pointer to an array of unsigned chars
        // a 2d array decays to a pointer pointing to the first element of the array
        // the rule is that array names decay into pointers
        // for example, an array decays into a pointer to its first element
        unsigned char (*getRefboard())[8] { return refboard; };

        void setBitboard(unsigned long long input_bitboard) { bitboard = input_bitboard; };
        void setRefboard(unsigned char (*input_refboard)[8]) { (*refboard)[8] = (*input_refboard)[8]; };
    private:
        unsigned long long bitboard = 0;
        unsigned char refboard[8][8];
        unsigned char gfxboard[8][8]; 

        void parseBitboardToGraphic();
        void parseRefboardToGraphic();

};

#endif 