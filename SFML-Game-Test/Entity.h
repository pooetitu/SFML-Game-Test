#pragma once
#include <SFML/Graphics.hpp>

typedef struct GameData GameData;

class Entity {
public:
	Entity(sf::Texture* texture, GameData* data) {
		if (texture != NULL)sprite.setTexture(*texture);
		this->gameData = data;
	}
	virtual ~Entity() {}
	virtual void onDraw(sf::RenderWindow* window, double& dt) = 0;
	virtual void onUpdate(double& dt) = 0;
	sf::Vector2f* getPosition() { return &mapPosition; }
	sf::FloatRect* getHitBox() { return hitBox; }
protected:
	GameData* gameData;
	sf::FloatRect* hitBox;
	sf::Vector2f velocity;
	sf::Vector2f mapPosition;
	sf::Sprite sprite;
};
