#pragma once
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Tileset.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/Map.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class TileMap {
private:
	tmx::ObjectGroup objectLayer;
	std::vector<tmx::TileLayer> tileLayers ;
	sf::Texture tileSet;
	sf::Vector2i offsetPosition;
public:
	TileMap(){}
	TileMap(tmx::Map* map);
	void draw(sf::RenderWindow* window);
	void update(float& dt);
};