//
// Created by Grim Reaper on 16.04.2023.
//

#ifndef L1_PUZZLE_H
#define L1_PUZZLE_H

enum direction {up = 0, down = 1, left = 2, right = 3};

class Puzzle {
private:
    short board[4][4]{};
    short x;
    short y;
    void shuffle() noexcept;
public:
    Puzzle();
    void printBoard() const noexcept;
    bool move(direction dir) noexcept;
    bool checkWin() noexcept;
};


#endif //L1_PUZZLE_H
