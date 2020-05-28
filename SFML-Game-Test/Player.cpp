#include "Game.hpp"

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

}
void Player::onEvent(sf::Event event) {
	
}