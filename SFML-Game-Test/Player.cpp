#include "Game.hpp"

void Player::onDraw(sf::RenderWindow& window) {
	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(5,5);
	circle.setRadius(20);
	window.draw(circle);
}
void Player::onUpdate() {

}
void Player::onEvent(sf::Event event) {

}