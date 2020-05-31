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
	for (iter = bullets->begin(); iter != bullets->end(); ++iter) {
		(*iter)->onDraw(window, dt);
		(*iter)->onUpdate(dt);
	}
	player->onDraw(window,dt);
}

