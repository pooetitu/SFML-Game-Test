#pragma once
#define BULLET_SPEED 2.0f
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>



typedef struct LinkedList LinkedList;


class Game;


class Entity {
public:
	Entity(Game* game) : game(game){}
	virtual ~Entity() {}
	virtual void onDraw() = 0;
	virtual void onEvent(sf::Event event) = 0;
	Game* getGame() { return game; };
private:
	Game* game;
};

class Game {
public:
	Game() {}
	Game(sf::RenderWindow* window);
	void draw();
	void event(sf::Event& event);
	sf::RenderWindow* getWindow() { return window; };
	std::list<Entity*>* getEntities() { return entities; };
private:
	sf::RenderWindow* window = NULL;
	std::list<Entity*>* entities;
	std::list<Entity*>::iterator iter;
};

class Player : public Entity {
public:
	Player(Game* game);
	void onDraw();
	void update();
	void onEvent(sf::Event event);
private:
	int health = 10;
	int bullets = 15;
	double angle = 90;
	sf::CircleShape circle;
	sf::RectangleShape line;
	sf::Vector2f mapPosition;
	sf::Clock clock;
};

class Bullet : public Entity {
public:
	Bullet(Game* game, double angle, sf::Vector2f position);
	void onDraw();
	void update();
	void onEvent(sf::Event event);
private:
	float speed = BULLET_SPEED;
	sf::RectangleShape shape;
	sf::Vector2f velocity;
};


