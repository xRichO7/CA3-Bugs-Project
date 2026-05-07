#include "Bug.h"

Bug::Bug(int bugId, int positionX, int positionY, int directionValue, int bugHealth) {
    this->id = bugId;
    this->position.first = positionX;
    this->position.second = positionY;
    this->direction = directionValue;
    this->health = bugHealth;
    this->alive = true;
    this->path.push_back(this->position);

}



int Bug::getId() const
 {
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
    this->position.first = positionX;
    this->position.second = positionY;
    this->path.push_back(this->position);
}

void Bug::setDirection(int directionValue) {
    direction = directionValue;
}

void Bug::setHealth(int bugHealth) {
    health = bugHealth;
}



void Bug::setAlive(bool isAliveFlag) 
{
    alive = isAliveFlag;
}