#pragma once
#include "state.h"
#include "../Scenes/scene.h"

class GameState :
    public State
{
private:
    Scene scene;

protected:

public:
    GameState(sf::RenderWindow* window, ResourceManager* resourceManager, StateManager* stateManager, UIManager* uiManager, std::map<std::string, int>* supportedKeys);
    ~GameState();

    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);

    void checkForQuit();
    void updateKeyInput();
};

