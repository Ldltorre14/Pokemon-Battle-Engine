#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"
class MainMenuState :
    public State
{
private:
    

public:
    MainMenuState(sf::RenderWindow* window);
    ~MainMenuState();

    void update(const float& dt) override;
    void render(sf::RenderTarget* target) override;

};


#endif

