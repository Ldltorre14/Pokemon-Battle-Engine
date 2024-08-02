#include "Scene.h"



Scene::Scene(ResourceManager* resourceManager) 
{
	this->button = new UI::RectButton(UI::buttonState::IDLE_BTN, UI::textAlignment::CENTER, sf::Vector2f(100, 50),
		"START",nullptr, 16, sf::Vector2f(550, 300), sf::Color::Green);
	this->resourceManager = resourceManager;
	this->texture = this->resourceManager->getTexture("Tileset", "Terrains");
	this->spritesheet.setTexture(*this->texture);
	//this->spritesheet.setTextureRect(getTerrainRect(tl::Terrain::TOPLEFTCORNER));


	std::cout << "SCENE INITIALIZED\n";
}

Scene::~Scene() {
	delete this->button;
}


void Scene::render(sf::RenderTarget* target) {
	this->button->render(target);
	//target->draw(this->spritesheet);
	this->tileMap.render(target);
}

