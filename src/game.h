#include "entity.h"

class Game {
public:
    Game();
    ~Game();

    bool _isPaused;
    void HandlePause();

    //TODO: IMPLEMENT TIMER FISPLAY
    //TODO: IMPLEMENT IMGUI FOR PAUSED MENU

    void RunGameLoop();
    
    Entity enemies[50];
    Entity player;
    void UpdateEnemies();
    void CheckCollisions();
};