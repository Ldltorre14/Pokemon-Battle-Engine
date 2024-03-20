#include "RectButton.h"

using namespace UI;

RectButton::RectButton(const buttonState& state, const sf::Vector2f& buttonSize, const std::string& textString, sf::Font* font, const unsigned int& fontSize,
    const sf::Vector2f& pos, sf::Color color, sf::Texture* texture)
    : Button(state, new sf::RectangleShape()) {

    this->initButtonAttributes(textString, buttonSize, font, fontSize, pos, color, texture);
    std::cout << "BUTTON INITIALIZED\n";
    std::cout << "SIZE ARGUMENT: " << this->buttonSize.x << "x" << this->buttonSize.y << "\n";
    std::cout << "SIZE: " << this->getButtonSize().x << "x" << this->getButtonSize().y << "\n";
    
}

void RectButton::initButtonAttributes(const std::string& textString, const sf::Vector2f& buttonSize, sf::Font* font, const unsigned int& fontSize,
    const sf::Vector2f& pos, sf::Color color, sf::Texture* texture) {
    this->textString = textString;
    this->font = font;
    this->fontSize = fontSize;
    this->position = pos;
    this->buttonSize = buttonSize;
    this->color = color;
    if (texture != nullptr)
        this->texture = texture;
    
    this->rectShape = dynamic_cast<sf::RectangleShape*>(this->baseShape);
    this->rectShape->setPosition(this->position);
    this->rectShape->setFillColor(this->color);
    this->rectShape->setSize(this->buttonSize);

    this->text.setString(textString);
    this->text.setFont(*font);
    this->text.setCharacterSize(fontSize);
}

RectButton::~RectButton() {
    delete this->texture; // Only delete if texture was dynamically allocated
}

void RectButton::setTextAlignment(const textAlignment& align) {
    // Implement text alignment logic here
}

void UI::RectButton::setButtonSize(const sf::Vector2f& buttonSize)
{
    this->rectShape->setSize(buttonSize);
}

void UI::RectButton::setText(const std::string& stringText)
{
    this->text.setString(stringText);
}

void UI::RectButton::setText(const sf::Text& text)
{
    this->text = text;
}

void UI::RectButton::setTextPosition(const sf::Vector2f& pos)
{
    this->text.setPosition(pos);
}

void UI::RectButton::setButtonPosition(const sf::Vector2f& pos)
{
    this->baseShape->setPosition(pos);
}

void UI::RectButton::setBackgroundColor(const sf::Color& color)
{
    this->baseShape->setFillColor(color);
}

