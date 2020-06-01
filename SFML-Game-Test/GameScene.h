#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/FileInputStream.hpp>
#include <list>
#include <iostream>
#include "Scene.h"
#include "Player.h"
#include "DebugMenu.h"


class GameScene : public Scene {
public:
	GameScene(sf::RenderWindow* window);
	void onDraw(sf::RenderWindow* window, double& dt);
private:
#if _DEBUG
	bool debugging = true;
#else
	bool debugging = false;
#endif
	
	DebugMenu debugMenu;
	Player* player;
	std::list<Bullet*>* bullets;
	std::list<Bullet*>::iterator iter;
	void initRessources();
	bool checkBulletPosition(sf::RenderWindow* window, Bullet* bullet);
	void updateDebug(sf::RenderWindow* window, int& bulletCount);
	void frameCount(float* fps);
};
