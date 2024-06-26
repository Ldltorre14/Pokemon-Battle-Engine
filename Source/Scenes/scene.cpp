#include "scene.h"



Scene::Scene() 
{
	this->button = new UI::RectButton(UI::buttonState::IDLE_BTN, UI::textAlignment::CENTER, sf::Vector2f(100, 50),
		"START",nullptr, 16, sf::Vector2f(550, 300), sf::Color::Green);
	std::cout << "SCENE INITIALIZED\n";
}

Scene::~Scene() {
	delete this->button;
}


void Scene::render(sf::RenderTarget* target) {
	this->button->render(target);
}

