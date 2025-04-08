#pragma once 
#include <SDL2/SDL.h>

#define SPEED 1
#define RADIUS 10

class Entity {
public: 
    uint64_t last_tick;
    double mx;
    double my;

    Entity(double x, double y);

    void updatePosition(double x, double y, uint64_t tick);

    inline double getX() { return mx; };
    inline double getY() { return my; };
};
