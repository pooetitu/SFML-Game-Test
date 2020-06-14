#pragma once
#include <vector>

#include "Player.h"
#include "DebugMenu.h"
#include "TileMap.h"
#include "Camera.h"



struct GameData {
	Settings* settings;
	std::vector<Bullet*> bullets;
	Camera camera;
	TileMap tileMap;
	DebugMenu debugMenu;
	Player* player;
};