#include "../include/MovingObject.hpp"
#include <cmath>

MovingObject::MovingObject(int id, sf::Vector2f pos, float speed, float angle)
    : id(id), position(pos), speed(speed), angle(angle), radius(8.f)
{
    status = ObjectStatus::UNKNOWN;
}

void MovingObject::update(float deltaTime, sf::Vector2u bounds)
{
    position.x += speed * cos(angle) * deltaTime;
    position.y += speed * sin(angle) * deltaTime;

    if (position.x <= 0 || position.x >= bounds.x)
        angle = 3.14f - angle;

    if (position.y <= 0 || position.y >= bounds.y)
        angle = -angle;
}

void MovingObject::draw(sf::RenderWindow& window)
{
    sf::CircleShape shape(radius);

    shape.setPosition(position);

    switch (status)
    {
        case ObjectStatus::FRIENDLY:
            shape.setFillColor(sf::Color::Green);
            break;

        case ObjectStatus::ENEMY:
            shape.setFillColor(sf::Color::Red);
            break;

        default:
            shape.setFillColor(sf::Color::Yellow);
            break;
    }

    window.draw(shape);
}

sf::Vector2f MovingObject::getPosition() const
{
    return position;
}

int MovingObject::getId() const
{
    return id;
}

float MovingObject::getSpeed() const
{
    return speed;
}

ObjectStatus MovingObject::getStatus() const
{
    return status;
}

void MovingObject::setStatus(ObjectStatus s)
{
    status = s;
}