#pragma once
#define BULLET_SPEED 200.0f

#include <SFML/Graphics.hpp>
#include "Entity.h"


class Bullet : public Entity {
public:
	~Bullet() {}
	Bullet(double angle, sf::Vector2f position);
	void onDraw(sf::RenderWindow* window, double& dt);
	void update(double& dt);
	void onEvent(sf::Event event, double& dt);
private:
	float speed = BULLET_SPEED;
	sf::RectangleShape shape;
	sf::Vector2f velocity;
};