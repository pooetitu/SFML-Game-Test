#pragma once
#include <SFML/Graphics.hpp>
#include <list>
class IEntity {
public:
	IEntity() {}
	virtual ~IEntity() {}
	virtual void onDraw(sf::RenderWindow& window) = 0;
	virtual void onUpdate()=0;
	virtual void onEvent(sf::Event event)=0;
};
class Player : public IEntity {
public:
	Player(){}
	int health = 10;
	int bullets = 15;


	void onDraw(sf::RenderWindow& window);
	void onUpdate();
	void onEvent(sf::Event event);
};
class Game {
public:
	void init();
	void draw(sf::RenderWindow &window);
	void update();
	void event(sf::Event &event);
private:
	void addEntity(IEntity* entity);
	std::list<IEntity*> entitiesList;
};

