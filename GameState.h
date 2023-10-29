#pragma once
#include "State.h"
class GameState :
    public State
{
private:

protected:

public:
    GameState(sf::RenderWindow* window);
    ~GameState();

    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);


};

