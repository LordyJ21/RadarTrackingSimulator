#include "../include/RadarScanner.hpp"

RadarScanner::RadarScanner()
{
    angle = 0.f;
}

void RadarScanner::update(float speed)
{
    angle += speed;

    if (angle > 360.f)
        angle = 0.f;
}

float RadarScanner::getAngle() const
{
    return angle;
}