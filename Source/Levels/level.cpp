#include "Level.h"

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

//<<<<<<SETTERS>>>>>>>>>>
void Level::addTileMap(TileMap* tileMap)
{
	this->tileMaps.push_back(tileMap);
}

void Level::setCurrentTileMap(TileMap* currentTileMap)
{
	this->currentTileMap = currentTileMap;
}

//<<<<<<GETTERS>>>>>>>>>>>
TileMap* Level::getTileMapById(std::string mapId) {
	for (const auto& tileMap : this->tileMaps) {
		if (tileMap->getMapId() == mapId) {
			return tileMap;
		}
	}
	return nullptr;
}

TileMap* Level::getCurrentTileMap()
{
	return this->currentTileMap;
}


// LOADING METHODS (TILEMAPS, GAMEOBJECTS, NPC's)
void Level::loadAllTileMaps()
{
	for (auto& tileMap : this->tileMaps) {
		tileMap->load();
	}
}

void Level::loadTileMapById(std::string id)
{
	this->getTileMapById(id)->load();
}

void Level::loadCurrentTileMap()
{
	this->getCurrentTileMap()->load();
}

void Level::loadAll() {
	this->loadAllTileMaps();
}


//UNLOADING METHODS (TILEMAPS, GAMEOBJECTS, NPC's)
void Level::unloadTileMapById(std::string id)
{
	this->getTileMapById(id)->unload();
}

void Level::unloadAllTileMaps()
{
	for (auto& tileMap : this->tileMaps) {
		if (tileMap->getMapState() == TileMapState::ACTIVE ||
			tileMap->getMapState() == TileMapState::READY) {
			tileMap->unload();
		}
	}
}

void Level::unloadCurrentTileMap()
{
	this->getCurrentTileMap()->unload();
}

void Level::unloadAll()
{
	this->unloadAllTileMaps();
}


//UPDATE METHODS 
void Level::updateTileMapState()
{
	// Update Tiles animations or other dynamic
}

void Level::handleTileMapState()
{
	// Change tileMap state based on some conditions
}


void Level::update()
{
	// update TileMaps, NPC's, Game Objects etc
}



//RENDERING METHODS
void Level::renderTileMaps(sf::RenderTarget* target)
{
	for (auto tilemap : this->tileMaps) {
		if (tilemap->isActive()) {
			tilemap->render(target);
		}
	}
	
}

void Level::render(sf::RenderTarget* target)
{
	this->renderTileMaps(target);
}



