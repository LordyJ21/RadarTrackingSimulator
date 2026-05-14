#include "../include/Renderer.hpp"

Renderer::Renderer()
    : window(sf::VideoMode(800, 600), "RADAR Tracking Simulator")
{
    window.setFramerateLimit(60);
}

bool Renderer::isOpen()
{
    return window.isOpen();
}

void Renderer::render(RadarSystem& radar)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear(sf::Color::Black);

    sf::CircleShape radarCircle(200);
    radarCircle.setFillColor(sf::Color::Transparent);
    radarCircle.setOutlineColor(sf::Color::Green);
    radarCircle.setOutlineThickness(2);
    radarCircle.setPosition(200, 100);

    window.draw(radarCircle);

    {
        std::lock_guard<std::mutex> lock(radar.getMutex());

        for (auto& obj : radar.getObjects())
        {
            obj.draw(window);
        }
    }

    window.display();
}

sf::RenderWindow& Renderer::getWindow()
{
    return window;
}