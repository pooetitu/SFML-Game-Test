#pragma once
#define BULLET_SPEED 160.0f

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"


class Bullet : public Entity {
public:
	~Bullet() {}
	Bullet(sf::Texture* texture, double angle, sf::Vector2f position);
	void onDraw(sf::RenderWindow* window, double& dt);
	void onUpdate(double& dt);
	sf::Vector2f getPosition() { return shape.getPosition(); }
private:
	float speed = BULLET_SPEED;
	sf::RectangleShape shape;
	sf::Vector2f velocity;
};