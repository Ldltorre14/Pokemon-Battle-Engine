#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "../Game Components/tilemap.h"


class Level
{
private:
	std::vector<TileMap*> tileMaps;
	TileMap* currentTileMap;

	
public:
	Level(std::vector<TileMap*> tileMaps);
	~Level();

	void addTileMap(TileMap* tileMap);
	void setCurrentTileMap(TileMap* currentTileMap);

	TileMap* getTileMapById(std::string mapId);
	TileMap* getCurrentTileMap();
	
	void update();
	void render(sf::RenderTarget* target);


	

};

#endif
