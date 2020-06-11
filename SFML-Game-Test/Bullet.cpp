#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture,double angle, sf::Vector2f& position) : Entity(texture, &position) {
	mapPosition = position;
	double angleR = angle * 3.14 / 180;
	velocity = sf::Vector2f(std::cos(angleR), std::sin(angleR));
	sprite.setRotation(angle);
	sprite.setPosition(position);
	sprite.setOrigin(sf::Vector2f(2, 2));
	hitBox = sf::IntRect(sprite.getGlobalBounds());
	std::cout << mapPosition.x << "  " << mapPosition.y << std::endl;
}

void Bullet::onDraw(sf::RenderWindow* window, double& dt) {
	sprite.setPosition(mapPosition.x - mapOffset->x + window->getSize().x/2, mapPosition.y - mapOffset->y + window->getSize().y / 2);
	window->draw(sprite);
	onUpdate(dt);
}

void Bullet::onUpdate(double& dt) {
	sf::Vector2f dVelocity(velocity);
	dVelocity.x *= dt * speed;
	dVelocity.y *= dt * speed;
	mapPosition += dVelocity;
	hitBox.top = mapPosition.y;
	hitBox.left = mapPosition.x;
}
