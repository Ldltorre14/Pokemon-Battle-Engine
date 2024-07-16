#include "Button.h"




UI::Button::Button(const buttonState& state, const UI::textAlignment& alignment = UI::textAlignment::CENTER, sf::Shape* shape = nullptr)
{
	this->state = state;
	this->alignment = alignment;
	this->baseShape = shape;
}

UI::Button::~Button(){
	if(this->baseShape != nullptr)
		delete this->baseShape;
}

void UI::Button::setState(const buttonState& btn_state)
{
	this->state = btn_state;
}

UI::buttonState UI::Button::getState()
{
	return this->state;
}



bool UI::Button::isOnButton(const sf::Vector2f& cursor)
{
	if (this->baseShape->getGlobalBounds().contains(cursor)) {
		return true;
	}
	return false;
}


void UI::Button::updateState(const sf::Vector2f& cursor)
{
	this->setState(UI::buttonState::IDLE_BTN);

	if (this->isOnButton(cursor)) {
		
		this->setState(UI::buttonState::HOVER_BTN);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			
			this->setState(UI::buttonState::ACTIVE_BTN);
			
		}
	}
}

void UI::Button::handleState()
{
	switch (this->state) {
		case UI::buttonState::IDLE_BTN:
			this->baseShape->setFillColor(sf::Color::Green);
			break;
		case UI::buttonState::HOVER_BTN:
			this->baseShape->setFillColor(sf::Color::Blue);
			break;
		case UI::buttonState::ACTIVE_BTN:
			this->baseShape->setFillColor(sf::Color::Red);
			break;
		default:
			break;
	}
}

void UI::Button::update(const sf::Vector2f& cursor)
{
	this->updateState(cursor);
	this->handleState();
	this->handleTextAlignment();
}

void UI::Button::render(sf::RenderTarget* target)
{
	if (target) {
		target->draw(*this->baseShape);
		this->renderText(target);
	}
	else {
		std::cout << "CANNOT RENDER BUTTON\n";
	}
}



