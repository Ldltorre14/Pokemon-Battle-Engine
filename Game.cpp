#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(900, 700), "PokeShowdown");
}

void Game::initStateManager()
{
	this->stateManager = new StateManager(new MainMenuState(this->window));
}


Game::Game()
{
	this->initWindow();
	this->initStateManager();
	
}

Game::~Game()
{
	delete this->window;
	delete this->stateManager;
}

void Game::updateDeltaTime()
{
	this->dt = this->clock.restart().asSeconds();
}

void Game::update()
{
	
	this->stateManager->updateState(dt);
}

void Game::render()
{
	this->window->clear();
	if (!this->stateManager->noTasks()) {
		this->stateManager->renderState();
	}
	this->window->display();
}

void Game::mainloop()
{
	sf::Event event;
	while (this->window->isOpen()) {
		while (this->window->pollEvent(event)) {
			
			if (event.type == sf::Event::Closed) {
				this->window->close();
			}
			
			this->updateDeltaTime();
			this->update();
			this->render();
			
		}
	}
	
}

void Game::run()
{
	this->mainloop();
}
