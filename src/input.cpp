/*
input.cpp

cpp file for thei nput manager
*/
#include "input.h"
#include <string>
#include <unordered_map>

void InputManager::setInputFromMap(std::unordered_map<std::string, std::string> user_piece_input) {
    InputManager::init_pieces = user_piece_input;
}