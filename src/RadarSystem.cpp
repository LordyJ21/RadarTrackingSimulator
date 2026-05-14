#include "../include/RadarSystem.hpp"

void RadarSystem::addObject(const MovingObject& obj)
{
    std::lock_guard<std::mutex> lock(mtx);
    objects.push_back(obj);
}

void RadarSystem::update(float deltaTime, sf::Vector2u bounds)
{
    std::lock_guard<std::mutex> lock(mtx);

    for (auto& obj : objects)
    {
        obj.update(deltaTime, bounds);
    }
}

std::vector<MovingObject>& RadarSystem::getObjects()
{
    return objects;
}

std::mutex& RadarSystem::getMutex()
{
    return mtx;
}