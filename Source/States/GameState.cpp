#include "GameState.h"

GameState::GameState(sf::RenderWindow* window,ResourceManager* resourceManager,StateManager* stateManager,std::map<std::string, int>* supportedKeys)
	:State(window, resourceManager,stateManager, supportedKeys)
{
}

GameState::~GameState()
{
}

void GameState::update(const float& dt)
{
	//std::cout << "Hello from GameState" << std::endl;
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	
}
