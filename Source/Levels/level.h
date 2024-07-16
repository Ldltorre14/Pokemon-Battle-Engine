#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "../Game Objects/TileMap.h"


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


	void loadAllTileMaps();
	void loadTileMapById(std::string id);
	void loadCurrentTileMap();
	void loadAll();

	
	void unloadAllTileMaps();
	void unloadTileMapById(std::string id);
	void unloadCurrentTileMap();
	void unloadAll();

	void updateTileMapState();
	void handleTileMapState();

	void update();

	void renderTileMaps(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);


	

};

#endif
