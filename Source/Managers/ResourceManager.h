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
	std::map<std::string, sf::Font*> fonts;

	void initTextures();
	void initTileSets();
	void initEntitiesSpritesheets();
	void initHUDTextures();
	void initFonts();

public:
	ResourceManager();
	~ResourceManager();

	void setFont(std::string fontName, std::string font);
	void setTexture(std::string categoryKey, std::string textureKey, std::string texture);

	sf::Texture* getTexture(const std::string& categoryKey,const std::string& textureKey);
	sf::Font* getFont(const std::string& fontKey);
	void getAvailableFonts();
	void getSize() { std::cout << "Fonts Size:" << this->fonts.size() << "\n"; };
	void test() { std::cout << "RESOURCE MANAGER TEST\n"; };

	
};


#endif

