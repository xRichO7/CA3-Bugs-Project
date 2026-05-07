#include "Board.h"
#include "../Bugs/Crawler.h"
#include "../Bugs/Hopper.h"
#include "../Bugs/Scorpion.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <map>

Board::Board() : boardSize(10) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Board::loadBugs(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: could not open " << filename << std::endl;
        return;
    }

    bugs.clear();
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ';')) {
            tokens.push_back(token);
        }

        if (tokens.empty()) continue;

        char type = tokens[0][0];
        int id = std::stoi(tokens[1]);
        int x = std::stoi(tokens[2]);
        int y = std::stoi(tokens[3]);
        int dir = std::stoi(tokens[4]);
        int health = std::stoi(tokens[5]);

        if (type == 'C') {
            bugs.push_back(std::make_unique<Crawler>(id, x, y, dir, health));
        } else if (type == 'H') {
            int hopLen = std::stoi(tokens[6]);
            bugs.push_back(std::make_unique<Hopper>(id, x, y, dir, health, hopLen));
        } else if (type == 'S') {
            bugs.push_back(std::make_unique<Scorpion>(id, x, y, dir, health));
        }
    }

    file.close();
    std::cout << "Loaded " << bugs.size() << " bugs onto the board.\n";
}

void Board::load(const std::string& filename) {
    loadBugs(filename);
}

void Board::displayAllBugs() const {
    if (bugs.empty()) {
        std::cout << "No bugs on the board. Load bugs first.\n";
        return;
    }

    for (const auto& bug : bugs) {
        std::string type = "Bug";
        if (dynamic_cast<const Crawler*>(bug.get()))
            type = "Crawler";
        else if (dynamic_cast<const Hopper*>(bug.get()))
            type = "Hopper";
        else if (dynamic_cast<const Scorpion*>(bug.get()))
            type = "Scorpion";

        std::cout << bug->getId() << " " << type
                  << " (" << bug->getPosition().first << "," << bug->getPosition().second << ")"
                  << " " << bug->getHealth() << " " << bug->getDirectionString()
                  << " " << (bug->isAlive() ? "Alive" : "Dead")
                  << std::endl;
    }
}

std::string Board::findBug(int id) const {
    for (const auto& bug : bugs) {
        if (bug->getId() == id) {
            return bug->toString();
        }
    }
    return "Bug " + std::to_string(id) + " not found";
}

void Board::tapBoard() {
    if (bugs.empty()) {
        std::cout << "No bugs to move. Load bugs first.\n";
        return;
    }

    int freezeIndex = -1;
    int aliveCount = getAliveBugCount();
    if (aliveCount > 1) {
        freezeIndex = std::rand() % aliveCount;
    }

    int aliveSeen = 0;
    for (auto& bug : bugs) {
        if (!bug->isAlive()) continue;
        if (aliveSeen == freezeIndex) {
            std::cout << "Bug " << bug->getId() << " is frozen this turn.\n";
            aliveSeen++;
            continue;
        }
        bug->move(boardSize);
        aliveSeen++;
    }

    fightAndEat();
    std::cout << "Board tapped! Bugs moved.\n";
}

void Board::tap() {
    tapBoard();
}

void Board::displayLifeHistory() const {
    if (bugs.empty()) {
        std::cout << "No bugs on the board.\n";
        return;
    }

    for (const auto& bug : bugs) {
        std::cout << bug->getId();

        if (dynamic_cast<const Crawler*>(bug.get()))
            std::cout << " Crawler";
        else if (dynamic_cast<const Hopper*>(bug.get()))
            std::cout << " Hopper";
        else if (dynamic_cast<const Scorpion*>(bug.get()))
            std::cout << " Scorpion";
        else
            std::cout << " Bug";

        std::cout << " Path: ";

        const auto& path = bug->getPath();
        bool first = true;
        for (const auto& pos : path) {
            if (!first) std::cout << ",";
            std::cout << "(" << pos.first << "," << pos.second << ")";
            first = false;
        }

        bool eaten = false;
        if (!bug->isAlive()) {
            for (const auto& other : bugs) {
                if (other->getId() != bug->getId() && other->isAlive() &&
                    other->getPosition() == bug->getPosition()) {
                    std::cout << " Eaten by " << other->getId();
                    eaten = true;
                    break;
                }
            }
            if (!eaten) std::cout << " Dead";
        } else {
            std::cout << " Alive!";
        }
        std::cout << std::endl;
    }
}

void Board::displayAllCells() const {
    if (bugs.empty()) {
        std::cout << "No bugs on the board.\n";
        return;
    }

    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            std::cout << "(" << x << "," << y << "): ";

            std::vector<std::string> cellBugs;
            for (const auto& bug : bugs) {
                if (!bug->isAlive()) continue;
                auto pos = bug->getPosition();
                if (pos.first == x && pos.second == y) {
                    std::string type = "Bug";
                    if (dynamic_cast<const Crawler*>(bug.get()))
                        type = "Crawler";
                    else if (dynamic_cast<const Hopper*>(bug.get()))
                        type = "Hopper";
                    else if (dynamic_cast<const Scorpion*>(bug.get()))
                        type = "Scorpion";
                    cellBugs.push_back(type + " " + std::to_string(bug->getId()));
                }
            }

            if (cellBugs.empty()) {
                std::cout << "empty";
            } else {
                for (size_t i = 0; i < cellBugs.size(); i++) {
                    if (i > 0) std::cout << ", ";
                    std::cout << cellBugs[i];
                }
            }
            std::cout << std::endl;
        }
    }
}

int Board::getAliveBugCount() const {
    int count = 0;
    for (const auto& bug : bugs) {
        if (bug->isAlive()) count++;
    }
    return count;
}

Bug* Board::getLastAliveBug() const {
    Bug* last = nullptr;
    for (const auto& bug : bugs) {
        if (bug->isAlive()) {
            if (last != nullptr) return nullptr;
            last = bug.get();
        }
    }
    return last;
}

void Board::writeLifeHistoryToFile() const {
    auto now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    std::stringstream ss;
    ss << "bugs_life_history_"
       << std::put_time(&tm, "%Y%m%d_%H%M%S")
       << ".out";
    std::string filename = ss.str();

    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: could not create " << filename << std::endl;
        return;
    }

    for (const auto& bug : bugs) {
        file << bug->getId();

        if (dynamic_cast<const Crawler*>(bug.get()))
            file << " Crawler";
        else if (dynamic_cast<const Hopper*>(bug.get()))
            file << " Hopper";
        else if (dynamic_cast<const Scorpion*>(bug.get()))
            file << " Scorpion";
        else
            file << " Bug";

        file << " Path: ";

        const auto& path = bug->getPath();
        bool first = true;
        for (const auto& pos : path) {
            if (!first) file << ",";
            file << "(" << pos.first << "," << pos.second << ")";
            first = false;
        }

        bool eaten = false;
        if (!bug->isAlive()) {
            for (const auto& other : bugs) {
                if (other->getId() != bug->getId() && other->isAlive() &&
                    other->getPosition() == bug->getPosition()) {
                    file << " Eaten by " << other->getId();
                    eaten = true;
                    break;
                }
            }
            if (!eaten) file << " Dead";
        } else {
            file << " Alive!";
        }
        file << std::endl;
    }

    file.close();
    std::cout << "Life history written to " << filename << std::endl;
}

void Board::fightAndEat() {
    std::map<std::pair<int,int>, std::vector<Bug*>> cellMap;

    for (const auto& bug : bugs) {
        if (!bug->isAlive()) continue;
        cellMap[bug->getPosition()].push_back(bug.get());
    }

    for (auto& entry : cellMap) {
        auto& cellBugs = entry.second;
        if (cellBugs.size() < 2) continue;

        std::cout << "Fight at (" << entry.first.first << "," << entry.first.second
                  << ") between " << cellBugs.size() << " bugs!\n";

        for (size_t i = 0; i < cellBugs.size() - 1; i += 2) {
            Bug* a = cellBugs[i];
            Bug* b = cellBugs[i + 1];

            if (!a->isAlive() || !b->isAlive()) continue;

            std::cout << "  Bug " << a->getId() << " vs Bug " << b->getId() << ":\n";

            for (int round = 0; round < 3; round++) {
                if (!a->isAlive() || !b->isAlive()) break;

                int dmgA = std::rand() % 6;
                int dmgB = std::rand() % 6;

                a->setHealth(a->getHealth() - dmgA);
                b->setHealth(b->getHealth() - dmgB);

                std::cout << "    Round " << (round + 1)
                          << ": Bug " << a->getId() << " takes " << dmgA
                          << " damage (HP: " << a->getHealth() << "), "
                          << "Bug " << b->getId() << " takes " << dmgB
                          << " damage (HP: " << b->getHealth() << ")\n";

                if (a->getHealth() <= 0) {
                    a->setAlive(false);
                    std::cout << "    Bug " << a->getId() << " has been defeated!\n";
                }
                if (b->getHealth() <= 0) {
                    b->setAlive(false);
                    std::cout << "    Bug " << b->getId() << " has been defeated!\n";
                }
            }
        }
    }
}