#include "window.h"
#include <iostream>

//Constructor
Window::Window(const std::string& title, int width, int height) : 
_title(title), _width(width), _height(height), wPressed(false), aPressed(false), sPressed(false), dPressed(false)
{
    if(!init()) {
        _closed = true;
    }
}

//Initializer
bool Window::init() {
    //Initializes SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL Could not be initialized!\n";
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 0;
    }

    //Initializes window
    _window = SDL_CreateWindow(
        _title.c_str(), 
        SDL_WINDOWPOS_CENTERED, //X
        SDL_WINDOWPOS_CENTERED, //Y
        _width, 
        _height, 
        SDL_WINDOW_SHOWN
    );

    if(_window == nullptr) {
        std::cout << "Window could not be created\n";
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        return 0;
    }
    std::cout << "Window initialized successfully.\n";

    //Initializes renderer
    _renderer = SDL_CreateRenderer(
        _window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    std::cout << "Renderer initalized successfully.\n";

    return true;
}

void Window::PollEvents(Entity* player) {
    SDL_Event e;

    while(SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_QUIT:
                _closed = true;
                break;
            case SDL_KEYDOWN:
                switch(e.key.keysym.scancode) {
                    case SDL_SCANCODE_W:
                        wPressed = true;
                        break;
                    case SDL_SCANCODE_A:
                        aPressed = true;
                        break;
                    case SDL_SCANCODE_S:
                        sPressed = true;
                        break;
                    case SDL_SCANCODE_D:
                        dPressed = true;
                        break;
                    default: 
                        break;
                }
                break;
            case SDL_KEYUP:
                switch (e.key.keysym.scancode) {
                    case SDL_SCANCODE_W:
                        wPressed = false;
                        break;
                    case SDL_SCANCODE_A:
                        aPressed = false;
                        break;
                    case SDL_SCANCODE_S:
                        sPressed = false;
                        break;
                    case SDL_SCANCODE_D:
                        dPressed = false;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    double x, y = 0;
    if(wPressed) {
        y -= 1;
    } 
    if(sPressed) {
        y += 1;
    }
    if(aPressed){ 
        x -= 1;
    }
    if(dPressed) {
        x += 1;
    }
    player->updatePosition(x, y, SDL_GetTicks64());
}
