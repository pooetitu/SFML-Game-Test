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

void update(float& dt) {

}

/*void TileMap::draw(sf::RenderWindow* window) {
	for (auto const tileLayer : tileLayers)
		for (auto const chunk : tileLayer.getChunks()) {
			sf::Vector2i chunkPos(chunk.position.x, chunk.position.y);
			int tileCount = 0;
			for (auto const tile : chunk.tiles) {
				if (tile.ID > 0) {
					sf::Vector2i tilePos(camera->worldToCamera(sf::Vector2f(tileCount % chunk.size.x, tileCount / chunk.size.y)));
					sf::Sprite sprite(tileSet);
					sprite.setTextureRect(sf::IntRect(32 * ((tile.ID - 1) % (tileSet.getSize().x / 32)), 32 * ((tile.ID - 1) / (tileSet.getSize().x / 32)), 32, 32));
					sprite.setPosition(chunkPos.x + tilePos.x, chunkPos.y + tilePos.y);
					window->draw(sprite);
				}
				tileCount++;
			}
		}
}*/
