#pragma once
#include "State.h"
#include "../Scenes/Scene.h"
#include "../Game Objects/TileMap.h"
#include "../Levels/pallet_town_data.h"
#include "../Entities/Entity.h"

class GameState :
    public State
{
private:
    Scene scene;

protected:

public:
    GameState(sf::RenderWindow* window, ResourceManager* resourceManager, 
        StateManager* stateManager, UIManager* uiManager, std::map<std::string, int>* supportedKeys);
    ~GameState();

    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);

    void checkForQuit();
    void updateKeyInput();
};

