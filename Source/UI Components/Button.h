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
	enum class textAlignment : int {
		TOP_LEFT = 0,
		TOP_CENTER = 1,
		TOP_RIGHT = 2,
		LEFT = 3,
		CENTER = 4,
		RIGHT = 5,
		BOTTOM_LEFT = 6,
		BOTTOM_CENTER = 7,
		BOTTOM_RIGHT = 8
	};

	class Button
	{
	private:
		
	protected:
		buttonState state;
		sf::Shape* baseShape;


	public:
		Button(const buttonState& state, sf::Shape* shape);
		virtual ~Button();
		bool isOnButton(const sf::Event& event);
		bool isOnButton(const sf::Vector2f& cursor);

		virtual void setState(const buttonState& btn_state);
		virtual void setButtonSize(const sf::Vector2f& buttonSize) {};
		virtual void setButtonPosition(const sf::Vector2f& buttonPos) {};
		virtual void setText(const std::string& stringText) {};
		virtual void setText(const sf::Text& text) {};
		virtual void setTextPosition(const sf::Vector2f& pos) {};
		virtual void setBackgroundColor(const sf::Color& color) {};

		virtual buttonState getState();
		virtual void updateState(const sf::Vector2f& cursor);
		virtual void handleState(const sf::Event& event);
		virtual void update(const sf::Vector2f& cursor, const sf::Event& event);
		virtual void render(sf::RenderTarget* target = nullptr);

	};
};




#endif

