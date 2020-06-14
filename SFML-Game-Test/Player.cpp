#include "GameScene.h"
#include <iostream>
#include <tmxlite/Object.hpp>


Player::Player(sf::Texture* texture, sf::Texture* bulletTexture, sf::RenderWindow* window, std::vector<Bullet*>* bullets, GameData* data) : Entity(texture, data) {
	this->bulletTexture = bulletTexture;
	bulletList = bullets;
	sprite.setTexture(*texture);
	sprite.setRotation(angle);
	sprite.setTextureRect(sf::IntRect(0, 0, 37, 30));
	sprite.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	sprite.setOrigin(37 / 2, 30 / 2);
	mapPosition.x = 1 + sprite.getOrigin().x / 32;
	mapPosition.y = 1 + sprite.getOrigin().y / 32;
	hitBox = &sprite.getGlobalBounds();
}

void Player::onDraw(sf::RenderWindow* window, double& dt) {
	window->draw(sprite);
	if (window->hasFocus()) {
		updateRotation(window, dt);
		shoot();
	}
}
void Player::onUpdate(double& dt) {
	std::array<tmx::Object*, 5> collisionObjects = gameData->tileMap.getCollisionObjects(mapPosition);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ) {
		if (collisionObjects[2] != NULL) {
			tmx::Object* obj = collisionObjects[2];
			if (obj->getType() == "1" && !hitBox->intersects(sf::FloatRect(obj->getAABB().left, obj->getAABB().top, obj->getAABB().width, obj->getAABB().height)))
				mapPosition.y -= dt * PLAYER_MOVEMENT_SPEED;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		mapPosition.y += dt * PLAYER_MOVEMENT_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		mapPosition.x -= dt * PLAYER_MOVEMENT_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		mapPosition.x += dt * PLAYER_MOVEMENT_SPEED;
	}
	gameData->camera.setCameraPosition(mapPosition);
}

void Player::updateRotation(sf::RenderWindow* window, double& dt) {
	sf::Vector2f coord = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	double x1 = window->getSize().x / 2;
	double x2 = coord.x;
	double y1 = window->getSize().y / 2;
	double y2 = coord.y;
	angle = atan2(y2 - y1, x2 - x1) * 180 / 3.14;
	sprite.setRotation(angle);
}

void Player::shoot() {
	static sf::Clock clock;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock.getElapsedTime().asMilliseconds() > 300) {
		bulletList->push_back(new Bullet(bulletTexture, angle, mapPosition, gameData));
		clock.restart();
	}
}
