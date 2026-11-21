#include <iostream>
#include <utility>
#include "functions.h"

int main()
{
    // variable declaration
    std::pair<const int, const int> boardSize{8, 8}; //.first is the Row size and .second the Col size
    std::pair<int, int> snakeHeadLocation{boardSize.first / 2, boardSize.second / 2};
    std::pair<int, int> appleLocation{appleLocationGenerator(boardSize)};
    char playerKey{}; // wasd input by player
    int playerScore{0};

    // Run the generator while the coordenates are the same as the snake head
    while (snakeHeadLocation.first == appleLocation.first && snakeHeadLocation.second == appleLocation.second)
    {
        appleLocation = appleLocationGenerator(boardSize);
    }

    drawBoard(boardSize, snakeHeadLocation, appleLocation, playerScore);
    bool isRunning{true};
    while (isRunning)
    {
        std::cout << "Pick your next move: " << '\n';
        std::cout << "w, a, s, d \n";
        std::cout << "Press 'q' to quit \n";
        std::cout << "select a key: ";
        std::cin >> playerKey;
        Movement playerMove{readMovement(playerKey)};
        std::cout << "--------------------------\n";
        if (playerMove == Movement::quit)
        {
            isRunning = !isRunning;
            std::cout << "GAME OVER\n";
        }
        else
        {
            // set the head in the new position selected by the player wasd key input
            setSnakeHead(snakeHeadLocation, playerMove);
            // delimit the walls where the snake can move
            if (snakeHeadLocation.second >= boardSize.second || snakeHeadLocation.first >= boardSize.first || snakeHeadLocation.second < 0 || snakeHeadLocation.first < 0)
            {
                isRunning = !isRunning;
                std::cout << "GAME OVER\n";
            }
            else
            {
                if (snakeHeadLocation.first == appleLocation.first && snakeHeadLocation.second == appleLocation.second)
                {
                    ++playerScore;
                    // this do while avoids the apple from being generated in the snake's head position
                    do
                    {
                        appleLocation = appleLocationGenerator(boardSize);
                    } while (snakeHeadLocation.first == appleLocation.first && snakeHeadLocation.second == appleLocation.second);
                }
                drawBoard(boardSize, snakeHeadLocation, appleLocation, playerScore);
            }
        }
    }
    return 0;
}