#pragma once
#include "ofMain.h"
#include "objects.h"

class Star {
public:
    Star(const ofVec2f& position, const ofVec2f& speed, float radius1, float radius2, int points)
        : position(position), speed(speed), radius1(radius1), radius2(radius2), points(points) {}

    void update(float deltaTime);
    void draw() const;
    bool isAlive() const { return lifetime > 0; }

private:
    ofVec2f position;
    ofVec2f speed;
    float radius1, radius2;
    int points;
    float lifetime = 10.0f;
    float gravity = 20.0f;
};


class StarGenerator {
public:
    void update(float deltaTime);
    void draw() const;

private:
    void createStar();

    std::vector<Star> stars;
    float starInterval = 3.0f;
    float timeSinceLastStar = 0.0f;
};
