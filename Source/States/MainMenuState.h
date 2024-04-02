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

    void init();
    void initKeybinds();
    void initBackground();
    void initMousePosText();
    

public:
    MainMenuState(sf::RenderWindow* window, ResourceManager* resourceManager, StateManager* stateManager, UIManager* uiManager, std::map<std::string, int>* supportedKeys);
    ~MainMenuState();

    
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

