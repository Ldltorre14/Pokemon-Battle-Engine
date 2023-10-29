#ifndef GAME_H
#define GAME_H

#include "StateManager.h"
#include "MainMenuState.h"
#include "GameState.h"

//main class for handling the game/application

class Game
{
private:
	sf::RenderWindow* window;
	StateManager* stateManager;

	std::string title;
	sf::VideoMode resolution;
	sf::ContextSettings settings;
	bool fullscreen;
	bool verticalSyncEnabled;
	float framerate;
	unsigned antialiasing;
	unsigned bpp;




	sf::Clock clock;
	float dt;
	
	

	void initWindow();
	void initStateManager();


public:
	Game();
	~Game();
	
	
	void updateDeltaTime();
	void update();
	void render();
	void mainloop();
	void run();
};



#endif