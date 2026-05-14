#include "../include/ThreatDetector.hpp"
#include <cmath>

void ThreatDetector::analyze(RadarSystem& radar)
{
    std::lock_guard<std::mutex> lock(radar.getMutex());

    auto& objects = radar.getObjects();

    for (auto& obj : objects)
    {
        auto pos = obj.getPosition();

        float centerDistance = sqrt(
            pow(pos.x - 400, 2) +
            pow(pos.y - 300, 2)
        );

        if (centerDistance < 100)
        {
            obj.setStatus(ObjectStatus::ENEMY);
        }
        else
        {
            obj.setStatus(ObjectStatus::FRIENDLY);
        }
    }
}