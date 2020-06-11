#include "GameScene.h"
#include <iostream>


Player::Player(sf::Texture* texture, sf::Texture* bulletTexture, sf::RenderWindow* window, std::list<Bullet*>* bullets) : Entity(texture, NULL) {
	this->bulletTexture = bulletTexture;
	bulletList = bullets;
	circle.setFillColor(sf::Color::Red);
	circle.setRadius(15);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(window->getSize().x / 2, window->getSize().y / 2);

	line.setRotation(angle);
	line.setFillColor(sf::Color::Blue);
	line.setSize(sf::Vector2f(15, 5));
	line.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	line.setOrigin(0, 3);

	mapPosition.x = 32 + circle.getRadius();
	mapPosition.y = 32 + circle.getRadius();
	hitBox = sf::IntRect(circle.getGlobalBounds());
}

void Player::onDraw(sf::RenderWindow* window, double& dt) {
	window->draw(circle);
	window->draw(line);
	if (window->hasFocus()) {
		onUpdate(dt);
		updateRotation(window, dt);
		shoot();
	}
}
void Player::onUpdate(double& dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		mapPosition.y -= 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		mapPosition.y += 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		mapPosition.x -= 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		mapPosition.x += 1;
}

void Player::updateRotation(sf::RenderWindow* window, double& dt) {
	sf::Vector2f coord = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	double x1 = circle.getPosition().x;
	double x2 = coord.x;
	double y1 = circle.getPosition().y;
	double y2 = coord.y;
	angle = atan2(y2 - y1, x2 - x1) * 180 / 3.14;
	line.setRotation(angle);
}

void Player::shoot() {
	static sf::Clock clock;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock.getElapsedTime().asMilliseconds() > 300) {
		bulletList->push_back(new Bullet(bulletTexture, angle, mapPosition));
		clock.restart();
	}
}
