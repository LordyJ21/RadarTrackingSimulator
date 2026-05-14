#pragma once

class RadarScanner
{
private:
    float angle;

public:
    RadarScanner();

    void update(float speed);

    float getAngle() const;
};