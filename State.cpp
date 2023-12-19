#include "State.h"

State::State(sf::RenderWindow* window)
{
	this->window = window;
	this->stateQuitStatus = false;
}

State::~State()
{
	
}

bool State::getQuit()
{
	return this->stateQuitStatus;
	
}

void State::updateCursorPos()
{
	this->mouseScreenPos = sf::Mouse::getPosition();
	this->mouseWindowPos = sf::Mouse::getPosition(*this->window);
	this->mouseViewPos = this->window->mapPixelToCoords(this->mouseWindowPos);
	
}


