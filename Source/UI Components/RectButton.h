#ifndef RECTBUTTON_H
#define RECTBUTTON_H

#include "Button.h"

namespace UI {
    class RectButton : public Button {
    private:
        sf::RectangleShape* rectShape;
        sf::Vector2f position;
        sf::Vector2f buttonSize;
        sf::Text text;
        std::string textString;
        sf::Font* font;
        unsigned int fontSize;
        sf::Color color;
        sf::Texture* texture;

        void initButtonAttributes(const std::string& textString, const sf::Vector2f& buttonSize, sf::Font* font, const unsigned int& fontSize,
            const sf::Vector2f& pos, sf::Color color, sf::Texture* texture);
    public:
        RectButton(const buttonState& state, const sf::Vector2f& buttonSize, const std::string& textString, sf::Font* font = nullptr, const unsigned int& fontSize = 12,
            const sf::Vector2f& pos = sf::Vector2f(0, 0), sf::Color color = sf::Color::White, sf::Texture* texture = nullptr);
        ~RectButton();

        void setTextAlignment(const textAlignment& align);
        void setButtonSize(const sf::Vector2f& buttonSize);
        void setButtonPosition(const sf::Vector2f& buttonPos) override;
        void setText(const std::string& stringText);
        void setText(const sf::Text& text);
        void setTextPosition(const sf::Vector2f& pos);
        void setBackgroundColor(const sf::Color& color);
        sf::Vector2f getButtonSize() { return this->buttonSize; }
        unsigned int getFontSize() { return this->fontSize; }
        std::string getText() { return this->text.getString(); }
       

    };
}

#endif