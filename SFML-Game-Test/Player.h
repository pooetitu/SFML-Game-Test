#pragma once
#include "Bullet.h"

class Player : public Entity {
public:
	Player(sf::Texture* texture, sf::Texture* bulletTexture, sf::RenderWindow* window,std::list<Bullet*>* bullets);
	void onDraw(sf::RenderWindow* window, double& dt);
	void onUpdate( double& dt);
	void shoot();
	void updateRotation(sf::RenderWindow* window, double& dt);
private:
	int health = 10;
	int bullets = 15;
	double angle = 90;
	sf::Texture* bulletTexture;
	std::list<Bullet*>* bulletList;
	sf::CircleShape circle;
	sf::RectangleShape line;
};
