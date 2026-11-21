#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <utility>
#include <random>

using PairInt = std::pair <int, int>;

static std::mt19937 mt{ std::random_device{}() };

enum class Movement{
    up,
    down,
    left,
    right,
    quit,
    none,
};

enum class CellChar{
    snakeHead,
    apple,
    board,
};

char toChar(CellChar cell);
Movement readMovement(char key);
void setSnakeHead(PairInt& snakeHeadLocation, Movement playerMove);
std::pair<int, int> appleLocationGenerator(PairInt boardSize);
CellChar getCellCharacter(PairInt cell, PairInt snakeHeadLocation, PairInt appleLocation);
void drawBoard(PairInt boardSize, PairInt snakeHeadLocation, PairInt appleLocation, int& playerScore);

#endif