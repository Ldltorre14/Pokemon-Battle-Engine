#include "rectbutton.h"

using namespace UI;

// CONSTRUCTOR | DESTRUCTOR

RectButton::RectButton(const buttonState& state, const UI::textAlignment& alignment, const sf::Vector2f& buttonSize, const std::string& textString, sf::Font* font, const unsigned int& fontSize,
    const sf::Vector2f& buttonPosition, sf::Color color, sf::Texture* texture)
    : Button(state, alignment, new sf::RectangleShape()) {

    this->initButtonAttributes(textString, buttonSize, font, fontSize, buttonPosition, color, texture);
    this->handleTextAlignment();
    
}


RectButton::~RectButton() {
    if(this->texture != nullptr)
        delete this->texture; // Only delete if texture was dynamically allocated
}

//<<<<<<<<<<   PRIVATE FUNCTIONS   >>>>>>>>>>


//INITIALIZERS
void RectButton::initButtonAttributes(const std::string& textString, const sf::Vector2f& buttonSize, sf::Font* font, const unsigned int& fontSize,
    const sf::Vector2f& buttonPosition, sf::Color color, sf::Texture* texture) {
    this->textString = textString;
    if(font != nullptr)
        this->font = font;
    this->fontSize = fontSize;
    this->buttonPosition = buttonPosition;
    this->buttonSize = buttonSize;
    this->color = color;
    if (texture != nullptr)
        this->texture = texture;
    
    this->rectShape = dynamic_cast<sf::RectangleShape*>(this->baseShape);
    this->rectShape->setPosition(this->buttonPosition);
    this->rectShape->setFillColor(this->color);
    this->rectShape->setSize(this->buttonSize);

    this->text.setString(textString);
    if(this->font != nullptr)
        this->text.setFont(*this->font);
    this->text.setCharacterSize(fontSize);
}



//TEXT ALIGNMENT FUNCTIONS

void UI::RectButton::alignTextTopLeft()
{
    this->textPosition.x = this->baseShape->getGlobalBounds().left;
    this->textPosition.y = this->baseShape->getGlobalBounds().top;
    this->text.setPosition(this->textPosition);
}

void UI::RectButton::alignTextTopCenter()
{
    this->textPosition.x = this->buttonPosition.x + ((this->baseShape->getGlobalBounds().width / 2) - (this->text.getGlobalBounds().width / 2));
    this->textPosition.y = this->baseShape->getGlobalBounds().top;
    this->text.setPosition(this->textPosition);
}

void UI::RectButton::alignTextTopRight()
{
    this->textPosition.x = (this->baseShape->getGlobalBounds().left + this->baseShape->getGlobalBounds().width - this->text.getGlobalBounds().width);
    this->textPosition.y = this->baseShape->getGlobalBounds().top;
    this->text.setPosition(this->textPosition);
}

void UI::RectButton::alignTextLeft()
{
    this->textPosition.x = this->baseShape->getGlobalBounds().left;
    this->textPosition.y = this->buttonPosition.y + ((this->baseShape->getGlobalBounds().height / 2) - (this->text.getGlobalBounds().height / 2));
    this->text.setPosition(this->textPosition);
}

void UI::RectButton::alignTextCenter()
{
    this->textPosition.x = this->buttonPosition.x + ((this->buttonSize.x / 2) - (this->text.getGlobalBounds().width / 2));
    this->textPosition.y = this->buttonPosition.y + ((this->buttonSize.y / 2) - (this->text.getGlobalBounds().height / 2));
    this->text.setPosition(this->textPosition);
}

void UI::RectButton::alignTextRight()
{
    this->textPosition.x = ((this->baseShape->getGlobalBounds().left + this->baseShape->getGlobalBounds().width - this->text.getGlobalBounds().width));
    this->textPosition.y = this->buttonPosition.y + ((this->baseShape->getGlobalBounds().height / 2) - (this->text.getGlobalBounds().height / 2));
    this->text.setPosition(this->textPosition);
}

void UI::RectButton::alignTextBottomLeft()
{
    this->textPosition.x = this->baseShape->getGlobalBounds().left;
    this->textPosition.y = (this->baseShape->getGlobalBounds().top + this->baseShape->getGlobalBounds().height - this->text.getGlobalBounds().height);
    this->text.setPosition(this->textPosition);
}

void UI::RectButton::alignTextBottomCenter()
{
    this->textPosition.x = this->buttonPosition.x + ((this->baseShape->getGlobalBounds().width / 2) - (this->text.getGlobalBounds().width / 2));
    this->textPosition.y = (this->baseShape->getGlobalBounds().top + this->baseShape->getGlobalBounds().height - this->text.getGlobalBounds().height);
    this->text.setPosition(this->textPosition);
}

void UI::RectButton::alignTextBottomRight()
{
    this->textPosition.x = (this->baseShape->getGlobalBounds().left + this->baseShape->getGlobalBounds().width - this->text.getGlobalBounds().width);
    this->textPosition.y = (this->baseShape->getGlobalBounds().top + this->baseShape->getGlobalBounds().height - this->text.getGlobalBounds().height);
    this->text.setPosition(this->textPosition);
}


//<<<<<<<<<<   PUBLIC FUNCTIONS   >>>>>>>>>>

//Set the text alignment state
void RectButton::setTextAlignment(const textAlignment& align) {
    
}

//Set the size of the rect shape which represents the overall base of the button
void UI::RectButton::setButtonSize(const sf::Vector2f& buttonSize)
{
    this->rectShape->setSize(buttonSize);
}

//Simple setter for the sf::Text attribute
void UI::RectButton::setText(const std::string& stringText)
{
    this->text.setString(stringText);
}

//Overloaded setter for the sf::Text attribute
void UI::RectButton::setText(const sf::Text& text)
{
    this->text = text;
}

//Simple setter for the text position 
void UI::RectButton::setTextPosition(const sf::Vector2f& pos)
{
    this->text.setPosition(pos);
}

//Simple setter for the shape/button position
void UI::RectButton::setButtonPosition(const sf::Vector2f& pos)
{
    this->baseShape->setPosition(pos);
}

//Simple setter for the Button color
void UI::RectButton::setBackgroundColor(const sf::Color& color)
{
    this->baseShape->setFillColor(color);
}

//Function for handling the text alignment based on the the alignment state

void UI::RectButton::handleTextAlignment()
{
    switch (this->alignment) {
    case UI::textAlignment::TOP_LEFT:
        this->alignTextTopLeft();
        break;
    case UI::textAlignment::TOP_CENTER:
        this->alignTextTopCenter();
        break;
    case UI::textAlignment::TOP_RIGHT:
        this->alignTextTopRight();
        break;
    case UI::textAlignment::LEFT:
        this->alignTextLeft();
        break;
    case UI::textAlignment::CENTER:
        this->alignTextCenter();
        break;
    case UI::textAlignment::RIGHT:
        this->alignTextRight();
        break;
    case UI::textAlignment::BOTTOM_LEFT:
        this->alignTextBottomLeft();
        break;
    case UI::textAlignment::BOTTOM_CENTER:
        this->alignTextBottomCenter();
        break;
    case UI::textAlignment::BOTTOM_RIGHT:
        this->alignTextBottomRight();
        break;
    default:
        break;
    }
}

void UI::RectButton::renderText(sf::RenderTarget* target)
{
    target->draw(this->text);
  
}

