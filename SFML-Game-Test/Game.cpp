#include "Game.hpp"

void Game::init() {
	Player* player = new Player();
	this->addEntity(player);
}
void Game::draw(sf::RenderWindow& window) {
	for (IEntity* entity : entitiesList) {
		entity->onDraw(window);
	}
	this->update();
}
void Game::event(sf::Event& event) {
	for (IEntity* entity : entitiesList) {
		entity->onEvent(event);
	}
}

void Game::update() {
	for (IEntity* entity : entitiesList) {
		entity->onUpdate();
	}
}

void Game::addEntity(IEntity *entity){
	this->entitiesList.push_back(entity);
}

void IEntity::onDraw(sf::RenderWindow& window) {

}
void IEntity::onUpdate() {

}
void IEntity::onEvent(sf::Event event) {

}