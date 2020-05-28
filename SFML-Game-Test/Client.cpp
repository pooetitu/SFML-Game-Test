#include "Client.hpp"



void Client::init() {
    game.init();
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window.create(sf::VideoMode(800, 600), "SFML game test", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);
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
        game.draw(window);
        window.display();
    }
}