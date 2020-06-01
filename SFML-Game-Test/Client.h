#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <stack>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/filesystem.hpp>

#include "GameScene.h"
#include "Scene.h"
#include "Settings.h"

class Client {
private:
	sf::RenderWindow window;
	std::vector<Scene*>* scenes;
	Settings settings;
	void loadConfig();
	void saveConfig();

public:
	Client();
	void start();
};