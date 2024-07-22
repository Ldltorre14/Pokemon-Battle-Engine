#ifndef SPRITESHEET_PARSING_H
#define SPRITESHEET_PARSING_H

#include "../Types/tiles.h"
#include "SFML/Graphics.hpp"


inline sf::IntRect getTerrainRect(tl::Terrain terrainEnum) {
	switch (terrainEnum) {
	case tl::Terrain::TOPLEFTCORNER:
		return sf::IntRect(0, 0, 32, 32);
		break;

	case tl::Terrain::TOPCENTER:
		return sf::IntRect(32, 0, 32, 32);
		break;

	case tl::Terrain::TOPRIGHT:
		return sf::IntRect(64, 0, 32, 32);
		break;

	case tl::Terrain::CENTERLEFT:
		return sf::IntRect(0, 32, 32, 32);
		break;

	case tl::Terrain::CENTER:
		return sf::IntRect(32, 32, 32, 32);
		break;

	case tl::Terrain::CENTERRIGHT:
		return sf::IntRect(64, 32, 32, 32);
		break;

	case tl::Terrain::BOTTOMLEFT:
		return sf::IntRect(0, 64, 32, 32);
		break;

	case tl::Terrain::BOTTOMCENTER:
		return sf::IntRect(32, 64, 32, 32);
		break;

	case tl::Terrain::BOTTOMRIGHT:
		return sf::IntRect(64, 64, 32, 32);
		break;

	default:
		break;
	}
}


#endif