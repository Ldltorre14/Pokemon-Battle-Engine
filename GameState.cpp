#include "GameState.h"

GameState::GameState(sf::RenderWindow* window,ResourceManager* resourceManager, std::map<std::string, int>* supportedKeys)
	:State(window, resourceManager, supportedKeys)
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
