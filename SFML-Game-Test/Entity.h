#pragma once
#include <SFML/Graphics.hpp>
#include "Camera.h"


class Entity {
public:
	Entity(sf::Texture* texture, sf::Vector2f* mapOffset, Camera* camera) {
		if (texture != NULL)sprite.setTexture(*texture);
		this->mapOffset = mapOffset;
		this->camera = camera;
	}
	virtual ~Entity() {}
	virtual void onDraw(sf::RenderWindow* window, double& dt) = 0;
	virtual void onUpdate(double& dt) = 0;
	sf::Vector2f* getPosition() { return &mapPosition; }
	sf::IntRect getHitBox() { return hitBox; }
protected:
	Camera* camera;
	sf::IntRect hitBox;
	sf::Vector2f velocity;
	sf::Vector2f mapPosition;
	sf::Vector2f* mapOffset;
	sf::Sprite sprite;
};
