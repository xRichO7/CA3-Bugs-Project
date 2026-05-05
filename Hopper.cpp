#include "Hopper.h"
#include <cstdlib>

Hopper::Hopper(int id, int x, int y, int directionValue, int health, int hopLen)
    : Bug(id, x, y, directionValue, health), hopLength(hopLen) {}

void Hopper::move(int boardSize) {
    if (!alive) return;

    if (isWayBlocked(boardSize)) {
        do {
            direction = 1 + rand() % 4;
        } while (isWayBlocked(boardSize));
    }

    int dx = 0;
    int dy = 0;
    if (direction == 1) dy = -hopLength;
    else if (direction == 2) dx = hopLength;
    else if (direction == 3) dy = hopLength;
    else if (direction == 4) dx = -hopLength;

    int newX = position.first + dx;
    int newY = position.second + dy;

    if (newX < 0) newX = 0;
    else if (newX >= boardSize) newX = boardSize - 1;
    if (newY < 0) newY = 0;
    else if (newY >= boardSize) newY = boardSize - 1;

    setPosition(newX, newY);
}


#include "Hopper.h"
#include <cstdlib>

Hopper::Hopper(int id, int x, int y, int directionValue, int health, int hopLen)
    : Bug(id, x, y, directionValue, health), hopLength(hopLen) {}

void Hopper::move(int boardSize) {
    if (!alive) return;

    if (isWayBlocked(boardSize)) {
        do {
            direction = 1 + rand() % 4;
        } while (isWayBlocked(boardSize));
    }

    int dx = 0;
    int dy = 0;
    if (direction == 1) dy = -hopLength;
    else if (direction == 2) dx = hopLength;
    else if (direction == 3) dy = hopLength;
    else if (direction == 4) dx = -hopLength;

    int newX = position.first + dx;
    int newY = position.second + dy;

    if (newX < 0) newX = 0;
    else if (newX >= boardSize) newX = boardSize - 1;
    if (newY < 0) newY = 0;
    else if (newY >= boardSize) newY = boardSize - 1;

    setPosition(newX, newY);
}

bool Hopper::isWayBlocked(int boardSize) const {
    int x = position.first;
    int y = position.second;
    if (direction == 1 && y < hopLength) return true;
    if (direction == 2 && x >= boardSize - hopLength) return true;
    if (direction == 3 && y >= boardSize - hopLength) return true;
    if (direction == 4 && x < hopLength) return true;
    return false;
}
