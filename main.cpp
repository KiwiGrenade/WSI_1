#include <iostream>
#include "Puzzle.h"



int main()
{
    Puzzle* board = new Puzzle();

    board->printBoard();
    std::cout << board->isSolvable();

    return 0;
}
