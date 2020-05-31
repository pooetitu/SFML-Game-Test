#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture,double angle, sf::Vector2f position) : Entity(texture) {
	double angleR = angle * 3.14 / 180;
	velocity = sf::Vector2f(std::cos(angleR), std::sin(angleR));
	sprite.setRotation(angle);
	sprite.setPosition(position);
	sprite.setOrigin(sf::Vector2f(2, 2));
	shape.setRotation(angle);
	shape.setPosition(position);
	shape.setSize(sf::Vector2f(5, 5));
	shape.setOrigin(sf::Vector2f(2, 2));
}

void Bullet::onDraw(sf::RenderWindow* window, double& dt) {
	window->draw(sprite);
	onUpdate(dt);
}

void Bullet::onUpdate(double& dt) {
	sf::Vector2f dVelocity(velocity);
	dVelocity.x *= dt * speed;
	dVelocity.y *= dt * speed;
	shape.setPosition(shape.getPosition() + dVelocity);
	sprite.setPosition(shape.getPosition() + dVelocity);

}
