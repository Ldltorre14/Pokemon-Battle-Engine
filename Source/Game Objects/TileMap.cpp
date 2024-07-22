#include "TileMap.h"

//DEFAULT CONSTRUCTOR
TileMap::TileMap()
{
	this->mapId = "empty Id";
	this->mapState = TileMapState::READY;
	this->logicGrid = { 
		{enumToInt(tl::Terrain::TOPLEFTCORNER), enumToInt(tl::Terrain::TOPCENTER), enumToInt(tl::Terrain::TOPRIGHT)},
		{enumToInt(tl::Terrain::CENTERLEFT), enumToInt(tl::Terrain::CENTER), enumToInt(tl::Terrain::CENTERRIGHT)},
		{enumToInt(tl::Terrain::BOTTOMLEFT), enumToInt(tl::Terrain::BOTTOMCENTER), enumToInt(tl::Terrain::BOTTOMRIGHT)}
	};
	//this->load();
	this->tileGrid = {
		{new sf::Sprite(), new sf::Sprite(), new sf::Sprite()},
		{new sf::Sprite(), new sf::Sprite(), new sf::Sprite()},
		{new sf::Sprite(), new sf::Sprite(), new sf::Sprite()}
	};
	for (size_t i = 0; i < this->tileGrid.size(); i++) {
		for (size_t j = 0; j < this->tileGrid[i].size(); j++) {
			sf::Sprite* tile = this->tileGrid[i][j];
			sf::Texture texture;
			texture.create(32, 32);
            tile->setTexture(texture);
            tile->setColor(sf::Color::Blue);
            tile->setPosition(5 + (j * 32) ,5 + (i * 32));
		}
	}
	
}

//CONSTRUCTOR
TileMap::TileMap(std::string mapId, TileMapState mapState, 
	std::vector<std::vector<int>> logicGrid, std::vector<std::vector<sf::Sprite*>> tileGrid)
{
	this->mapId = mapId;
	this->mapState = mapState;
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
void TileMap::setMapState(TileMapState mapState)
{
	this->mapState = mapState;
}
template<typename EnumType>
void TileMap::setLogicTile(int x, int y, EnumType logicTile) {
	this->logicGrid[x][y] = enumToInt(logicTile);
}

void TileMap::setLogicGrid(std::vector<std::vector<int>> logicGrid)
{
	this->logicGrid = logicGrid;
}
void TileMap::setTileGrid(std::vector<std::vector<sf::Sprite*>> tileGrid)
{
	if (!this->tileGrid.empty()) {
		std::cout << "Cannot set the tileGrid (tiles already allocated)\n";
		return;
	}
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

//Check if every tile in the tileGrid has a sprite allocated (returns false otherwise)
bool TileMap::isLoaded() {
	if (this->tileGrid.empty())
		return false;

	for (const auto& row : this->tileGrid) {
		for (const auto& tile : row) {
			if (tile == nullptr)
				return false;
		}
	}
	
	return true;
}


bool TileMap::isLogicGridEmpty()
{
	if (this->logicGrid.empty())
		return true;
	return false;
}

bool TileMap::isTileGridEmpty()
{
	if (this->tileGrid.empty())
		return true;
	return false;
}


void TileMap::load() {
	// Check if tileGrid is empty before initializing
	if (!this->tileGrid.empty()) {
		std::cout << "Cannot load the tileGrid (Tiles already allocated)\n";
		return;
	}

	// Check if logicGrid is not empty
	if (this->logicGrid.empty()) {
		std::cout << "Cannot load the tileGrid (logicGrid is empty)\n";
		return;
	}

	// Check if logicGrid and tileGrid have the same dimensions
	if (this->tileGrid.size() != this->logicGrid.size()) {
		std::cout << "Cannot load the tileGrid (logic/tileGrid have different dimensions)\n";
		return;
	}

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

//Method for deallocate the tiles/sprites from the tileGrid
void TileMap::unload()
{
	if (this->tileGrid.empty()) {
		std::cout << "Cannot unload the tileGrid (tileGrid Empty)\n";
		return;
	}

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



