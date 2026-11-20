#include "functions.h"
#include <iostream>
#include <random>

static std::mt19937 mt{ std::random_device{}() };

void setHeadRow( int& headRowCurr, char playerMove){
    if (playerMove == 'w')
        --headRowCurr;
    else if (playerMove == 's')
        ++headRowCurr;
}
void setHeadCol( int& headColCurr, char playerMove){
    if (playerMove == 'a')
        --headColCurr;
    else if (playerMove == 'd')
        ++headColCurr;
}

int appleGeneratorRow(const int boardRowSize){
    std::uniform_int_distribution generatorRow{0, boardRowSize  - 1};
    return generatorRow(mt);
}

int appleGeneratorCol(const int boardColSize){
    std::uniform_int_distribution generatorCol{0, boardColSize  - 1};
    return generatorCol(mt);
}

char getCellChar(int cellCol, int cellRow, int headCol, int headRow, int appleCol, int appleRow){    
    if(cellCol == headCol && cellRow == headRow)
        return 'O';
    else if(cellCol == appleCol && cellRow == appleRow)
        return 'A';
    else
        return '.';
}
void drawBoard(const int boardRowSize, const int boardColSize, int headRowCurr, int headColCurr, int appleCol, int appleRow){
        for(int row{}; row < boardRowSize; ++row){
        for(int col{}; col < boardColSize; ++col){
            std::cout << getCellChar(col, row, headColCurr, headRowCurr, appleCol, appleRow);
        }
        std::cout << '\n';
    }
}

