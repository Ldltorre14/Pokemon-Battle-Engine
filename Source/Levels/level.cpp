#include "level.h"

Level::Level(std::vector<TileMap*> tileMaps)
{
	this->tileMaps = tileMaps;
}

Level::~Level()
{
	for (auto& tileMap : this->tileMaps) {
		delete tileMap;
	}
}

void Level::addTileMap(TileMap* tileMap)
{
	this->tileMaps.push_back(tileMap);
}

void Level::setCurrentTileMap(TileMap* currentTileMap)
{
	this->currentTileMap = currentTileMap;
}

TileMap* Level::getTileMapById(std::string mapId) {
	for (const auto& tileMap : this->tileMaps) {
		if (tileMap->getMapId() == mapId) {
			return tileMap;
		}
	}
}

TileMap* Level::getCurrentTileMap()
{
	return this->currentTileMap;
}

void Level::update()
{
	
}

void Level::render(sf::RenderTarget* target)
{
	for (auto tilemap : this->tileMaps) {
		if (tilemap->isActive()) {
			tilemap->render(target);
		}
	}
	
}



