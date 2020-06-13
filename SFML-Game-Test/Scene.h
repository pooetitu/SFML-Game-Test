#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "Settings.h"

class Scene {
public:
	Scene(Settings* settings) : settings(settings) {};
	virtual void initRessources() = 0;
	virtual void onDraw(sf::RenderWindow* window, double& dt) = 0;
	virtual void onUpdate(double& dt) = 0;
protected:
	Settings* settings;
	std::map<std::string, sf::Texture> ressources;
};