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
	int up;
	int down;
	int left;
	int right;
	int shoot;
};

class Settings {
private:
	RenderSettings renderSettings;
	KeyBinds keyBinds;
public:
	RenderSettings* getRenderSettings() { return &renderSettings; }
	KeyBinds* getKeyBinds() { return &keyBinds; }
};