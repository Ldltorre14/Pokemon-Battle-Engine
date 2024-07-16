#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity 
{
private:

protected:
	sf::Sprite sprite;

public:
	Entity(sf::Texture* texture,  const sf::Vector2f& pos, const sf::Vector2f& size);
	~Entity();

	void setTexture(sf::Texture* texture);
	void setPosition(const sf::Vector2f& pos);
	const sf::Vector2f getPosition();
	const sf::Texture getTexture();

	void move();
	void update();

	void render(sf::RenderTarget* target);



};

#endif