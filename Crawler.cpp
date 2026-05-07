#include "Crawler.h"
#include <cstdlib>

Crawler::Crawler(int id, int x, int y, int directionValue, int health)
    : Bug(id, x, y, directionValue, health) {}

bool Crawler::isWayBlocked(int boardSize) const 
{
    int x = position.first;
    int y = position.second;

    if (direction == 1 && y == 0) return true; //north
    if (direction == 2 && x == boardSize - 1) return true; //wast
    if (direction == 3 && y == boardSize - 1) return true; //south
    if (direction == 4 && x == 0) return true; //west

    return false;
}

void Crawler::move(int boardSize) {
    if (!alive) return;

    if (isWayBlocked(boardSize)) {
        do {
            direction = 1 + rand() % 4;
        } while (isWayBlocked(boardSize));
    }

    int dx = 0, dy = 0;

    if (direction == 1) dy = -1;
    else if (direction == 2) dx = 1;
    else if (direction == 3) dy = 1;
    else if (direction == 4) dx = -1;

    int newX = position.first + dx;
    int newY = position.second + dy;

    if (newX < 0) newX = 0;
    else if (newX >= boardSize) newX = boardSize - 1;

    if (newY < 0) newY = 0;
    else if (newY >= boardSize) newY = boardSize - 1;

    setPosition(newX, newY);
}