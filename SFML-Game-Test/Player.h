#pragma once
#include "Bullet.h"
#define PLAYER_MOVEMENT_SPEED 2.0f;

class Player : public Entity {
public:
	Player(sf::Texture* texture, sf::Texture* bulletTexture, sf::RenderWindow* window,std::vector<Bullet*>* bullets, GameData* data);
	void onDraw(sf::RenderWindow* window, double& dt);
	void onUpdate( double& dt);
	void shoot();
	void updateRotation(sf::RenderWindow* window, double& dt);
private:
	int health = 10;
	int bullets = 15;
	double angle = 90;
	sf::Texture* bulletTexture;
	std::vector<Bullet*>* bulletList;
};
