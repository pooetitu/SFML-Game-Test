#pragma once
#include <SFML/Graphics.hpp>

typedef struct RenderSettings RenderSettings;

struct RenderSettings {
	int height = 600;
	int width = 800;
	int framerate = 60;
	char antialiasingLevel = 0;
	bool fullscreen = false;
	bool vSync = false;
};

typedef struct KeyBinds KeyBinds;

struct KeyBinds {
	int debugMenu = sf::Keyboard::Key::F1;
	int up;
	int down;
	int left;
	int right;
	int shoot;
};

class Settings {
private:
#if NDEBUG
	bool debugging = true;
#else
	bool debugging = false;
#endif
	RenderSettings renderSettings;
	KeyBinds keyBinds;
public:
	bool isDebugging() { return debugging; }
	void toggleDebug() { debugging ^= 1; }
	RenderSettings* getRenderSettings() { return &renderSettings; }
	KeyBinds* getKeyBinds() { return &keyBinds; }
};