#include "Bug.h"

Bug::Bug(int bugId, int positionX, int positionY, int directionValue, int bugHealth) {
    id = bugId;
    position.first = positionX;
    position.second = positionY;
    direction = directionValue;
    health = bugHealth;
    alive = true;
    path.push_back(position);
}

int Bug::getId() const {
    return id;
}

std::pair<int, int> Bug::getPosition() const {
    return position;
}

int Bug::getDirection() const {
    return direction;
}

int Bug::getHealth() const {
    return health;
}

bool Bug::isAlive() const {
    return alive;
}

const std::list<std::pair<int, int>>& Bug::getPath() const {
    return path;
}

void Bug::setPosition(int positionX, int positionY) {
    position.first = positionX;
    position.second = positionY;
    path.push_back(position);
}

void Bug::setDirection(int directionValue) {
    direction = directionValue;
}

void Bug::setHealth(int bugHealth) {
    health = bugHealth;
}

void Bug::setAlive(bool isAliveFlag) {
    alive = isAliveFlag;
}

bool Bug::isWayBlocked(int boardSize) const 
{
    int x = position.first;
    int y = position.second;

    if (direction == 1 && y == 0) return true;              // north
    if (direction == 2 && x == boardSize - 1) return true;  // east
    if (direction == 3 && y == boardSize - 1) return true;  // south
    if (direction == 4 && x == 0) return true;              // west

    return false;
}

std::string Bug::getDirectionString() const
{
    if (direction == 1) return "North";
    if (direction == 2) return "East";
    if (direction == 3) return "South";
    if (direction == 4) return "West";

    return "Unknown";
}

std::string Bug::toString() const
{
    std::string aliveStatus;

    if (alive)
        aliveStatus = "Yes";
    else
        aliveStatus = "No";

    std::string result;

    result = "Bug ID: " + std::to_string(id);
    result += " | Pos: (" + std::to_string(position.first) + "," + std::to_string(position.second) + ")";
    result += " | Dir: " + getDirectionString();
    result += " | Health: " + std::to_string(health);
    result += " | Alive: " + aliveStatus;

    return result;
}
