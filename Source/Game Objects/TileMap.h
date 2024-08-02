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
	int tileSizePx;
	int mapWidthPx;
	int mapHeightPx;
	sf::Vector2i gridSize;
	sf::Vector2i origin;
	sf::Texture* spritesheet;
	std::vector<std::vector<int>> logicGrid;
	std::vector<std::vector<sf::Sprite*>> tileGrid;


public:
	TileMap();
	TileMap(std::string mapId, TileMapState mapState, int tileSizePx, int mapWidthPx, int mapHeightPx,
		sf::Vector2i gridSize, sf::Vector2i origin, sf::Texture* spritesheet,
		std::vector<std::vector<int>> logicGrid, std::vector<std::vector<sf::Sprite*>> tileGrid);
	~TileMap();

	void setMapId(std::string mapId);
	void setMapState(TileMapState mapState);
	void setTileSizePx(int tileSizePx);
	void setMapWidthPx(int mapWidthPx);
	void setMapHeightPx(int mapHeightPx);
	void setGridSize(sf::Vector2i gridSize);
	void setGridSize(int rows, int cols);
	void setOrigin(sf::Vector2i originCoord);
	void setOrigin(int x, int y);
	void setSpritesheet(sf::Texture* spritesheet);
	template <typename EnumType>
	void setLogicTile(int x, int y, EnumType logicTile);
	void setTileTexture(int x, int y, sf::Texture* texture);
	void setTileSprite(int x, int y, sf::Sprite* tile);
	void setLogicGrid(std::vector<std::vector<int>> logicGrid);
	void setTileGrid(std::vector<std::vector<sf::Sprite*>> tileGrid);

	const std::string& getMapId();
	const TileMapState& getMapState();
	const int& getTileSizePx();
	const int& getMapWidthPx();
	const int& getMapHeightPx();
	const sf::Vector2i& getGridSize();
	const sf::Vector2i& getOrigin();
	const sf::Texture* getSpritesheet();
	template <typename EnumType>
	const EnumType& getLogicTile(int x, int y);
	const sf::Texture* getTileTexture(int x, int y);
	const sf::Sprite* getTileSprite(int x, int y);
	const std::vector<std::vector<int>>& getLogicGrid();
	const std::vector<std::vector<sf::Sprite*>>& getTileGrid();

	bool isTileGridEmpty();
	bool isLogicGridEmpty();
	bool areCoordsOutOfBounds(const int &x, const int &y);
	bool checkSameGridsDimensions();
	bool isActive();
	bool isLoaded();

	void resizeTileGrid();
	void load();
	void unload();
	void render(sf::RenderTarget* target);

};

#endif
