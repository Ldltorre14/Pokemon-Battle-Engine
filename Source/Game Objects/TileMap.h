#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Types/types.h"
#include "../Types/tiles.h"
#include "../Types/consts.h"
#include "../Utils/enum_utils.h"

class TileMap
{
private:
	std::string mapId;
	TileMapState mapState;
	std::vector<std::vector<int>> logicGrid;
	std::vector<std::vector<sf::Sprite*>> tileGrid;

public:
	TileMap();
	TileMap(std::string mapId, TileMapState mapState, 
		std::vector<std::vector<int>> logicGrid, std::vector<std::vector<sf::Sprite*>> tileGrid);
	~TileMap();

	void setMapId(std::string mapId);
	void setMapState(TileMapState mapState);
	template <typename EnumType>
	void setLogicTile(int x, int y, EnumType logicTile);
	void setTile(int x, int y, sf::Sprite* tile);
	void setLogicGrid(std::vector<std::vector<int>> logicGrid);
	void setTileGrid(std::vector<std::vector<sf::Sprite*>> tileGrid);

	const std::string& getMapId();
	const TileMapState& getMapState();
	const std::vector<std::vector<int>>& getLogicGrid();
	const std::vector<std::vector<sf::Sprite*>>& getTileGrid();

	bool isTileGridEmpty();
	bool isLogicGridEmpty();
	bool checkSameGridsDimensions();
	bool isActive();
	bool isLoaded();
	bool isRendered();

	void resizeTileGrid();
	void load();
	void unload();
	void render(sf::RenderTarget* target);

};

#endif
