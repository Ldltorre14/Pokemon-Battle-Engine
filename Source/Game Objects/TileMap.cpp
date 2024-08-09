#include "TileMap.h"
  
//DEFAULT CONSTRUCTOR
TileMap::TileMap()
{
	this->mapId = "empty Id";
	this->mapState = TileMapState::READY;
	this->tileSizePx = 32;
	this->mapWidthPx = 1280;
	this->mapHeightPx = 720;
	this->gridSize.x = 1280 / 32;
	this->gridSize.y = 720 / 32;
	this->origin.x = 0;
	this->origin.y = 0;
	this->logicGrid = { 
		{enumToInt(tl::Terrain::TOPLEFTCORNER), enumToInt(tl::Terrain::TOPCENTER), enumToInt(tl::Terrain::TOPRIGHT)},
		{enumToInt(tl::Terrain::CENTERLEFT), enumToInt(tl::Terrain::CENTER), enumToInt(tl::Terrain::CENTERRIGHT)},
		{enumToInt(tl::Terrain::BOTTOMLEFT), enumToInt(tl::Terrain::BOTTOMCENTER), enumToInt(tl::Terrain::BOTTOMRIGHT)}
	};

	this->load();
	
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
TileMap::TileMap(std::string mapId, TileMapState mapState, int tileSizePx, int mapWidthPx, int mapHeightPx,
	sf::Vector2i gridSize, sf::Vector2i origin, sf::Texture* spritesheet,
	std::vector<std::vector<int>> logicGrid, std::vector<std::vector<sf::Sprite*>> tileGrid)
{
	this->mapId = mapId;
	this->mapState = mapState;
	this->tileSizePx = tileSizePx;
	this->mapWidthPx = mapWidthPx;
	this->mapHeightPx = mapHeightPx;
	this->gridSize = gridSize;
	this->origin = origin;
	this->spritesheet = spritesheet;
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

void TileMap::setTileSizePx(int tileSizePx)
{
	this->tileSizePx = tileSizePx;
}

void TileMap::setMapWidthPx(int mapWidthPx)
{
	this->mapWidthPx = mapWidthPx;
}

void TileMap::setMapHeightPx(int mapHeightPx)
{
	this->mapHeightPx = mapHeightPx;
}

void TileMap::setGridSize(sf::Vector2i gridSize)
{
	this->gridSize = gridSize;
}

void TileMap::setGridSize(int rows, int cols)
{
	this->gridSize.x = rows;
	this->gridSize.y = cols;
}

void TileMap::setOrigin(sf::Vector2i originCoord)
{
	this->origin = originCoord;
}

void TileMap::setOrigin(int x, int y)
{
	this->origin.x = x;
	this->origin.y = y;
}

void TileMap::setSpritesheet(sf::Texture* spritesheet)
{
	if (!spritesheet) {
		std::cout << "Cannot set spritesheet (texture is referencing a null ptr)\n";
		return;
	}
	this->spritesheet = spritesheet;
}

template<typename EnumType>
void TileMap::setLogicTile(int x, int y, EnumType logicTile) {

	if (this->isLogicGridEmpty()) {
		std::cout << "Cannot set Logic Tile (Logic Grid is Empty)\n";
		return;
	}

	if (this->areCoordsOutOfBounds(x, y)) {
		std::cout << "Cannot set logic Tile (Coords Out of Bounds)\n";
		return;
	}
	
	this->logicGrid[x][y] = enumToInt(logicTile);
}
	

void TileMap::setTileTexture(int x, int y, sf::Texture* texture)
{
	if (this->isTileGridEmpty()) {
		std::cout << "Cannot set Tile Texture (Tile Grid is Empty)\n";
		return;
	}
	if (this->areCoordsOutOfBounds(x, y)) {
		std::cout << "Cannot set Tile Texture (Coords Out of Bounds)\n";
		return;
	}
	if (!texture) {
		std::cout << "Cannot set Tile Texture (texture is referencing a null ptr)\n";
		return;
	}
	
	this->tileGrid[x][y]->setTexture(*texture);
}

void TileMap::setTileSprite(int x, int y, sf::Sprite* tile)
{
	if (this->isTileGridEmpty()) {
		std::cout << "Cannot set Tile Sprite (Tile Grid is Empty)\n";
		return;
	}
	if (this->areCoordsOutOfBounds(x, y)) {
		std::cout << "Cannot set Tile Sprite (Coords Out of Bounds)\n";
		return;
	}
	if (!tile) {
		std::cout << "Cannot set Tile Sprite (tile is referencing a null ptr)\n";
		return;
	}

	delete this->tileGrid[x][y];
	this->tileGrid[x][y] = tile;
}

void TileMap::setLogicGrid(std::vector<std::vector<int>> logicGrid)
{
	this->logicGrid = logicGrid;
}

void TileMap::setTileGrid(std::vector<std::vector<sf::Sprite*>> tileGrid)
{
	if (!this->isTileGridEmpty()) {
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

const int& TileMap::getTileSizePx()
{
	return this->tileSizePx;
}

const int& TileMap::getMapWidthPx()
{
	return this->mapWidthPx;
}

const int& TileMap::getMapHeightPx()
{
	return this->mapHeightPx;
}

const sf::Vector2i& TileMap::getGridSize()
{
	return this->gridSize;
}

const sf::Vector2i& TileMap::getOrigin()
{
	return this->origin;
}

const sf::Texture* TileMap::getSpritesheet()
{
	return nullptr;
}

template<typename EnumType>
const EnumType& TileMap::getLogicTile(int x, int y)
{
	if (this->isLogicGridEmpty()) {
		std::cout << "Cannot get Logic Tile (Logic Grid is Empty)\n";
		return;
	}
	
	if (this->areCoordsOutOfBounds(x, y)) {
		std::cout << "Cannot get Logic Tile (Coords are Out of Bounds)\n";
		return;
	}

	return this->logicGrid[x][y];
}

const sf::Texture* TileMap::getTileTexture(int x, int y)
{
	if (this->isTileGridEmpty()) {
		std::cout << "Cannot get Tile Texture (Tile Grid is Empty)\n";
		return nullptr;
	}

	if (this->areCoordsOutOfBounds(x, y)) {
		std::cout << "Cannot get Tile Texture (Coords are Out of Bounds)\n";
		return nullptr;
	}

	if (!this->tileGrid[x][y]->getTexture()) {
		std::cout << "Cannot get Tile Texture (texture is referencing a null ptr)\n";
		return nullptr;
	}

	return this->tileGrid[x][y]->getTexture();
}

const sf::Sprite* TileMap::getTileSprite(int x, int y)
{
	if (this->isTileGridEmpty()) {
		std::cout << "Cannot get Tile Sprite (Tile Grid is Empty)\n";
		return nullptr;
	}

	if (this->areCoordsOutOfBounds(x, y)) {
		std::cout << "Cannot get Tile Sprite (Coords are Out of Bounds)\n";
		return nullptr;
	}

	if (!this->tileGrid[x][y]) {
		std::cout << "Cannot get Tile Sprite (sprite is referencing a null ptr)\n";
		return nullptr;
	}

	return this->tileGrid[x][y];
}

const std::vector<std::vector<int>>& TileMap::getLogicGrid()
{
	return this->logicGrid;
}

const std::vector<std::vector<sf::Sprite*>>& TileMap::getTileGrid()
{
	return this->tileGrid;
}

bool TileMap::isTileGridEmpty()
{
	if (this->tileGrid.empty())
		return true;
	return false;
}

bool TileMap::isLogicGridEmpty()
{
	if (this->logicGrid.empty())
		return true;
	return false;
}

bool TileMap::areCoordsOutOfBounds(const int &x, const int &y)
{
	if (x < 0 || y < 0 || x > this->tileGrid.size() || y > this->tileGrid[0].size()
		|| x > this->logicGrid.size() || y > this->logicGrid[0].size())
	{
		return true;
	}
	return false;
}


bool TileMap::checkSameGridsDimensions()
{
	if ((this->logicGrid.size() == this->tileGrid.size()) && (this->logicGrid[0].size() == this->tileGrid[0].size()) )
		return true;
	return false;
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



void TileMap::resizeTileGrid()
{
	if (this->checkSameGridsDimensions()) {
		std::cout << "Cannot resize because both grids have already the same dimensions\n";
		return;
	}
	else {
		this->tileGrid.resize(this->logicGrid.size());
		for (auto& row : this->tileGrid) {
			row.resize(this->logicGrid[0].size());
		}
		std::cout << this->tileGrid.size() << "\n";
		std::cout << this->tileGrid[0].size() << "\n";
	}
}

void TileMap::load() {
	if (this->isLogicGridEmpty()) {
		std::cout << "Cannot load Tilemap (Cannot resize Tile Grid (Logic Grid empty))\n";
		return;
	}
	if (!this->isTileGridEmpty()) {
		std::cout << "Cannot load Tilemap (Tile Grid already loaded)\n";
		return;
	}

	this->resizeTileGrid();
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



