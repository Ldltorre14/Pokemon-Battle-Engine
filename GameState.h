#pragma once
#include "State.h"
class GameState :
    public State
{
private:

protected:

public:
    GameState(sf::RenderWindow* window,ResourceManager* resourceManager, std::map<std::string, int>* supportedKeys);
    ~GameState();

    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);


};

