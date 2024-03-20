#include "Button.h"




UI::Button::Button(const buttonState& state, sf::Shape* shape)
{
	this->state = state;
	this->baseShape = shape;
	
}

UI::Button::~Button(){
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


bool UI::Button::isOnButton(const sf::Event& event)
{
	// Convert event.mouseButton.x and event.mouseButton.y to float
	float mouseX = static_cast<float>(event.mouseButton.x);
	float mouseY = static_cast<float>(event.mouseButton.y);

	// Check if the mouse position is within the bounds of the button
	if (this->baseShape->getGlobalBounds().contains(sf::Vector2f(mouseX, mouseY))) {
		return true;
	}
	return false;
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
	if (this->isOnButton(cursor)) {
		this->setState(UI::buttonState::HOVER_BTN);
	}
	else {
		this->setState(UI::buttonState::IDLE_BTN);
	}
}

void UI::Button::handleState(const sf::Event& event)
{
	if (this->getState() == UI::buttonState::HOVER_BTN) {
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			if (this->isOnButton(event)) {
				this->setState(UI::buttonState::ACTIVE_BTN);
				//handle Button Click
			}
		}
	}
}

void UI::Button::update(const sf::Vector2f& cursor, const sf::Event& event)
{
	this->updateState(cursor);
	this->handleState(event);
}

void UI::Button::render(sf::RenderTarget* target)
{
	target->draw(*this->baseShape);
}



