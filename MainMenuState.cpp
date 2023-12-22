#include "MainMenuState.h"


void MainMenuState::init() {
	this->initBackground();
	this->initMousePosText();
}

void MainMenuState::initBackground()
{
	
	std::cout << "Resource Manager Available\n";
	if (this->resourceManager->getTexture("Background", "Title"))
		std::cout << "Texture Available\n";
	this->bgTexture = this->resourceManager->getTexture("Background", "Title");
	this->background.setSize(static_cast<sf::Vector2f>(this->window->getSize()));
	this->background.setTexture(this->bgTexture);
	
	if (this->bgTexture)
		std::cout << "bgTexture Initialized Properly\n";
	std::cout << "Background Size: " << this->background.getSize().x << " x " << this->background.getSize().y << "\n";
	

}

void MainMenuState::initMousePosText()
{
	
	std::stringstream mousePosTextStream;
	mousePosTextStream << "X:" << this->mouseViewPos.x << "\nY:" << this->mouseViewPos.y;

	this->mousePosText.setCharacterSize(12);
	this->mousePosText.setFont(*this->resourceManager->getFont("Gen1_2"));
	this->mousePosText.setPosition(this->mouseViewPos.x + 15, this->mouseViewPos.y + 15);
	this->mousePosText.setString(mousePosTextStream.str());
}

MainMenuState::MainMenuState(sf::RenderWindow* window, ResourceManager* resourceManager)
	: State(window,resourceManager)
{
	this->initBackground();
	this->initMousePosText();
	
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::renderBackground(sf::RenderTarget* target)
{
	target->draw(this->background);
}

void MainMenuState::renderMousePosText(sf::RenderTarget* target)
{
	std::stringstream mousePosTextStream;
	mousePosTextStream << "X:" << this->mouseViewPos.x << "\nY:" << this->mouseViewPos.y;
	this->mousePosText.setPosition(this->mouseViewPos.x + 15, this->mouseViewPos.y + 15);
	this->mousePosText.setString(mousePosTextStream.str());
	target->draw(this->mousePosText);
	
}

void MainMenuState::update(const float& dt)
{
	//std::cout << "Hello from main menu" << std::endl;
	this->updateMousePos();
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;



	
	this->renderBackground(target);
	this->renderMousePosText(target);
}
