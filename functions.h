#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int setHeadRow( int headRowCurr, char playerMove);
int setHeadCol( int headColCurr, char playerMove);
char getCellChar( int cellCol, int cellRow, int headCol, int headRow);
void drawBoard(const int boardRowSize, const int boardColSize, int headRowCurr, int headColCurr);
void appleGeneratorRow(const int boardRowSize);
void appleGeneratorCol(const int boardColSize);


#endif