#include "tilemap.h"


//CONSTRUCTOR
TileMap::TileMap(std::string mapId, TileMapState mapState, int tileSize, 
	std::vector<std::vector<int>> logicGrid, std::vector<std::vector<sf::Sprite*>> tileGrid)
{
	this->mapId = mapId;
	this->mapState = mapState;
	this->tileSize = tileSize;
	this->logicGrid = logicGrid;
	this->tileGrid = tileGrid;
}

//DESTRUCTOR
TileMap::~TileMap()
{
	for (auto& row : this->tileGrid) {
		for (auto& tile : row) {
			delete tile;
		}
	}
}



//SETTERS
void TileMap::setMapId(std::string mapId)
{
	this->mapId = mapId;
}
void TileMap::setMapState(TileMapState& mapState)
{
	this->mapState = mapState;
}
void TileMap::setTileSize(int tileSize)
{
	this->tileSize = tileSize;
}
void TileMap::setLogicGrid(std::vector<std::vector<int>> logicGrid)
{
	this->logicGrid = logicGrid;
}
void TileMap::setTileGrid(std::vector<std::vector<sf::Sprite*>> tileGrid)
{
	this->tileGrid = tileGrid;
}

//GETTERS
const std::string& TileMap::getMapId()
{
	return this->mapId;
}
const TileMapState& TileMap::getMapState()
{
	return this->mapState;
}
const int& TileMap::getTileSize()
{
	return this->tileSize;
}
const std::vector<std::vector<int>>& TileMap::getLogicGrid()
{
	return this->logicGrid;
}
const std::vector<std::vector<sf::Sprite*>>& TileMap::getTileGrid()
{
	return this->tileGrid;
}

//Method that checks if the current TileMap's State is ACTIVE (ACTIVE, READY, INACTIVE)
bool TileMap::isActive()
{
	if (this->getMapState() == TileMapState::ACTIVE) 
		return true;
	return false;
		
}

void TileMap::load() {
	// Check if tileGrid is empty before initializing
	if (this->tileGrid.empty()) {
		// Resize tileGrid to match the size of logicGrid
		this->tileGrid.resize(this->logicGrid.size(), std::vector<sf::Sprite*>(this->logicGrid[0].size(), nullptr));

		// Iterate over each element in tileGrid
		for (size_t i = 0; i < this->tileGrid.size(); i++) {
			for (size_t j = 0; j < this->tileGrid[i].size(); j++) {
				// Allocate a new sf::Sprite for each element
				this->tileGrid[i][j] = new sf::Sprite();
			}
		}

		// Print a message indicating the TileMap is loaded into memory
		std::cout << "TileMap " << mapId << " loaded into memory.\n";
	}
}

//Method for deallocate the tiles/sprites from the tileGrid
void TileMap::unload()
{
	for (auto& row : this->tileGrid) {
		for (auto& tile : row) {
			delete tile;
			tile = nullptr;
		}
	}
	this->tileGrid.clear();


}

//Method for rendering the tileGrid; it has the target(window) as a parameter, which draws each tile in the tileGrid
void TileMap::render(sf::RenderTarget* target) {

	for (const auto& row : this->tileGrid) {
		for (const auto& tile : row) {
			if (tile) {
				target->draw(*tile);
			}
		}
	}
}


