#include "Button.h"




UI::Button::Button(const sf::Text& text, sf::Font* font, unsigned fontSize, sf::Texture* btnTexture, sf::Color* txtColor)
{
	this->text = text;
	this->font = font;
	this->fontSize = fontSize;
	this->btnTexture = btnTexture;
	this->txtColor = txtColor;
}

UI::Button::~Button(){
	
}

void UI::Button::setState(buttonState btn_state)
{
	this->state = btn_state;
}
