//
// Created by Grim Reaper on 16.04.2023.
//
#include <iostream>
#include <unordered_set>
#include <random>
#include "Puzzle.h"

void Puzzle::printBoard() const noexcept {
    for (auto & i : board) {
        for (auto j: i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

Puzzle::Puzzle() {
    x = 3;
    y = 3;
    g = 0;

    size_t counter = 1;
    for (auto & i : board) {
        for (auto& j: i) {
            if(counter == 16)
            {
                counter = 0;
            }
            j = counter;
            counter++;
        }
    }
    shuffle();
}

void Puzzle::shuffle() noexcept {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(0, 3);
    for (int i = 0; i < 1000; ++i) {
        move(direction(distribution(generator)));
    }
}

bool Puzzle::move(direction dir) noexcept{
    switch (dir) {
        case up:
            //can't move up if you're in the last row
            if(y != 3){
                std::swap(board[y][x], board[y+1][x]);
                y++;
                g++;
                return true;
            }
            break;
        case down:
            //can't move down if you're in the first row
            if(y != 0){
                std::swap(board[y][x], board[y-1][x]);
                y--;
                g++;
                return true;
            }
            break;
        case left:
            //can't move left if you're in the first column
            if(x != 3){
                std::swap(board[y][x], board[y][x+1]);
                x++;
                g++;
                return true;
            }
            break;
        case right:
            //can't move right if you're in the last column
            if(x != 0){
                std::swap(board[y][x], board[y][x-1]);
                x--;
                g++;
                return true;
            }
            break;
    }
    return false;
}

void Puzzle::setBoard(short val[4][4]) noexcept {
    std::unordered_set<short> set;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(val[i][j] > 15) {
                std::cout << "SetBoardError: inserted value is too big!" << std::endl;
                return;
            }
            set.insert(val[i][j]);
        }
    }
    if(set.size() == 16){
        memcpy(this->board, val, sizeof(this->board));
    }
    else{
        std::cout << "SetBoardError: inserted values aren't unique!" << std::endl;
    }

}

size_t Puzzle::getG() const noexcept {
    return g;
}

bool Puzzle::checkWin() noexcept {
    size_t counter = 1;
    for (auto & i : board) {
        for (auto& j: i) {
            if(counter == 16)
            {
                counter = 0;
            }
            if(j != counter)
            {
                return false;
            }
            counter++;
        }
    }
    return true;
}
