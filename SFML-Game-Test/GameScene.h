#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "Scene.h"
#include "Player.h"



class GameScene : public Scene {
public:
	GameScene(sf::RenderWindow* window);
	void onDraw(sf::RenderWindow* window, double& dt);
	void onEvent(sf::Event event, double& dt);
private:
	Player* player;
	std::list<Bullet*>* bullets;
	std::list<Bullet*>::iterator iter;
};
