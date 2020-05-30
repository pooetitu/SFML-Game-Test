#pragma once
#include "Bullet.h"

class Player : public Entity {
public:
	Player(sf::RenderWindow* window, std::list<Bullet*>* bullets);
	void onDraw(sf::RenderWindow* window, double& dt);
	void update(sf::RenderWindow* window, double& dt);
	void onEvent(sf::Event event, double& dt);
private:
	int health = 10;
	int bullets = 15;
	double angle = 90;
	sf::CircleShape circle;
	sf::RectangleShape line;
	sf::Vector2f mapPosition;
	sf::Clock clock;
	std::list<Bullet*>* bulletList;
};
