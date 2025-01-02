#pragma once
#include "ofMain.h"

class Particle {
public:
    Particle(const ofVec2f& pos, const ofVec2f& vel, const ofColor& col, int rad, float lifetime)
        : position(pos), velocity(vel), color(col), radius(rad), lifetime(lifetime)
    {
        movingRight = ofRandomuf() > 0.5f;
    }

    void updateGravity(float deltaTime, float gravity)
    {
        velocity.y += gravity * deltaTime;
        position.y += velocity.y * deltaTime;
        position.x += velocity.x * deltaTime;

        lifetime -= deltaTime;
    }

    void updateOffset(float deltaTime)
    {
        if (movingRight) 
        {
            position.x += horizontalSpeed * deltaTime;
            if (position.x >= initialX + horizontalRange) { movingRight = false;  }
        }
        else 
        {
            position.x -= horizontalSpeed * deltaTime;
            if (position.x <= initialX - horizontalRange) { movingRight = true; }
        }
    }

    void updateFireworks(float deltaTime)
    {
        position.y += velocity.y * deltaTime;
        position.x += velocity.x * deltaTime;

        lifetime -= deltaTime;
        if (lifetime <= 0) 
        {
            alpha = ofMap(lifetime, 0, -maxLifetime/3, 255, 0, true);
        }
    }

    bool isAlive() const
    {
        return lifetime + 1.0f > 0;
    }

    const ofVec2f& getPosition() const { return position; }
    const ofVec2f& getVelocity() const { return velocity; }
    const ofColor& getColor() const { return color; }
    const int getRadius() const { return radius; }
    const float getLifetime() const { return lifetime; }
    const float getAlpha() const { return alpha;  }


private:
    ofVec2f position;
    ofVec2f velocity;
    ofColor color;
    int radius;
    float lifetime;
    float maxLifetime = lifetime + 1.0f;

    float horizontalRange = 20.0f;
    float horizontalSpeed = 10.0f;
    bool movingRight;
    float initialX = position.x;
    float alpha = 255;
};