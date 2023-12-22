#include "Game.h"

void Game::initWindow()
{

	try {

		std::ifstream file("Config/window_config.ini");
		
		if(file.is_open()){
			std::getline(file, this->title);
			file >> this->resolution.width >> this->resolution.height;
			file >> this->fullscreen;
			file >> this->verticalSyncEnabled;
			file >> this->framerate;
			file >> this->antialiasing;
			file >> this->bpp;
		}
		
		file.close();

		std::cout << this->title << std::endl
			<< "Resolution: " << this->resolution.width << "--" << this->resolution.height << std::endl
			<< "Fullscreen: " << this->fullscreen << std::endl
			<< "Vertical Sync: " << this->verticalSyncEnabled << std::endl
			<< "Framerate: " << this->framerate << std::endl
			<< "Antialiasing: " << this->antialiasing << std::endl
			<< "BitsPerPixel: " << this->bpp << std::endl;

	}
	catch (std::exception& e) {
		this->title = "Pokemon Clash";
		this->resolution = sf::VideoMode(1280, 720);
		this->fullscreen = false;
		this->verticalSyncEnabled = false;
		this->framerate = 60.f;
		this->antialiasing = 0;
		this->bpp = 32;
	}


	this->resolution.bitsPerPixel = this->bpp;
	this->settings.antialiasingLevel = this->antialiasing;



	if(this->fullscreen)
		this->window = new sf::RenderWindow(this->resolution, this->title, sf::Style::Fullscreen, this->settings);
	else {
		this->window = new sf::RenderWindow(this->resolution, this->title, sf::Style::Titlebar | sf::Style::Close, this->settings);
	}

	this->window->setFramerateLimit(this->framerate);
	this->window->setVerticalSyncEnabled(this->verticalSyncEnabled);
	
}

void Game::initStateManager()
{
	this->stateManager = new StateManager(new MainMenuState(this->window, &this->resourceManager));
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
