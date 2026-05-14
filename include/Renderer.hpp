#pragma once

#include "RadarSystem.hpp"
#include <SFML/Graphics.hpp>

class Renderer
{
private:
    sf::RenderWindow window;

public:
    Renderer();

    bool isOpen();

    void render(RadarSystem& radar);

    sf::RenderWindow& getWindow();
};