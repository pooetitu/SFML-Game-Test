#include "Game.hpp"

Game::Game(sf::RenderWindow* window) {
	this->entities = new std::list<Entity*>();
	this->window = window;
	entities->push_back(new Player(this));
	
}
void Game::draw() {
	for (iter = entities->begin(); iter != entities->end(); ++iter)
		(*iter)->onDraw();
}
void Game::event(sf::Event& event) {
	for (iter = entities->begin(); iter != entities->end(); ++iter)
		(*iter)->onEvent(event);
}

