#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <json.hpp>

using json = nlohmann::json;

typedef struct Config Config;

struct Config {
	int height = 600;
	int width = 800;
	int framerate = 60;
	char antialiasingLevel = 0;
	bool fullscreen = false;
	bool vSync = false;

};

class Client {
private:
	sf::RenderWindow window;
	Game game;
	Config config;
	void loadConfig();


public:
	Client();
	void start();
};