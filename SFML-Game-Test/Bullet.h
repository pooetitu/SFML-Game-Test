#pragma once
#define BULLET_SPEED 250.0f

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"


class Bullet : public Entity {
public:
	~Bullet() {}
	Bullet(sf::Texture* texture, double angle, sf::Vector2f& position, Camera* camera);
	void onDraw(sf::RenderWindow* window, double& dt);
	void onUpdate(double& dt);
private:
	float speed = BULLET_SPEED;
};