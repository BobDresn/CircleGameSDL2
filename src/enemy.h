#pragma once
#include "Entity.h"

class Enemy : public Entity {
public:
    double mvelX;
    double mvelY;

    Enemy(double x, double y, double velX, double velY);
    void updatePosition(double velX, double velY, uint64_t tick);
};
