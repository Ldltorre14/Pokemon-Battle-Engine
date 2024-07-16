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

MainMenuState::MainMenuState(sf::RenderWindow* window, ResourceManager* resourceManager, StateManager* stateManager, UIManager* uiManager, std::map<std::string, int>* supportedKeys)
	: State(window, resourceManager, stateManager, uiManager, supportedKeys)
{
	this->init();
	if (this->uiManager == nullptr)
		std::cout << "ERROR INITIALIZING UIMANAGER";
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) {
		this->stateQuitStatus = true;
	}
	else if (this->uiManager->getButton("MAINMENU", "EXIT_BUTTON")->getState() == UI::buttonState::ACTIVE_BTN) {
		this->stateQuitStatus = true;
	}
	
}

void MainMenuState::checkForStart() {
	if (this == nullptr) {
		std::cerr << "Error: 'this' is nullptr\n";
		return;
	}

	if (this->stateManager == nullptr) {
		std::cerr << "Error: stateManager is nullptr\n";
		return;
	}


	if (this->uiManager == nullptr) {
		std::cerr << "Error: uiManager is nullptr\n";
		return;
	}

	auto startButton = this->uiManager->getButton("MAINMENU", "START_BUTTON");
	if (startButton == nullptr) {
		std::cerr << "Error: startButton is nullptr\n";
		return;
	}

	if (startButton->getState() == UI::buttonState::ACTIVE_BTN) {
		if (this->stateManager == nullptr) {
			std::cerr << "Error: stateManager is nullptr when pushing new GameState\n";
			return;
		}
		this->stateManager->pushState(new GameState(this->window, this->resourceManager, this->stateManager,
			this->uiManager, this->supportedKeys));
		std::cout << "GAME STATE PUSHED\n";
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

	this->uiManager->update(this->mouseViewPos);
}

void MainMenuState::updateInput()
{
	this->checkForStart();
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

	// Render target check
	if (!target) {
		std::cerr << "Invalid render target!" << std::endl;
		return;
	}

	// Render background if needed
	this->renderBackground(target);
	this->uiManager->render(target);
	// Render mouse position text
	this->renderMousePosText(target);

}