#include "Bullet.h"

Bullet::Bullet(double angle, sf::Vector2f position) : Entity() {
	double angleR = angle * 3.14 / 180;
	velocity = sf::Vector2f(std::cos(angleR), std::sin(angleR));
	shape.setRotation(angle);
	shape.setPosition(position);
	shape.setSize(sf::Vector2f(5, 5));
	shape.setOrigin(sf::Vector2f(2, 2));
	shape.setFillColor(sf::Color::Red);
}

void Bullet::onDraw(sf::RenderWindow* window, double& dt) {
	window->draw(shape);
	update(dt);
}

void Bullet::update(double& dt) {
	sf::Vector2f dVelocity(velocity);
	dVelocity.x *= dt * speed;
	dVelocity.y *= dt * speed;
	shape.setPosition(shape.getPosition() + dVelocity);
}

void Bullet::onEvent(sf::Event event, double& dt) {

}