#include <iostream>
#include "Puzzle.h"


int main()
{
    size_t g = 0;
    Puzzle* board = new Puzzle();
    board->printBoard();
    std::cout << board->checkWin();
    return 0;
}
