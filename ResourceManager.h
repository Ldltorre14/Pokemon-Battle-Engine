#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H


#include <iostream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class ResourceManager
{
private:
	std::map<std::string, std::map<std::string, sf::Texture*>> textures;


	void initTextures();

public:
	ResourceManager();
	~ResourceManager();

	sf::Texture* getTexture(const std::string key);

};


#endif

