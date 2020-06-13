#include "Camera.h"

Camera::Camera() {

}
sf::Vector2f Camera::cameraToWorld(sf::Vector2f position) {
	return sf::Vector2f(cameraPosition.x / 32 + (position.x - settings->getRenderSettings()->width / 2) / 32, cameraPosition.y / 32 + (position.y - settings->getRenderSettings()->height / 2) / 32);
}

sf::Vector2f Camera::worldToCamera(sf::Vector2f position) {
	return sf::Vector2f(position.x * 32 - cameraPosition.x * 32 + settings->getRenderSettings()->width / 2, position.y * 32 - cameraPosition.y * 32 + settings->getRenderSettings()->height / 2);
}