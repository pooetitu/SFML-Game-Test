#include "Game.hpp"
#include <iostream>

Player::Player(sf::RenderWindow& window) :Entity(window) {
	circle.setFillColor(sf::Color::Red);
	circle.setRadius(20);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(this->getWindow()->getSize().x / 2, this->getWindow()->getSize().y / 2);
	line.setFillColor(sf::Color::Blue);
	line.setSize(sf::Vector2f(20, 5));
	line.setPosition(this->getWindow()->getSize().x / 2, this->getWindow()->getSize().y / 2);
	line.setOrigin(0, 3);
}

void Player::onDraw() {
	this->getWindow()->draw(this->circle);
	this->getWindow()->draw(line);
	update();
}
void Player::update() {
	sf::Mouse mouse;
	sf::Vector2f coord = this->getWindow()->mapPixelToCoords(mouse.getPosition(*this->getWindow()));
	double x1 = circle.getPosition().x;
	double x2 = coord.x;
	double y1 = circle.getPosition().y;
	double y2 = coord.y;
	double angle = atan2(y2 - y1, x2 - x1) * 180 / 3.14;
	line.setRotation(angle);
}
void Player::onEvent(sf::Event event) {
	
}