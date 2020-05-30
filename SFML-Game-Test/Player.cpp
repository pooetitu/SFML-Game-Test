#include "GameScene.h"
#include <iostream>


Player::Player(sf::RenderWindow* window, std::list<Bullet*>* bullets) : Entity() {
	bulletList = bullets;
	circle.setFillColor(sf::Color::Red);
	circle.setRadius(20);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	line.setRotation(angle);
	line.setFillColor(sf::Color::Blue);
	line.setSize(sf::Vector2f(20, 5));
	line.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	line.setOrigin(0, 3);
}

void Player::onDraw(sf::RenderWindow* window, double& dt) {
	window->draw(circle);
	window->draw(line);
	update(window,dt);
}
void Player::update(sf::RenderWindow* window, double& dt) {
	sf::Vector2f coord = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	double x1 = circle.getPosition().x;
	double x2 = coord.x;
	double y1 = circle.getPosition().y;
	double y2 = coord.y;
	angle = atan2(y2 - y1, x2 - x1) * 180 / 3.14;
	line.setRotation(angle);
}

void Player::onEvent(sf::Event event, double& dt) {
	sf::Time elapsed = clock.getElapsedTime();
	switch (event.type) {
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left && elapsed.asMilliseconds()>600) {
			bulletList->push_back(new Bullet(angle, circle.getPosition()));
			clock.restart();
		}
		break;
	}
}
