#include "GameScene.h"

GameScene::GameScene(sf::RenderWindow* window) : Scene() {
	bullets = new std::list<Bullet*>();
	player = new Player(window, bullets);
	
}
void GameScene::onDraw(sf::RenderWindow* window, double& dt) {
	for (iter = bullets->begin(); iter != bullets->end(); ++iter)
		(*iter)->onDraw(window,dt);
	player->onDraw(window,dt);
}
void GameScene::onEvent( sf::Event event, double& dt) {
	player->onEvent(event,dt);
	for (iter = bullets->begin(); iter != bullets->end(); ++iter)
		(*iter)->onEvent(event,dt);
}

