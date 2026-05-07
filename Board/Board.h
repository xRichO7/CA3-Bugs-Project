#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <string>
#include "../Bugs/Bug.h"

class Board
{
private:
    std::vector<std::unique_ptr<Bug>> bugs;
    int boardSize;

    void fightAndEat();

public:
    Board();

    void loadBugs(const std::string& filename);
    void load(const std::string& filename);

    void displayAllBugs() const;

    std::string findBug(int id) const;

    void tapBoard();
    void tap();

    void displayLifeHistory() const;
    void displayAllCells() const;

    int getAliveBugCount() const;
    Bug* getLastAliveBug() const;
    void writeLifeHistoryToFile() const;
};

#endif