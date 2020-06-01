#include "GameScene.h"

GameScene::GameScene (Settings* settings, sf::RenderWindow* window) : Scene(settings) {
	initRessources();
	debugMenu = DebugMenu();
	bullets = new std::list<Bullet*>();
	player = new Player(NULL, &ressources["BULLET"], window, bullets);
	std::cout << "Loaded GameScene" << std::endl;
	
}
void GameScene::initRessources() {
	sf::Clock cl;
	sf::Texture texture;
	if (!ressources["BULLET"].loadFromFile("res/sprite/bullet.png")) { 
		std::cout << "failed" << std::endl;
	}
	std::cout << cl.restart().asMilliseconds() << "millisec" << std::endl;
}

void GameScene::onDraw(sf::RenderWindow* window, double& dt) {
	std::list<Bullet*> toKeep;
	int count = 0;
	for (iter = bullets->begin(); iter != bullets->end(); ++iter) {
		count++;
		(*iter)->onDraw(window, dt);
		(*iter)->onUpdate(dt);
		if (!checkBulletPosition(window, *iter)) {
			toKeep.push_back(*iter);
		}
	}
	bullets->swap(toKeep);
	player->onDraw(window,dt);
	if (settings->isDebugging())
		updateDebug(window, count);
}

bool GameScene::checkBulletPosition(sf::RenderWindow* window,Bullet* bullet) {
	return bullet->getPosition().x > window->getSize().x || bullet->getPosition().y > window->getSize().y ||
		0 > bullet->getPosition().x || 0 > bullet->getPosition().y;
}

void GameScene::updateDebug(sf::RenderWindow* window, int& bulletCount) {
	debugMenu.setBulletCount(bulletCount);
	frameCount(debugMenu.getFrameCount());
	debugMenu.draw(window);
}

void GameScene::frameCount(float* fps) {
	static sf::Clock timer;
	static sf::Clock printTimer;
	static int numFrames = 0;
	numFrames++;
	if (printTimer.getElapsedTime().asSeconds() >= 1.0f) {
		*fps = (float)numFrames / timer.getElapsedTime().asSeconds();
		printTimer.restart();
		numFrames = 0;
		timer.restart();
	}
}