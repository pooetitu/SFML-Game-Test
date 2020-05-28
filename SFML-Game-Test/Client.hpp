#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
class Client {
private:
	sf::RenderWindow window;
	Game game;

public:
	void init();
	void start();
};