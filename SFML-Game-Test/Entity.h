#pragma once
#include <SFML/Graphics.hpp>


class Entity {
public:
	Entity(sf::Texture* texture) { if(texture!=NULL)sprite.setTexture(*texture); }
	virtual ~Entity() {}
	virtual void onDraw(sf::RenderWindow* window, double& dt) = 0;
	virtual void onUpdate(double& dt) = 0;
protected:
	sf::Sprite sprite;
};
