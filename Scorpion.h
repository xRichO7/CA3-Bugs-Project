#ifndef SCORPION_H
#define SCORPION_H

#include "Bug.h"

class Scorpion : public Bug {
public:
    Scorpion(int id, int x, int y, int directionValue, int health);
    void move(int boardSize) override;
    bool isWayBlocked(int boardSize) const override;
};

#endif