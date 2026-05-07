#ifndef BUG_H
#define BUG_H

#include <utility>
#include <list>
#include <string>

class Bug {
protected:
    int id;
    std::pair<int, int> position;
    int direction;
    int health;
    bool alive;
    std::list<std::pair<int, int>> path;

public:
    Bug(int bugId, int positionX, int positionY, int directionValue, int bugHealth);
    
    virtual ~Bug() = default;
    
    virtual void move(int boardSize) = 0;
    virtual bool isWayBlocked(int boardSize) const;
    
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