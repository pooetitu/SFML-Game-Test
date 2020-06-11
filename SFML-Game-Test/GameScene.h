#pragma once
#include <list>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System/FileInputStream.hpp>

#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>

#include "Scene.h"
#include "Player.h"
#include "DebugMenu.h"
#include "TileMap.h"

class GameScene : public Scene {
public:
	GameScene (Settings* settings, sf::RenderWindow* window);
	void onDraw(sf::RenderWindow* window, double& dt);
private:
	TileMap tileMap;
	DebugMenu debugMenu;
	Player* player;
	std::list<Bullet*>* bullets;
	std::list<Bullet*>::iterator iter;
	void initRessources();
	void initMap();
	bool checkBulletPosition(sf::RenderWindow* window, Bullet* bullet);
	void checkCollisions();
	void updateDebug(sf::RenderWindow* window, int& bulletCount);
	void frameCount(float* fps);
};
