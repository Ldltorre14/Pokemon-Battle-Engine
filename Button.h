#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


enum buttonState {
	IDLE_BTN = 0,
	HOVER_BTN = 1,
	ACTIVE_BTN = 2
};

class Button
{
private:
	sf::RectangleShape rect;
	sf::Text text;
	unsigned fontSize;
	
	//These will point to the ResourceManager to get the texture desired, so we can save memory instead of creating many sf::Texture objects
	sf::Texture* btnTexture;
	sf::Color* txtColor;

public:
	Button();
	~Button();
};


#endif

