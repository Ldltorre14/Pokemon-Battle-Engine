#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window) 
	: State(window) 
{
	
	
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::update(const float& dt)
{
	std::cout << "HELLO" << std::endl;
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	sf::CircleShape circle(100);
	target->draw(circle);

}
