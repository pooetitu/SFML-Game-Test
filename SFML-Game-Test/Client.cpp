#include "Client.h"

Client::Client() {
    this->loadConfig();
    sf::ContextSettings render;
    RenderSettings* renderSettings = settings.getRenderSettings();
    render.antialiasingLevel = renderSettings->antialiasingLevel;
    window.create(sf::VideoMode(renderSettings->width, renderSettings->height), "SFML game test", sf::Style::Titlebar | sf::Style::Close, render);
    window.setFramerateLimit(renderSettings->framerate);
    window.setVerticalSyncEnabled(renderSettings->vSync);
    scenes = new std::vector<Scene*>();
    scenes->push_back(new GameScene(&settings, &window));
}

void Client::start() {
    sf::Clock clock;
    double dt;
    while (window.isOpen()) {
        dt = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased) 
                if(event.key.code == sf::Keyboard::Key(settings.getKeyBinds()->debugMenu))
                    settings.toggleDebug();
            

        }
        window.clear(sf::Color::White);
        scenes->back()->onDraw(&window,dt);
        window.display();
    }
}

void Client::loadConfig() {
    RenderSettings* renderSettings = settings.getRenderSettings();
    boost::property_tree::ptree tree;
    tree.put("config.width", renderSettings->width);
    boost::filesystem::path fullPath(boost::filesystem::current_path());

    std::cout << fullPath.string() << std::endl;
    fullPath.append("\\config\\config.ini");
    try {
        if (exists(fullPath) && is_regular_file(fullPath) && !is_empty(fullPath)) {
            boost::property_tree::read_ini(fullPath.string(), tree);
            renderSettings->antialiasingLevel = tree.get<char>("config.antialiasingLevel");
            renderSettings->framerate = tree.get<int>("config.framerate");
            renderSettings->fullscreen = tree.get<bool>("config.fullscreen");
            renderSettings->height = tree.get<int>("config.height");
            renderSettings->width = tree.get<int>("config.width");
            renderSettings->vSync = tree.get<bool>("config.vSync");
        }
        else {
            saveConfig();
        }
    }
    catch (const boost::filesystem::filesystem_error& err) {
        std::cerr << err.what() << std::endl;
    }
}

void Client::saveConfig() {
    try {
        RenderSettings* renderSettings = settings.getRenderSettings();
        boost::property_tree::ptree tree;
        boost::filesystem::path fullPath(boost::filesystem::current_path());
        fullPath.append("\\config\\config.ini");
        boost::filesystem::path dirPath(fullPath);
        boost::filesystem::create_directories(dirPath.parent_path());
        tree.put("config.antialiasingLevel", renderSettings->antialiasingLevel);
        tree.put("config.framerate", renderSettings->framerate);
        tree.put("config.fullscreen", renderSettings->fullscreen);
        tree.put("config.height", renderSettings->height);
        tree.put("config.width", renderSettings->width);
        tree.put("config.vSync", renderSettings->vSync);
        boost::property_tree::write_ini(fullPath.string(),tree);
    } catch (const boost::filesystem::filesystem_error& err) {
        std::cerr << err.what() << std::endl;
    }
}