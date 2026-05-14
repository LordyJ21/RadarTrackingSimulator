#include "../include/RadarSystem.hpp"
#include "../include/Renderer.hpp"
#include "../include/ThreatDetector.hpp"
#include "../include/CollisionEngine.hpp"

#include <thread>
#include <chrono>

int main()
{
    RadarSystem radar;

    Renderer renderer;

    ThreatDetector detector;

    CollisionEngine collisionEngine;

    radar.addObject(MovingObject(1, {100, 100}, 100.f, 0.5f));
    radar.addObject(MovingObject(2, {300, 200}, 120.f, 1.0f));
    radar.addObject(MovingObject(3, {500, 400}, 90.f, 2.5f));

    bool running = true;

    std::thread updateThread([&]()
    {
        while (running)
        {
            radar.update(0.016f, {800, 600});

            detector.analyze(radar);

            collisionEngine.detect(radar);

            std::this_thread::sleep_for(
                std::chrono::milliseconds(16)
            );
        }
    });

    while (renderer.isOpen())
    {
        renderer.render(radar);
    }

    running = false;

    updateThread.join();

    return 0;
}