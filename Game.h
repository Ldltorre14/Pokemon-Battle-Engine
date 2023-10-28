#ifndef GAME_H
#define GAME_H

#include "StateManager.h"
#include "MainMenuState.h"

//main class for handling the game/application

class Game
{
private:
	sf::RenderWindow* window;
	StateManager* stateManager;

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