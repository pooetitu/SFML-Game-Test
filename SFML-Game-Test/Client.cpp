#include "Client.hpp"


Client::Client() {
    this->loadConfig();
    sf::ContextSettings settings;
    settings.antialiasingLevel = config.antialiasingLevel;
    window.create(sf::VideoMode(config.width, config.height), "SFML game test", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(config.framerate);
    window.setVerticalSyncEnabled(config.vSync);
    game = Game(window);

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
                game.event(event);
        }
        window.clear(sf::Color::Black);
        game.draw();
        window.display();
    }
}

void Client::loadConfig() {
    std::string location = std::getenv("USERPROFILE");
    if (location != "") {
    location.append("\\documents\\file.json");
    std::cout << location << std::endl;
    std::ifstream file(location);
    /*if (file.is_open()) {
        std::cout << "open" << std::endl;
        json j;
        file >> j;
    }
    else {
        std::ofstream fileO(location);
        fileO.close();
    }*/
}
}