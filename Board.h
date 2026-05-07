#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <string>

#include "Bug.h"

class Board
{
private:
    std::vector<std::unique_ptr<Bug>> bugs;
    int boardSize;

public:
    Board();

    void loadBugs(const std::string& filename);

    void displayAllBugs() const;

    Bug* findBug(int id) const;

    void tapBoard();

    std::vector<std::unique_ptr<Bug>>& getBugs();
};

#endif