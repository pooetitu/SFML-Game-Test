#include "Game.hpp"
#include <iostream>


Player::Player(Game* game) : Entity(game) {
	sf::RenderWindow* window = getGame()->getWindow();
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

void Player::onDraw() {
	getGame()->getWindow()->draw(circle);
	getGame()->getWindow()->draw(line);
	update();
}
void Player::update() {

}

void Player::onEvent(sf::Event event) {
	sf::Time elapsed = clock.getElapsedTime();
	switch (event.type) {
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left && elapsed.asMilliseconds()>600) {
			this->getGame()->getEntities()->push_front(new Bullet(getGame(), angle, circle.getPosition()));
			clock.restart();
		}
		break;
	case sf::Event::MouseMoved:
		sf::Vector2f coord = this->getGame()->getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*getGame()->getWindow()));
		double x1 = circle.getPosition().x;
		double x2 = coord.x;
		double y1 = circle.getPosition().y;
		double y2 = coord.y;
		angle = atan2(y2 - y1, x2 - x1) * 180 / 3.14;
		line.setRotation(angle);
		break;
	}
}

Bullet::Bullet(Game* game, double angle, sf::Vector2f position) : Entity(game) {
	double angleR = angle * 3.14 / 180;
	velocity = sf::Vector2f(std::cos(angleR), std::sin(angleR));
	shape.setRotation(angle);
	shape.setPosition(position);
	shape.setSize(sf::Vector2f(5, 5));
	shape.setOrigin(sf::Vector2f(2, 2));
	shape.setFillColor(sf::Color::Red);
}

void Bullet::onDraw() {
	this->getGame()->getWindow()->draw(shape);
	update();
}

void Bullet::update() {
	shape.setPosition(shape.getPosition()+velocity);
}

void Bullet::onEvent(sf::Event event) {

}