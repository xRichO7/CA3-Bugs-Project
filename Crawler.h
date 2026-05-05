#ifndef CRAWLER_H
#define CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {
public:
    Crawler(int id, int x, int y, int directionValue, int health);
    void move(int boardSize) override;
    bool isWayBlocked(int boardSize) const override;
};

#endif

