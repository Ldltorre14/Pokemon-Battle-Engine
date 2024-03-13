#include "State.h"

State::State(sf::RenderWindow* window, ResourceManager* resourceManager, StateManager* stateManager, std::map<std::string, int>* supportedKeys)
{
	this->window = window;
	this->resourceManager = resourceManager;
	this->stateManager = stateManager;
	this->supportedKeys = supportedKeys;
	this->stateQuitStatus = false;
}

State::~State()
{
	
}

bool State::getQuit()
{
	return this->stateQuitStatus;
	
}

void State::updateMousePos()
{
	this->mouseScreenPos = sf::Mouse::getPosition();
	this->mouseWindowPos = sf::Mouse::getPosition(*this->window);
	this->mouseViewPos = this->window->mapPixelToCoords(this->mouseWindowPos);
	
}





