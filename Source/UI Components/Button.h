#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace UI{
	enum class buttonState : int {
		IDLE_BTN = 0,
		HOVER_BTN = 1,
		ACTIVE_BTN = 2
	};
	class Button
	{
	private:
		buttonState state;

		sf::Text text;
		sf::Font* font;
		unsigned fontSize;

		sf::Texture* btnTexture;
		sf::Color* txtColor;

	public:
		Button(const sf::Text& text, sf::Font* font, unsigned fontSize,
			sf::Texture* btnTexture = nullptr, sf::Color* txtColor = nullptr);
		virtual ~Button();

		virtual void setState(buttonState btn_state);
		virtual void update() = 0;
		virtual void render(sf::RenderTarget* target = nullptr) = 0;
	};
};




#endif

