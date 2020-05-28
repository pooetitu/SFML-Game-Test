#pragma once
#include <SFML/Graphics.hpp>
#include <list>
class Entity {
public:
	Entity(sf::RenderWindow& window);
	virtual ~Entity() {}
	virtual void onDraw() = 0;
	virtual void onEvent(sf::Event event)=0;
	sf::RenderWindow* getWindow() { return window; };
private:
	sf::RenderWindow* window;
};
class Player : public Entity {
public:
	Player(sf::RenderWindow& window);
	void onDraw();
	void update();
	void onEvent(sf::Event event);
private:
	int health = 10;
	int bullets = 15;
	sf::CircleShape circle;
};
class Game {
public:
	Game() {}
	Game(sf::RenderWindow& window);
	void draw();
	void event(sf::Event &event);
private:
	sf::RenderWindow* window=NULL;
	void addEntity(Entity* entity);
	std::list<Entity*> entitiesList;
};

