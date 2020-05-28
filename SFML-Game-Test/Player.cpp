#include "Game.hpp"

Player::Player(sf::RenderWindow& window):Entity(window) {
	circle.setFillColor(sf::Color::Red);
	circle.setRadius(20);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(this->getWindow()->getSize().x / 2, this->getWindow()->getSize().y / 2);
}

void Player::onDraw() {
	this->getWindow()->draw(this->circle);
}
void Player::update() {
	sf::Mouse mouse;
	mouse.getPosition().x;

}
void Player::onEvent(sf::Event event) {
	
}