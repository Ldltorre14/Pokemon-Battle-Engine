#include "Entity.h"



Entity::Entity(sf::Texture* texture, const sf::Vector2f& pos, const sf::Vector2f& size)
{
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos);
	// this->sprite.setSize(size) ???? Why there is no setSize method
}

Entity::~Entity()
{
	delete this->sprite.getTexture();
}


void Entity::setTexture(sf::Texture* texture)
{
	this->sprite.setTexture(*texture);
}

void Entity::setPosition(const sf::Vector2f& pos)
{
	this->sprite.setPosition(pos);
}

const sf::Vector2f Entity::getPosition()
{
	return this->sprite.getPosition();
}

const sf::Texture Entity::getTexture()
{
	return *this->sprite.getTexture();
}

void Entity::move()
{

}

void Entity::update()
{

}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
