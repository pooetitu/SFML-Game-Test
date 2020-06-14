#include "GameScene.h"


Bullet::Bullet(sf::Texture* texture,double angle, sf::Vector2f& position, GameData* data) : Entity(texture, data) {
	mapPosition = position;
	double angleR = angle * 3.14 / 180;
	velocity = sf::Vector2f(std::cos(angleR), std::sin(angleR));
	sprite.setRotation(angle);
	sprite.setPosition(position);
	sprite.setOrigin(sf::Vector2f(2, 2));
	hitBox = &sprite.getGlobalBounds();
	std::cout << sprite.getGlobalBounds().width / 32<< std::endl;
}

void Bullet::onDraw(sf::RenderWindow* window, double& dt) {
	sprite.setPosition(gameData->camera.worldToCamera(mapPosition));
	window->draw(sprite);
	onUpdate(dt);
}

void Bullet::onUpdate(double& dt) {
	sf::Vector2f dVelocity(velocity);
	dVelocity.x *= dt * speed;
	dVelocity.y *= dt * speed;
	mapPosition += dVelocity;
	hitBox->top = mapPosition.y;
	hitBox->left = mapPosition.x;
}
