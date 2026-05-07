#ifndef BUG_H
#define BUG_H

#include <utility>
#include <list>
#include <string>

class Bug {
protected:
    int id; // bug id number
    std::pair<int, int> position; // x,y coordinates on the board
    int direction; // 0 = up, 1 = right, 2 = down, 3 = left
    int health; // current health points
    bool alive; // isd the bug still alive or no
    std::list<std::pair<int, int>> path; // visited positions history

public:
    Bug(int bugId, int positionX, int positionY, int directionValue, int bugHealth);
    
    virtual ~Bug() = default;
    
    virtual void move(int boardSize) = 0; // move the bug on the board
    virtual bool isWayBlocked(int boardSize) const; // check if there is an obstacle or edge
    
    int getId() const;
    std::pair<int, int> getPosition() const;
    int getDirection() const;
    int getHealth() const;
    bool isAlive() const;
    const std::list<std::pair<int, int>>& getPath() const;
    
    // helper function to get readable direction string
    std::string getDirectionString() const;
    
    virtual std::string toString() const;
    
    void setPosition(int positionX, int positionY);
    void setDirection(int directionValue);
    void setHealth(int bugHealth);
    void setAlive(bool isAliveFlag);
};

#endif