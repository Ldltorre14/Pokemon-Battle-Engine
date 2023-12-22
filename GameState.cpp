#include "GameState.h"

GameState::GameState(sf::RenderWindow* window,ResourceManager* resourceManager)
	:State(window, resourceManager)
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
