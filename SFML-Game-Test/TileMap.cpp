#include "TileMap.h"


TileMap::TileMap(tmx::Map* map) {
	const auto& layers = map->getLayers();
	for (const auto& layer : layers)
	{
		if (layer->getType() == tmx::Layer::Type::Object)
		{
			objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
		}
		else if (layer->getType() == tmx::Layer::Type::Tile)
		{
			tileLayers.push_back(layer->getLayerAs<tmx::TileLayer>());
		}
	}
	tileSet.loadFromFile(map->getTilesets().at(0).getImagePath());
}


void TileMap::draw(sf::RenderWindow* window) {
	for(auto const tileLayer : tileLayers)
	for (auto const chunk : tileLayer.getChunks()) {
		sf::Vector2i chunkPos(chunk.position.x, chunk.position.y);
		int tileCount = 0;
		for (auto const tile : chunk.tiles) {
			if (tile.ID > 0) {
				sf::Vector2i tilePos((tileCount % chunk.size.x) * 32, (tileCount / chunk.size.y) * 32);
				sf::Sprite sprite(tileSet);
				sprite.setTextureRect(sf::IntRect(32 * ((tile.ID - 1) % (tileSet.getSize().x/32)), 32 * ((tile.ID - 1) / (tileSet.getSize().y/32)), 32, 32));
				sprite.setPosition(chunkPos.x + tilePos.x, chunkPos.y + tilePos.y);
				window->draw(sprite);
			}
			tileCount++;
		}
	}

}
