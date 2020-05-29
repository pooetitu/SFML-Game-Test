#include "Client.hpp"

Client::Client() {
    this->loadConfig();
    sf::ContextSettings settings;
    settings.antialiasingLevel = config.antialiasingLevel;
    window.create(sf::VideoMode(config.width, config.height), "SFML game test", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(config.framerate);
    window.setVerticalSyncEnabled(config.vSync);
    game = new Game(&window);

}

void Client::start() {
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else
                game->event(event);
        }
        window.clear(sf::Color::White);
        game->draw();
        window.display();

    }
}

void Client::loadConfig() {
    boost::property_tree::ptree tree;
    tree.put("config.width",config.width);
    boost::filesystem::path fullPath(boost::filesystem::current_path());
    fullPath.append("\\config\\config.ini");
    try {
        if (exists(fullPath) && is_regular_file(fullPath) && !is_empty(fullPath)) {
            boost::property_tree::read_ini(fullPath.string(), tree);
            config.antialiasingLevel = tree.get<char>("config.antialiasingLevel");
            config.framerate = tree.get<int>("config.framerate");
            config.fullscreen = tree.get<bool>("config.fullscreen");
            config.height = tree.get<int>("config.height");
            config.width = tree.get<int>("config.width");
            config.vSync = tree.get<bool>("config.vSync");
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
        boost::property_tree::ptree tree;
        boost::filesystem::path fullPath(boost::filesystem::current_path());
        fullPath.append("\\config\\config.ini");
        boost::filesystem::path dirPath(fullPath);
        boost::filesystem::create_directories(dirPath.parent_path());
        tree.put("config.antialiasingLevel",config.antialiasingLevel);
        tree.put("config.framerate",config.framerate);
        tree.put("config.fullscreen",config.fullscreen);
        tree.put("config.height",config.height);
        tree.put("config.width",config.width);
        tree.put("config.vSync",config.vSync);
        boost::property_tree::write_ini(fullPath.string(),tree);
    } catch (const boost::filesystem::filesystem_error& err) {
        std::cerr << err.what() << std::endl;
    }
}