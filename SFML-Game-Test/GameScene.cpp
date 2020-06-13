#include "GameScene.h"

GameScene::GameScene (Settings* settings, sf::RenderWindow* window) : Scene(settings) {
	camera = Camera(settings);
	sf::Clock clock;
	debugMenu = DebugMenu();
	bullets = new std::list<Bullet*>();
	player = new Player(&ressources["PLAYER"], &ressources["BULLET"], window, bullets, &camera);
	initRessources();
	initMap();
	debugMenu.setMapPosition(player->getPosition());
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
		this->tileMap = TileMap(map, &camera);
		std::cout << "Map loaded" << std::endl;
	}
}

void GameScene::onDraw(sf::RenderWindow* window, double& dt) {
	window->draw(tileMap);
	int count = 0;
	for (iter = bullets->begin(); iter != bullets->end(); ++iter) {
		count++;
		(*iter)->onDraw(window, dt);
	}
	player->onDraw(window, dt);
	if (settings->isDebugging())
		debugMenu.draw(window);

}

void GameScene::onUpdate(double& dt) {
	tileMap.setPosition(camera.worldToCamera(sf::Vector2f(0, 0)));
	player->onUpdate(dt);
	if (settings->isDebugging())
		updateDebug(bullets->size());

}

void GameScene::updateDebug(int bulletCount) {
	debugMenu.setBulletCount(bulletCount);
	frameCount(debugMenu.getFrameCount());
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
