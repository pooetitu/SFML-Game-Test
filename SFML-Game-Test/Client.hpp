#pragma once
#include <SFML/Graphics.hpp>


class Client {
private:
	sf::RenderWindow window;

public:
	void init();
	void start();
};