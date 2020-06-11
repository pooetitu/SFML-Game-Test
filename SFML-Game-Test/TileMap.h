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
	std::vector<tmx::TileLayer> tileLayers;
	std::vector<sf::IntRect> collisionRects;
	sf::Texture tileSet;
	sf::Vector2f* offsetPosition = NULL;
public:
	TileMap(){}
	TileMap(tmx::Map* map, sf::Vector2f* offsetPosition);
	std::vector<sf::IntRect>& getCollision() { return collisionRects; }
	void draw(sf::RenderWindow* window);
	void update(float& dt);
};