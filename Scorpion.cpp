#include "Scorpion.h"
#include <cstdlib>

Scorpion::Scorpion(int id, int x, int y, int directionValue, int health)
    : Bug(id, x, y, directionValue, health) {}

bool Scorpion::isWayBlocked(int boardSize) const {
    // Scorpion moves in L-shape (knight move).
    // Direction determines the primary axis:
    // 1=North (primary dy=-2, dx=±1), 2=East (primary dx=2, dy=±1),
    // 3=South (primary dy=2, dx=±1), 4=West (primary dx=-2, dy=±1)
    // It's blocked if it can't make the full L-shaped move.
    int x = position.first;
    int y = position.second;

    if (direction == 1 && y < 2) return true;
    if (direction == 2 && x >= boardSize - 2) return true;
    if (direction == 3 && y >= boardSize - 2) return true;
    if (direction == 4 && x < 2) return true;

    return false;
}

void Scorpion::move(int boardSize) {
    if (!alive) return;

    // If way is blocked, pick a new random direction
    if (isWayBlocked(boardSize)) {
        do {
            direction = 1 + rand() % 4;
        } while (isWayBlocked(boardSize));
    }

    // Scorpion moves in L-shape: 2 squares in current direction, 1 square perpendicular
    int dx = 0, dy = 0;
    int side = (rand() % 2 == 0) ? 1 : -1;

    if (direction == 1) {
        dy = -2;
        dx = side;
    } else if (direction == 2) {
        dx = 2;
        dy = side;
    } else if (direction == 3) {
        dy = 2;
        dx = side;
    } else if (direction == 4) {
        dx = -2;
        dy = side;
    }

    int newX = position.first + dx;
    int newY = position.second + dy;

    if (newX < 0) newX = 0;
    else if (newX >= boardSize) newX = boardSize - 1;
    if (newY < 0) newY = 0;
    else if (newY >= boardSize) newY = boardSize - 1;

    setPosition(newX, newY);
}