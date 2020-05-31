#include "GameScene.h"

GameScene::GameScene(sf::RenderWindow* window) : Scene() {
	initRessources();
	bullets = new std::list<Bullet*>();
	player = new Player(NULL, &ressources["BULLET"], window, bullets);
	std::cout << "Loaded GameScene" << std::endl;
	
}
void GameScene::initRessources() {
	sf::Image image;
	if (!ressources["BULLET"].loadFromFile("res/sprite/bullet.png")) { 
		std::cout << "failed" << std::endl;
	}
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
	std::cout << count << std::endl;
	player->onDraw(window,dt);
}

bool GameScene::checkBulletPosition(sf::RenderWindow* window,Bullet* bullet) {
	return bullet->getPosition().x > window->getSize().x || bullet->getPosition().y > window->getSize().y ||
		0 > bullet->getPosition().x || 0 > bullet->getPosition().y;
}