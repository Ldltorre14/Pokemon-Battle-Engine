#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <map>
#include "../UI Components/rectbutton.h"
#include "../Managers/resourcemanager.h"

class UIManager
{
private:
    std::map<std::string, std::map<std::string, UI::Button*>> buttons;
    ResourceManager& resourceManager; // Reference to ResourceManager at Game Class

    // Initialize buttons
    void initButtons();

public:
    UIManager();
    UIManager(ResourceManager& resourceManager ); // Pass ResourceManager by reference
    ~UIManager();

    void setButton(std::string category, std::string buttonKey, UI::Button* button);
    UI::Button* getButton(std::string category, std::string buttonKey);

    void update(const sf::Vector2f& cursor);
    void render(sf::RenderTarget* target);
};

#endif

