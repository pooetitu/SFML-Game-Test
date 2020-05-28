#include "Game.hpp"

Game::Game(sf::RenderWindow& window) {
	Player* player = new Player(window);
	this->addEntity(player);
}
void Game::draw() {
	for (Entity* entity : entitiesList) {
		entity->onDraw();
	}
}
void Game::event(sf::Event& event) {
	for (Entity* entity : entitiesList) {
		entity->onEvent(event);
	}
}

void Game::addEntity(Entity *entity){
	this->entitiesList.push_back(entity);
}

Entity::Entity(sf::RenderWindow& window) {
	this->window = &window;
}