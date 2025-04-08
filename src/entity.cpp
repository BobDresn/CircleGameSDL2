#pragma once
#include "entity.h"

Entity::Entity(double x, double y) : mx(x), my(y) {}

void Entity::drawEntity(SDL_Renderer* renderer) {
   int mx = this->getX();
   int my = this->getY();
   const int32_t diameter = RADIUS * 2;

   int32_t x = RADIUS - 1;
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);
   SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, mx + x, my - y);
      SDL_RenderDrawPoint(renderer, mx + x, my + y);
      SDL_RenderDrawPoint(renderer, mx - x, my - y);
      SDL_RenderDrawPoint(renderer, mx - x, my + y);
      SDL_RenderDrawPoint(renderer, mx + y, my - x);
      SDL_RenderDrawPoint(renderer, mx + y, my + x);
      SDL_RenderDrawPoint(renderer, mx - y, my - x);
      SDL_RenderDrawPoint(renderer, mx - y, my + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}

void Entity::updatePosition(double x, double y, uint64_t tick) {
   //Update time since last tick
   uint64_t currentTick =  tick - last_tick;
   x *= currentTick;
   y *= currentTick;

   //Normalize
   double magnitude = sqrt((x * x) + (y * y));
   double magX = x / magnitude;
   double magY = y / magnitude;

   //Update space moved
   this->mx += magX * currentTick;
   this->my += magY * currentTick;
   this->last_tick = tick;
}

