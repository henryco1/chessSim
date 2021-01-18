/*
input.h

Header file for the input manager
*/
#ifndef INPUT_H
#define INPUT_H
#include <unordered_map>
#include <string>

/*
The input manager models chess pieces with a hash map where the key is the piece and the value is the position
*/
class InputManager 
{
    /*
    It is overkill to have a class for handling a map but I might want to expand input functionality later
    */
    public:
        void setInputFromMap(std::unordered_map<std::string, std::string> user_piece_input);
        std::unordered_map<std::string, std::string> getPieces() { return init_pieces; };
    private:
        std::unordered_map<std::string, std::string> init_pieces = {
            {"wr1", "a1"},
            {"wk1", "b1"},
            {"wb1", "c1"},
            {"wq", "d1"},
            {"wk", "e1"},
            {"wb2", "f1"},
            {"wk2", "g1"},
            {"wr2", "h1"},
            {"wp1", "a2"},
            {"wp2", "b2"},
            {"wp3", "c2"},
            {"wp4", "d2"},
            {"wp5", "e2"},
            {"wp6", "f2"},
            {"wp7", "g2"},
            {"wp8", "h2"},

            {"br1", "a8"},
            {"bk1", "b8"},
            {"bb1", "c8"},
            {"bq", "d8"},
            {"bk", "e8"},
            {"bb2", "f8"},
            {"bk2", "g8"},
            {"br2", "h8"},
            {"bp1", "a7"},
            {"bp2", "b7"},
            {"bp3", "c7"},
            {"bp4", "d7"},
            {"bp5", "e7"},
            {"bp6", "f7"},
            {"bp7", "g7"},
            {"bp8", "h7"}
        };
};

#endif 