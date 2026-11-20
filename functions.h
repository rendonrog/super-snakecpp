#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void setHeadRow(int& headRowCurr, char playerMove);
void setHeadCol(int& headColCurr, char playerMove);
int appleGeneratorRow(const int boardRowSize);
int appleGeneratorCol(const int boardColSize);
char getCellChar(int cellCol, int cellRow, int headCol, int headRow, int appleCol, int appleRow);
void drawBoard(const int boardRowSize, const int boardColSize, int headRowCurr, int headColCurr, int appleCol, int appleRow);

#endif