#include "functions.h"
#include <iostream>
#include <random>

int setHeadRow( int headRowCurr, char playerMove){
    if (playerMove == 'w')
        return --headRowCurr;
    else if (playerMove == 's')
        return ++headRowCurr;
    else
        return headRowCurr;
}
int setHeadCol( int headColCurr, char playerMove){
    if (playerMove == 'a')
        return --headColCurr;
    else if (playerMove == 'd')
        return ++headColCurr;
    else
        return headColCurr;
}
char getCellChar( int cellCol, int cellRow, int headCol, int headRow){
    if(cellCol == headCol && cellRow == headRow)
        return 'O';
    else
        return '.';
}
void drawBoard(const int boardRowSize, const int boardColSize, int headRowCurr, int headColCurr){
    for(int row{}; row < boardRowSize; ++row){
        for(int col{}; col < boardColSize; ++col){
            std::cout << getCellChar(col, row, headColCurr, headRowCurr);
        }
        std::cout << '\n';
    }
}

void appleGeneratorRow(const int boardRowSize){
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution generatorRow{0, boardRowSize  - 1};
    std::cout << generatorRow(mt) << '\n';
}

void appleGeneratorCol(const int boardColSize){
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution generatorCol{0, boardColSize  - 1};
    std::cout << generatorCol(mt) << '\n';
}