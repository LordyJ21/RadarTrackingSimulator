#include "../include/CollisionEngine.hpp"
#include "../include/Logger.hpp"

void CollisionEngine::detect(RadarSystem& radar)
{
    std::lock_guard<std::mutex> lock(radar.getMutex());

    auto& objects = radar.getObjects();

    for (size_t i = 0; i < objects.size(); ++i)
    {
        for (size_t j = i + 1; j < objects.size(); ++j)
        {
            auto p1 = objects[i].getPosition();
            auto p2 = objects[j].getPosition();

            float dx = p1.x - p2.x;
            float dy = p1.y - p2.y;

            float distance = sqrt(dx * dx + dy * dy);

            if (distance < 20)
            {
                Logger::log("Collision Alert!");
            }
        }
    }
}