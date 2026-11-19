#include <iostream>
#include "functions.h"

#if 0
int main(){
    const int boardRowSize{5};
    const int boardColSize{5};
    int headRowCurr{2};
    int headColCurr{2};
    char playerMove{};

    drawBoard(boardRowSize, boardColSize, headRowCurr, headColCurr);
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
            headRowCurr = setHeadRow(headRowCurr, playerMove);
            headColCurr = setHeadCol(headColCurr, playerMove);
            drawBoard(boardRowSize, boardColSize, headRowCurr, headColCurr);
        }
    }
return 0;
}
#endif

int main(){
    const int boardRowSize{5};
    const int boardColSize{5};

    appleGeneratorRow(boardRowSize);
    appleGeneratorCol(boardColSize);

    
    return 0;
}