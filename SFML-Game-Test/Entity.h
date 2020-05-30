#pragma once
#include <SFML/Graphics.hpp>


class Entity {
public:
	Entity() {}
	virtual ~Entity() {}
	virtual void onDraw(sf::RenderWindow* window, double& dt) = 0;
	virtual void onEvent(sf::Event event, double& dt) = 0;
};
