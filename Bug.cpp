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



