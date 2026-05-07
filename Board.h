#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <string>

#include "Bug.h"

class Board
{
private:
    // list of bugs owned by the board
    std::vector<std::unique_ptr<Bug>> bugs;
    
    // the board is a 10x10 grid
    int boardSize;

public:
    // constructor sets up the board
    Board();

    // load bugs from the file into the board
    void loadBugs(const std::string& filename);

    // print all bug details to the screen
    void displayAllBugs() const;

    // find a bug using its id, return nullptr if not found
    Bug* findBug(int id) const;

    // tap the board and move the bugs
    void tapBoard();

    // allow external code to inspect the bug list if needed
    std::vector<std::unique_ptr<Bug>>& getBugs();
};

#endif