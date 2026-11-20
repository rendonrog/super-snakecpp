#include <iostream>
#include "functions.h"

#if 1
int main(){
    const int boardRowSize{8};
    const int boardColSize{8};
    int headRowCurr{2};
    int headColCurr{2};
    char playerMove{};
    int appleRow = appleGeneratorRow(boardRowSize);
    int appleCol = appleGeneratorCol(boardColSize);

    drawBoard(boardRowSize, boardColSize, headRowCurr, headColCurr, appleCol, appleRow);
    bool isRunning{true};
    while (isRunning)
    {
        std::cout << "Pick your next move: " << '\n';
        std::cout << "w, a, s, d \n";
        std::cout << "Press 'q' to quit \n";
        std::cout << "select a key: ";
        std::cin >> playerMove;
        if(playerMove == 'q'){
            isRunning = !isRunning;
            std::cout << "GAME OVER\n";
        }
        else{
            setHeadRow(headRowCurr, playerMove);
            setHeadCol(headColCurr, playerMove);
            
            if(headColCurr >= boardColSize || headRowCurr >= boardRowSize || headColCurr < 0 || headRowCurr < 0){
                isRunning = !isRunning;
                std::cout << "GAME OVER\n";
            }
            else{
                if(headColCurr == appleCol && headRowCurr == appleRow){
                appleCol = appleGeneratorCol(boardColSize);
                appleRow = appleGeneratorRow(boardRowSize);
            }
            drawBoard(boardRowSize, boardColSize, headRowCurr, headColCurr, appleCol, appleRow);
        }
    }
}   
return 0;
}
#endif
