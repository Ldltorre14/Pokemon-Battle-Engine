#ifndef SCENE_H
#define SCENE_H

#include "../UI Components/RectButton.h"
#include "../Managers/ResourceManager.h"
#include "../Utils/spritesheet_parsing.h"
#include "../Game Objects/TileMap.h"

class Scene {
private:
	UI::Button* button;
	sf::Texture* texture;
	sf::Sprite spritesheet;
	TileMap tileMap;
	ResourceManager* resourceManager;

protected:

public:
	Scene(ResourceManager* resourceManager);
	~Scene();
	void render(sf::RenderTarget* target);
};

#endif 

