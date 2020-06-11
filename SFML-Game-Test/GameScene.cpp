#include "GameScene.h"

GameScene::GameScene (Settings* settings, sf::RenderWindow* window) : Scene(settings) {
	sf::Clock clck;
	debugMenu = DebugMenu();
	bullets = new std::list<Bullet*>();
	player = new Player(NULL, &ressources["BULLET"], window, bullets);
	initRessources();
	initMap();
	debugMenu.setMapPosition(player->getPosition());
	std::cout << "Loaded GameScene in " << clck.restart().asSeconds() << std::endl;
	
}

void GameScene::initRessources() {
	if (!ressources["BULLET"].loadFromFile("res/sprite/bullet.png")) { 
		std::cout << "failed" << std::endl;
	}
}

void GameScene::initMap() {
	tmx::Map* map = new tmx::Map();
	if (map->load("res/maps/map.tmx")) {
		this->tileMap = TileMap(map, player->getPosition());
		std::cout << "Map loaded" << std::endl;
	}
}

void GameScene::onDraw(sf::RenderWindow* window, double& dt) {
	tileMap.draw(window);
	checkCollisions();
	int count = 0;
	for (iter = bullets->begin(); iter != bullets->end(); ++iter) {
		count++;
		(*iter)->onDraw(window, dt);
	}
	player->onDraw(window, dt);
	if (settings->isDebugging())
		updateDebug(window, count);
}

bool GameScene::checkBulletPosition(sf::RenderWindow* window, Bullet* bullet) {
	return bullet->getPosition()->x > window->getSize().x || bullet->getPosition()->y > window->getSize().y ||
		0 > bullet->getPosition()->x || 0 > bullet->getPosition()->y;
}

void GameScene::updateDebug(sf::RenderWindow* window, int& bulletCount) {
	debugMenu.setBulletCount(bulletCount);
	frameCount(debugMenu.getFrameCount());
	debugMenu.draw(window);
}

void GameScene::frameCount(float* fps) {
	static sf::Clock timer;
	static int numFrames = 0;
	numFrames++;
	if (timer.getElapsedTime().asSeconds() >= 1.0f) {
		*fps = (float)numFrames / timer.getElapsedTime().asSeconds();
		numFrames = 0;
		timer.restart();
	}
}

void GameScene::checkCollisions() {
	for (auto const& obst : tileMap.getCollision()) {
		std::list<Bullet*> toKeep;
		for(iter = bullets->begin(); iter != bullets->end(); ++iter)
			if (!obst.intersects((*iter)->getHitBox())) {
				toKeep.push_back(*iter);
			}
		bullets->swap(toKeep);
	}
}
