#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/FileInputStream.hpp>
#include <list>
#include <iostream>
#include "Scene.h"
#include "Player.h"



class GameScene : public Scene {
public:
	GameScene(sf::RenderWindow* window);
	void onDraw(sf::RenderWindow* window, double& dt);
private:
	Player* player;
	std::list<Bullet*>* bullets;
	std::list<Bullet*>::iterator iter;
	void initRessources();
	bool checkBulletPosition(sf::RenderWindow* window, Bullet* bullet);
};
