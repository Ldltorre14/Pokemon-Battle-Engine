#include "MainMenuState.h"


void MainMenuState::init() {
	this->initBackground();
	this->initMousePosText();
	this->initKeybinds();
}

void MainMenuState::initKeybinds()
{
	try {
		std::ifstream file("Config/keybinds/mainmenu_state/mainmenu_keybinds.ini");
		std::string key;
		std::string function;

		while (file >> function >> key) {
			this->keybinds[function] = this->supportedKeys->at(key);
		}
	}
	catch (std::exception& e) {
		std::cout << "Exception:" << e.what();
		this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("Left");
		this->keybinds["MOVE_UP"] = this->supportedKeys->at("Up");
		this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("Right");
		this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("Down");
		this->keybinds["SELECT_LEFT"] = this->supportedKeys->at("Left");
		this->keybinds["SELECT_UP"] = this->supportedKeys->at("Up");
		this->keybinds["SELECT_RIGHT"] = this->supportedKeys->at("Right");
		this->keybinds["SELECT_Down"] = this->supportedKeys->at("Down");
		this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
		this->keybinds["SELECT"] = this->supportedKeys->at("Enter");
		this->keybinds["CANCEL"] = this->supportedKeys->at("Backspace");
	}
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

MainMenuState::MainMenuState(sf::RenderWindow* window, ResourceManager* resourceManager, StateManager* stateManager, std::map<std::string, int>* supportedKeys)
	: State(window,resourceManager,stateManager,supportedKeys)
{
	this->init();
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) {
		this->stateQuitStatus = true;
	}
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

void MainMenuState::updateKeyInput() {

}

void MainMenuState::updateButtonInput(){

}

void MainMenuState::updateInput()
{
	this->checkForQuit();
	this->updateKeyInput();
	this->updateButtonInput();
}



void MainMenuState::update(const float& dt)
{
	this->updateMousePos();
	this->updateInput();
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;



	
	this->renderBackground(target);
	this->renderMousePosText(target);
}
