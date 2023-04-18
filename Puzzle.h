//
// Created by Grim Reaper on 16.04.2023.
//

#ifndef L1_PUZZLE_H
#define L1_PUZZLE_H

enum direction {up = 0, down = 1, left = 2, right = 3};

class Puzzle {
private:
    unsigned short board[4][4]{};
    unsigned short x;
    unsigned short y;
    std::size_t count;
    void shuffle() noexcept;

public:
    Puzzle(bool shuffle);

    void printBoard() const noexcept;
    bool move(direction dir) noexcept;
    bool checkWin() noexcept;
    bool isSolvable() noexcept;
    std::string hash(std::vector<unsigned short> group) noexcept;
    size_t getCount() const noexcept;
    void setCount(size_t count) noexcept;
};


#endif //L1_PUZZLE_H
