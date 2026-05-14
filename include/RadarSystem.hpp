#pragma once

#include "MovingObject.hpp"
#include <vector>
#include <mutex>

class RadarSystem
{
private:
    std::vector<MovingObject> objects;
    std::mutex mtx;

public:
    void addObject(const MovingObject& obj);

    void update(float deltaTime, sf::Vector2u bounds);

    std::vector<MovingObject>& getObjects();

    std::mutex& getMutex();
};