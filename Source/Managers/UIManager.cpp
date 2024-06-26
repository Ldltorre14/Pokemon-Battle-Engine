#include "uimanager.h"

void UIManager::initButtons()
{
    this->buttons["MAINMENU"]["START_BUTTON"] = new UI::RectButton(UI::buttonState::IDLE_BTN, UI::textAlignment::CENTER, sf::Vector2f(100, 50),
        "START", this->resourceManager.getFont("Gen1_2"), 16, sf::Vector2f(550, 300), sf::Color::Green);

    this->buttons["MAINMENU"]["OPTIONS_BUTTON"] = new UI::RectButton(UI::buttonState::IDLE_BTN, UI::textAlignment::CENTER, sf::Vector2f(100, 50),
        "OPTIONS", this->resourceManager.getFont("Gen1_2"), 16, sf::Vector2f(400, 400), sf::Color::Green);

    this->buttons["MAINMENU"]["EXIT_BUTTON"] = new UI::RectButton(UI::buttonState::IDLE_BTN, UI::textAlignment::CENTER, sf::Vector2f(100, 50),
        "EXIT", this->resourceManager.getFont("Gen1_2"), 16, sf::Vector2f(700, 400), sf::Color::Green);
}

UIManager::UIManager() : resourceManager(*new ResourceManager())
{
    this->initButtons();
}

UIManager::UIManager(ResourceManager& resourceManager) : resourceManager(resourceManager)
{
    this->initButtons();
}

UIManager::~UIManager()
{
    for (auto& category : this->buttons) {
        for (auto& button : category.second) {
            delete button.second;
        }
    }
}

void UIManager::setButton(std::string category, std::string buttonKey, UI::Button* button)
{
    this->buttons[category][buttonKey] = button;
}

UI::Button* UIManager::getButton(std::string category, std::string buttonKey)
{
    return this->buttons[category][buttonKey];
}

void UIManager::update(const sf::Vector2f& cursor)
{
    for (auto category : this->buttons) {
        for (auto button : category.second) {
            button.second->update(cursor);
        }
    }
}

void UIManager::render(sf::RenderTarget* target)
{
    for (auto category : this->buttons) {
        for (auto button : category.second) {
            button.second->render(target);
        }
    }
}