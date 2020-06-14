#include "TileMap.h"


TileMap::TileMap(tmx::Map* map, Camera* camera) : camera(camera) {
	texture.loadFromFile(map->getTilesets().at(0).getImagePath());
	mapSize = sf::Vector2i(map->getBounds().width / 32, map->getBounds().height / 32);
	sf::Vector2i tileSize(32, 32);
	const auto& layers = map->getLayers();
	for (const auto& layer : layers)
	{
		if (layer->getType() == tmx::Layer::Type::Tile)
		{
			tileLayers.push_back(layer->getLayerAs<tmx::TileLayer>());
		}
	}

	for (const auto& layer : tileLayers) {
		vertices.push_back(sf::VertexArray());
		vertices.back().setPrimitiveType(sf::Quads);
		vertices.back().resize(mapSize.x * mapSize.y * 4);


		for (int i = 0; i < mapSize.x; i++) {
			for (int j = 0; j < mapSize.y; j++) {
				if (layer.getTiles()[i + j * mapSize.x].ID > 0) {
				int tileNumber = layer.getTiles()[i + j * mapSize.x].ID - 1;

				int tu = tileNumber % (texture.getSize().x / tileSize.x);
				int tv = tileNumber / (texture.getSize().x / tileSize.x);

				sf::Vertex* quad = &vertices.back()[(i + j * mapSize.x) * 4];

				quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			}
		}
		}
	}

	for (const auto& tileset : map->getTilesets()) {
		for (const auto& tile : tileset.getTiles()) {
			for (const auto& obj : tile.objectGroup.getObjects()) {
				tileCollisions.emplace(tile.ID, obj);
				std::cout << "Collision added for tile number " << tile.ID << std::endl;
			}
		}
	}

}


void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	states.texture = &texture;
	for(const auto& vertice : vertices)
		target.draw(vertice, states);
}

void TileMap::update(float& dt) {

}

std::array<tmx::Object*, 5> TileMap::getCollisionObjects(sf::Vector2f mapPosition) {
	int mapsize = mapSize.x * mapSize.y;
	std::array<tmx::Object*, 5> objects={};
	int flattenedPosition = mapSize.x * std::floor(mapPosition.y) + std::floor(mapPosition.x);
	if (flattenedPosition>=0 && flattenedPosition < mapsize && &tileCollisions[tileLayers.at(0).getTiles().at(flattenedPosition).ID] != NULL ) {
		objects[0] = &tileCollisions[tileLayers.at(0).getTiles().at(flattenedPosition).ID];
	}
	flattenedPosition = mapSize.x * std::floor(mapPosition.y+1) + std::floor(mapPosition.x );
	if (flattenedPosition > 0 && flattenedPosition < mapsize && &tileCollisions[tileLayers.at(0).getTiles().at(flattenedPosition).ID] != NULL) {
		objects[1] = &tileCollisions[tileLayers.at(0).getTiles().at(flattenedPosition).ID];
	}
	flattenedPosition = mapSize.x * std::floor(mapPosition.y-1) + std::floor(mapPosition.x );
	if (flattenedPosition > 0 && flattenedPosition < mapsize && &tileCollisions[tileLayers.at(0).getTiles().at(flattenedPosition).ID] != NULL) {
		objects[2] = &tileCollisions[tileLayers.at(0).getTiles().at(flattenedPosition).ID];
	}
	flattenedPosition = mapSize.x * std::floor(mapPosition.y) + std::floor(mapPosition.x+1);
	if (flattenedPosition > 0 && flattenedPosition < mapsize && &tileCollisions[tileLayers.at(0).getTiles().at(flattenedPosition).ID] != NULL) {
		objects[3] = &tileCollisions[tileLayers.at(0).getTiles().at(flattenedPosition).ID];
	}
	flattenedPosition = mapSize.x * std::floor(mapPosition.y) + std::floor(mapPosition.x-1);
	if (flattenedPosition > 0 && flattenedPosition < mapsize && &tileCollisions[tileLayers.at(0).getTiles().at(flattenedPosition).ID] != NULL) {
		objects[4] = &tileCollisions[tileLayers.at(0).getTiles().at(flattenedPosition).ID];
	}
	return objects;
}

