#include <SFML/Graphics.hpp>
#include "Client.hpp"


void Client::init() {
    window.create(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
}

void Client::start() {
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}