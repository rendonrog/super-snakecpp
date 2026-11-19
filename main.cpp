#include <iostream>

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

