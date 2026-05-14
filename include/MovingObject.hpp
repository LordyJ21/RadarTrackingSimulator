#pragma once

#include <SFML/Graphics.hpp>
#include <string>

enum class ObjectStatus
{
    FRIENDLY,
    UNKNOWN,
    ENEMY
};

class MovingObject
{
private:
    int id;
    sf::Vector2f position;
    float speed;
    float angle;
    float radius;
    ObjectStatus status;

public:
    MovingObject(int id, sf::Vector2f pos, float speed, float angle);

    void update(float deltaTime, sf::Vector2u bounds);

    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    int getId() const;
    float getSpeed() const;
    ObjectStatus getStatus() const;

    void setStatus(ObjectStatus s);
};