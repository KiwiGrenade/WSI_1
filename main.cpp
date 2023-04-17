#include <iostream>
#include <utility>
#include <vector>
#include <unordered_set>
#include <deque>
#include "Puzzle.h"


bool visitNode(Puzzle &puzzle,
               std::unordered_set<std::string> &visited,
               std::unordered_set<std::string> &closedList,
               std::vector<unsigned short> &groupWithBlank,
               std::vector<unsigned short> &group) {
    std::string puzzleHashWithBlank = puzzle.hash(groupWithBlank);

    //if visited contains puzzleHashWithBlank
    if (visited.contains(puzzleHashWithBlank)) {
        return false;
    }

    visited.insert(puzzleHashWithBlank);

    std::string groupHash = puzzle.hash(group);
    if (!closedList.contains(groupHash)){
        auto itr = closedList.find(groupHash);
        *itr = puzzle.;
    }

        return false;
}

void buildPatternDB(std::vector<unsigned short> group)
{
    Puzzle puzzle = new Puzzle(false);
    std::vector<unsigned short> groupWithBlank = std::move(group);
    groupWithBlank.push_back(0);

    // Permutations of groupWithBlank already visited
    std::unordered_set<std::string> visited;
    // Permutation of group tile locations with min move count so far
    std::unordered_set<std::string> closedList;
    // Next permutations to visit
    std::deque<std::pair<Puzzle, std::pair<unsigned short, unsigned short>>> openList;
    // puzzle, prior direction
    openList.emplace_back(puzzle,std::pair<unsigned short, unsigned short>(0, 0));

    while(!openList.empty()) {
        Puzzle current = openList[0].first;
        std::pair<unsigned short, unsigned short> prevMove = openList[0].second;

        openList.pop_front();

        if(!visitNode(current,
                      visited,
                      closedList,
                      groupWithBlank,
                      group)) {

        }
    }
}


int main()
{
    Puzzle* board = new Puzzle(true);

    board->printBoard();
    std::cout << board->isSolvable();

    return 0;
}
