#pragma once
#include <list>
#include <iostream>

#include <SFML/Graphics.hpp>

#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>

#include "GameData.h"
#include "Scene.h"


class GameScene : public Scene {
public:
	GameScene (Settings* settings, sf::RenderWindow* window);
	void onDraw(sf::RenderWindow* window, double& dt);
	void onUpdate(double& dt);
private:
	GameData data;
	void initRessources();
	void initMap();
	bool checkBulletPosition(sf::RenderWindow* window, Bullet* bullet);
	void updateDebug(int bulletCount);
	void frameCount(float* fps);
};
