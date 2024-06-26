#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Types/types.h"

class TileMap
{
private:
	std::string mapId;
	TileMapState mapState;
	int tileSize;
	std::vector<std::vector<int>> logicGrid;
	std::vector<std::vector<sf::Sprite*>> tileGrid;

public:
	TileMap(std::string mapId, TileMapState mapState, int tileSize, 
		std::vector<std::vector<int>> logicGrid, std::vector<std::vector<sf::Sprite*>> tileGrid);
	~TileMap();

	void setMapId(std::string mapId);
	void setMapState(TileMapState& mapState);
	void setTileSize(int tileSize);
	void setLogicGrid(std::vector<std::vector<int>> logicGrid);
	void setTileGrid(std::vector<std::vector<sf::Sprite*>> tileGrid);

	const std::string& getMapId();
	const TileMapState& getMapState();
	const int& getTileSize();
	const std::vector<std::vector<int>>& getLogicGrid();
	const std::vector<std::vector<sf::Sprite*>>& getTileGrid();

	bool isActive();
	void load();
	void unload();
	void render(sf::RenderTarget* target);

};

#endif
