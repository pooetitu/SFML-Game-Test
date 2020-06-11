#include "DebugMenu.h"

DebugMenu::DebugMenu() {
	initFont();
	bulletCount = 0;
	frameCount = 0.0f;
}
void DebugMenu::initFont() {
	if (!font.loadFromFile("res/font/Arial.ttf"))
		std::cout << "err while loading font" << std::endl;
	text.setFillColor(sf::Color::Green);
	text.setCharacterSize(15);
}

void DebugMenu::draw(sf::RenderWindow* window) {
	text.setFont(font);
	std::string str;
	str.append("Frame Count: ");
	str.append(std::to_string(frameCount));
	str.append("\nBullet Count: ");
	str.append(std::to_string(bulletCount));
	str.append("\nMap x: ");
	str.append(std::to_string(mapPosition->x));
	str.append("Map y: ");
	str.append(std::to_string(mapPosition->y));
	text.setString(str);
	window->draw(text);
}

