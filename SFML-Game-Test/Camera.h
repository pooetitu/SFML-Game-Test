#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"

class Camera {
public:
	Camera();
	Camera(Settings* settings) : settings(settings){}
	sf::Vector2f cameraToWorld(sf::Vector2f position);
	sf::Vector2f worldToCamera(sf::Vector2f position);
	sf::Vector2f getCameraPosition() { return cameraPosition; }
	void setCameraPosition(sf::Vector2f position) { cameraPosition = position; }
private:
	sf::Vector2f cameraPosition;
	Settings* settings;
};