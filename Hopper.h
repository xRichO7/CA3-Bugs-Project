#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(int id, int x, int y, int directionValue, int health, int hopLen);

    void move(int boardSize) override;
    bool isWayBlocked(int boardSize) const override;
};

#endif