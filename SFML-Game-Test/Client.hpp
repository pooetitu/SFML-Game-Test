#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/filesystem.hpp>

#include "Game.hpp"


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
	Game* game;
	Config config;
	void loadConfig();
	void saveConfig();

public:
	Client();
	void start();
};