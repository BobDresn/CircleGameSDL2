#include "window.h"
#include "window.cpp"
#include "entity.h"
#include "entity.cpp"

int main() {
    Window win("Circle Game", 800, 600);
    Entity player(400, 300);
    while(!win.IsClosed()) {
        //Update player position
        win.PollEvents(&player);

        //Clear window
        SDL_RenderClear(win._renderer);
        SDL_SetRenderDrawColor(win._renderer, 85, 85, 85, 255); //Gray
        //Update renderer with new player draw coords
        player.drawEntity(win._renderer);
        //Redraw player
        SDL_RenderPresent(win._renderer);
    }
    return 1;
}
