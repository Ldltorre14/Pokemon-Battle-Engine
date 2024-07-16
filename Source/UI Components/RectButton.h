#ifndef RECTBUTTON_H
#define RECTBUTTON_H

#include "Button.h"

namespace UI {
    class RectButton : public Button {
    private:
        sf::RectangleShape* rectShape;
        sf::Vector2f buttonPosition;
        sf::Vector2f buttonSize;
        sf::Text text;
        sf::Vector2f textPosition;
        std::string textString;
        sf::Font* font;
        unsigned int fontSize;
        sf::Color color;
        sf::Texture* texture;

        void initButtonAttributes(const std::string& textString, const sf::Vector2f& buttonSize, sf::Font* font, const unsigned int& fontSize,
            const sf::Vector2f& buttonPosition, sf::Color color, sf::Texture* texture);

        void alignTextTopLeft();
        void alignTextTopCenter();
        void alignTextTopRight();
        void alignTextLeft();
        void alignTextCenter();
        void alignTextRight();
        void alignTextBottomLeft();
        void alignTextBottomCenter();
        void alignTextBottomRight();
    public:
        RectButton(const buttonState& state, const UI::textAlignment& alignment, const sf::Vector2f& buttonSize,  const std::string& textString, sf::Font* font = nullptr, const unsigned int& fontSize = 12,
            const sf::Vector2f& buttonPosition = sf::Vector2f(0, 0), sf::Color color = sf::Color::White, sf::Texture* texture = nullptr);
        ~RectButton();

        void setTextAlignment(const textAlignment& align) override;
        void setButtonSize(const sf::Vector2f& buttonSize) override;
        void setButtonPosition(const sf::Vector2f& buttonPos) override;
        void setText(const std::string& stringText) override;
        void setText(const sf::Text& text) override;
        void setTextPosition(const sf::Vector2f& pos) override;
        void setBackgroundColor(const sf::Color& color) override;
        sf::Vector2f getButtonSize() { return this->buttonSize; }
        unsigned int getFontSize() { return this->fontSize; }
        std::string getText() { return this->text.getString(); }

        void handleTextAlignment() override;
        void renderText(sf::RenderTarget* target) override;

    };
}

#endif