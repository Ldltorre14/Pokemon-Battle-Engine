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

#include "ResourceManager.h"


class State
{
private:
	

protected:
	sf::RenderWindow* window;
	ResourceManager* resourceManager;
	bool stateQuitStatus;

	//Cursor/View attributes
	sf::Vector2i mouseScreenPos;
	sf::Vector2i mouseWindowPos;
	sf::Vector2f mouseViewPos;

public:
	State(sf::RenderWindow* window, ResourceManager* resourceManager);
	virtual ~State();

	virtual bool getQuit();
	virtual void updateMousePos();

	virtual void update(const float& dt) = 0;

	virtual void render(sf::RenderTarget* target = NULL) = 0;

};


#endif
