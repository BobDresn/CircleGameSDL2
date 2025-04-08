#include "Enemy.h"

Enemy::Enemy(double x, double y, double velX, double velY) : mx(x), my(y), mvelX(velX), mvelY(velY) {}

void Enemy::updatePosition(double velX, double velY, uint64_t tick) {
    uint64_t current_tick = tick - last_tick;
    y *= current_tick;
    x *= current_tick;

    double magnitude;
}
