#include <SFML/Graphics.hpp>
#include <iostream>

class DebugMenu {
private:
	sf::Text text;
	sf::Font font;
	int bulletCount;
	float frameCount;
	sf::Vector2i mapPosition;
	void initFont();
public:
	DebugMenu();
	void draw(sf::RenderWindow* window);
	void setBulletCount(int count) { bulletCount = count; };
	float* getFrameCount() { return &frameCount; };
	sf::Vector2i getMapPosition() { return mapPosition; }
};