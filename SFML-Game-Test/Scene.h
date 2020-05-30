#pragma once
#include <SFML/Graphics.hpp>

class Scene {
public:
	Scene() {};
	virtual void onDraw(sf::RenderWindow* window, double& dt) = 0;
	virtual void onEvent(sf::Event event, double& dt) = 0;
};