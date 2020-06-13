#include "Camera.h"

Camera::Camera() {

}
sf::Vector2f Camera::cameraToWorld(sf::Vector2f position) {
	return sf::Vector2f(cameraPosition.x + (position.x - settings->getRenderSettings()->width / 2) / 32, cameraPosition.y + (position.y - settings->getRenderSettings()->height / 2) / 32);
}

sf::Vector2f Camera::worldToCamera(sf::Vector2f position) {
	return sf::Vector2f(position.x * 32 - cameraPosition.x + settings->getRenderSettings()->width / 2, position.y * 32 - cameraPosition.y  + settings->getRenderSettings()->height / 2);
}