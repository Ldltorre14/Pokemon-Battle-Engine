#ifndef GAME_H
#define GAME_H

#include "Managers/StateManager.h"
#include "Managers/ResourceManager.h"
#include "Managers/UIManager.h"
#include "States/MainMenuState.h"
#include "States/GameState.h"


//main class for handling the game/application

class Game
{
private:
	sf::RenderWindow* window;
	StateManager* stateManager;
	ResourceManager resourceManager;
	UIManager uiManager;

	std::map<std::string, int> supportedKeys;

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
	void initSupportedKeys();
	


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