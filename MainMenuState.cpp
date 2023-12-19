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
	//std::cout << "Hello from main menu" << std::endl;
	this->updateCursorPos();
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	sf::CircleShape circle(100);
	target->draw(circle);

	sf::Text mousePosText;
	std::stringstream mousePosTextStream;
	mousePosTextStream << this->mouseViewPos.x << this->mouseViewPos.y;

	mousePosText.setString(mousePosTextStream.str());
	target->draw(mousePosText);
	std::cout << this->mouseViewPos.x;

}
