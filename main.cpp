#include <iostream>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include "Puzzle.h"


bool visitNode(Puzzle &puzzle,
               std::unordered_set<std::string> &visited,
               std::unordered_map<std::string, std::size_t> &closedList, // database
               std::vector<unsigned short> &groupWithBlank,
               std::vector<unsigned short> &group) {
    std::string puzzleHashWithBlank = puzzle.hash(groupWithBlank);

    //if visited contains puzzleHashWithBlank
    if (visited.contains(puzzleHashWithBlank)) {
        return false;
    }

    visited.insert(puzzleHashWithBlank);

    std::string groupHash = puzzle.hash(group);
    // If the permutation (it's hash) hasn't been reached before
    // assign the number of moves it took to reach it as key in the database
    if (!closedList.contains(groupHash))    {
        closedList[groupHash] = puzzle.getCount();
    }
    // If the number of moves it took to reach the current permutation
    // is less than it's key in DB - update it!
    else if (closedList[groupHash] > puzzle.getCount()){
        closedList[groupHash] = puzzle.getCount();
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
