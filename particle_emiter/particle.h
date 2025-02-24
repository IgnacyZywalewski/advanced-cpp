#pragma once
#include "ofMain.h"

class Particle {
public:
    Particle(const ofVec3f& pos, const ofVec3f& vel, const ofColor& col, int rad, float life)
        : position(pos), velocity(vel), color(col), radius(rad), lifetime(life) { }

    void update(float deltaTime, float gravity, const ofVec3f& platformPosition, float platformSize);
    bool isAlive() const;

    const ofVec3f& getPosition() const { return position; }
    const ofColor& getColor() const { return color; }
    const int getRadius() const { return radius; }
    const ofVec3f& getVelocity() const { return velocity; }
    void setVelocity(ofVec3f newVelocity) { velocity = newVelocity; }

private:
    ofVec3f position;
    ofVec3f velocity;
    ofColor color;
    int radius;
    float lifetime;
};