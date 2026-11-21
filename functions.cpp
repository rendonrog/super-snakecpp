#include "functions.h"
#include <iostream>
char toChar(CellChar cell){
    switch(cell){
        case CellChar::snakeHead: return 'O';
        case CellChar::apple:     return 'A';
        case CellChar::board:     return '.';
    }
    return '?';
}

Movement readMovement(char key){
    switch(key){
        case 'w': case 'W': return Movement::up;
        case 's': case 'S': return Movement::down;
        case 'a': case 'A': return Movement::left;
        case 'd': case 'D': return Movement::right;
        case 'q': case 'Q': return Movement::quit;
        default:            return Movement::none;

    }
}

void setSnakeHead(PairInt& snakeHeadLocation, Movement playerMove){
    if(playerMove == Movement::up){
        --snakeHeadLocation.first;
    }else if(playerMove == Movement::down){
        ++snakeHeadLocation.first;
    }else if(playerMove == Movement::left){
        --snakeHeadLocation.second;
    }else if(playerMove == Movement::right){
        ++snakeHeadLocation.second;
    }
}

std::pair<int, int> appleLocationGenerator(PairInt boardSize){
    std::uniform_int_distribution<int> appleRowGen{0, boardSize.first - 1};
    std::uniform_int_distribution<int> appleColGen{0, boardSize.second - 1};
    std::pair<int, int> appleGenerator{appleRowGen(mt), appleColGen(mt)};
    return appleGenerator;
}

CellChar getCellCharacter(PairInt cell, PairInt snakeHeadLocation, PairInt appleLocation){
    if(cell == snakeHeadLocation){
        return CellChar::snakeHead;
    }else if(cell == appleLocation){
        return CellChar::apple;
    }else{
        return CellChar::board;
    }
}

void drawBoard(PairInt boardSize, PairInt snakeHeadLocation, PairInt appleLocation, int& playerScore){
    std::cout << "PLAYER SCORE: " << playerScore << '\n';
    for(int row{}; row < boardSize.first; ++row){
        for(int col{}; col < boardSize.second; ++col){
            PairInt cell {row, col};
            std::cout << toChar(getCellCharacter(cell, snakeHeadLocation, appleLocation));
        }
        std::cout << '\n';
    }
}






