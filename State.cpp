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


