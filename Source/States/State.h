#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <stack>
#include <fstream>
#include <memory>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../Managers/ResourceManager.h"
#include "../Managers/StateManager.h"


class State
{
private:
	

protected:
	sf::RenderWindow* window;
	ResourceManager* resourceManager;
	StateManager* stateManager;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool stateQuitStatus;

	//Cursor/View attributes
	sf::Vector2i mouseScreenPos;
	sf::Vector2i mouseWindowPos;
	sf::Vector2f mouseViewPos;

public:
	State(sf::RenderWindow* window, ResourceManager* resourceManager, StateManager* stateManager, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	virtual void checkForQuit() = 0;
	virtual bool getQuit();
	virtual void updateMousePos();
	virtual void updateKeyInput() = 0;

	virtual void update(const float& dt) = 0;

	virtual void render(sf::RenderTarget* target = NULL) = 0;

};


#endif
