#pragma once
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/Tileset.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <tmxlite/Map.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <array>
#include <iostream>
#include "Camera.h"

class TileMap : public sf::Drawable, public sf::Transformable  {
private:
	std::vector<tmx::TileLayer> tileLayers;
	std::vector<sf::VertexArray> vertices;
	sf::Vector2i mapSize;
	std::map<int, tmx::Object> tileCollisions;
	sf::Texture texture;
	Camera* camera;
public:
	TileMap() {}
	TileMap(tmx::Map* map, Camera* camera);
	std::map<int, tmx::Object>* getTileCollisions() { return &tileCollisions; }
	std::array<tmx::Object*, 5> getCollisionObjects(sf::Vector2f mapPosition);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(float& dt);
};