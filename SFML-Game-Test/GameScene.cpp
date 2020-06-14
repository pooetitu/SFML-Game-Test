#include "GameScene.h"

GameScene::GameScene (Settings* settings, sf::RenderWindow* window) : Scene(settings) {
	data.camera = Camera(settings);
	sf::Clock clock;
	data.debugMenu = DebugMenu();
	data.player = new Player(&ressources["PLAYER"], &ressources["BULLET"], window, &data.bullets, &data);
	initRessources();
	initMap();
	data.debugMenu.setMapPosition(data.player->getPosition());
	std::cout << "Loaded GameScene in " << clock.restart().asSeconds() << std::endl;
	
}

void GameScene::initRessources() {
	if (!ressources["BULLET"].loadFromFile("res/sprite/bullet.png")) { 
		std::cout << "failed" << std::endl;
	}
	if (!ressources["PLAYER"].loadFromFile("res/sprite/player.png")) {
		std::cout << "failed" << std::endl;
	}
}

void GameScene::initMap() {
	tmx::Map* map = new tmx::Map();
	if (map->load("res/maps/map.tmx")) {
		data.tileMap = TileMap(map, &data.camera);
		std::cout << "Map loaded" << std::endl;
	}
}

void GameScene::onDraw(sf::RenderWindow* window, double& dt) {
	window->draw(data.tileMap);
	for (auto& iter : data.bullets)
		iter->onDraw(window, dt);
	data.player->onDraw(window, dt);
	if (settings->isDebugging())
		data.debugMenu.draw(window);

}

void GameScene::onUpdate(double& dt) {
	data.tileMap.setPosition(data.camera.worldToCamera(sf::Vector2f(0, 0)));
	data.player->onUpdate(dt);
	if (settings->isDebugging())
		updateDebug(data.bullets.size());

}

void GameScene::updateDebug(int bulletCount) {
	data.debugMenu.setBulletCount(bulletCount);
	frameCount(data.debugMenu.getFrameCount());
}

bool GameScene::checkBulletPosition(sf::RenderWindow* window, Bullet* bullet) {
	return bullet->getPosition()->x > window->getSize().x || bullet->getPosition()->y > window->getSize().y ||
		0 > bullet->getPosition()->x || 0 > bullet->getPosition()->y;
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
