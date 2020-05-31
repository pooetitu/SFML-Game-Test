#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

class Scene {
public:
	Scene() {};
	virtual void initRessources() = 0;
	virtual void onDraw(sf::RenderWindow* window, double& dt) = 0;
protected:
	std::map<std::string, sf::Texture> ressources;
};