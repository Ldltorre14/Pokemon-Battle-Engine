#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "../Types/ui_types.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace UI{

	class Button
	{
	private:
		
	protected:
		buttonState state;
		textAlignment alignment;
		sf::Shape* baseShape;
		sf::Text text;


	public:
		Button(const buttonState& state, const UI::textAlignment& alignment, sf::Shape* shape);
		virtual ~Button();
		bool isOnButton(const sf::Vector2f& cursor);

		virtual void setState(const buttonState& btn_state);
		virtual void setButtonSize(const sf::Vector2f& buttonSize) {};
		virtual void setButtonPosition(const sf::Vector2f& buttonPos) {};
		virtual void setText(const std::string& stringText) {};
		virtual void setText(const sf::Text& text) {};
		virtual void setTextPosition(const sf::Vector2f& pos) {};
		virtual void setTextAlignment(const UI::textAlignment& alignment) {};
		virtual void setBackgroundColor(const sf::Color& color) {};

		virtual buttonState getState();
		virtual void handleTextAlignment() {};
		virtual void updateState(const sf::Vector2f& cursor);
		virtual void handleState();
		virtual void update(const sf::Vector2f& cursor);
		virtual void renderText(sf::RenderTarget* target = nullptr) {};
		virtual void render(sf::RenderTarget* target = nullptr);

	};
};




#endif

