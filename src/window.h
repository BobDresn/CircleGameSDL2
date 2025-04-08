#pragma once

#include <string>
#include "entity.h"
#include <SDL.h>

class Window{
public: 
    std::string _title;
    int _width;
    int _height;

    bool _closed = false;

    bool wPressed = false;
    bool aPressed = false;
    bool sPressed = false;
    bool dPressed = false;

    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

public:
    Window(const std::string& title, int width, int height);

    inline bool IsClosed() {
        return _closed; 
    }

    void PollEvents(Entity* player);

private:
    bool init();
};