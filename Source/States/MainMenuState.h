#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"
#include "../UI Components/RectButton.h"



class MainMenuState :
    public State
{
private:
    sf::Text mousePosText;
    sf::Texture* bgTexture;
    sf::RectangleShape background;
    UI::Button* button;

    void init();
    void initKeybinds();
    void initBackground();
    void initMousePosText();
    

public:
    MainMenuState(sf::RenderWindow* window, ResourceManager* resourceManager, StateManager* stateManager, std::map<std::string, int>* supportedKeys);
    ~MainMenuState();

    void initButton();
    void checkForQuit();
    void renderBackground(sf::RenderTarget* target);
    void renderMousePosText(sf::RenderTarget* target);
    void updateKeyInput();
    void updateButtonInput();
    void updateInput();
    void update(const float& dt) override;
    void render(sf::RenderTarget* target) override;

};


#endif

