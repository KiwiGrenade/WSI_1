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
    size_t g;
    void shuffle() noexcept;
public:
    Puzzle();
    void printBoard() const noexcept;
    bool move(direction dir) noexcept;
    void setBoard(short val[4][4]) noexcept;
    bool checkWin() noexcept;
    size_t getG() const noexcept;
    size_t evalH() noexcept;
    size_t evalF() noexcept;
};


#endif //L1_PUZZLE_H
