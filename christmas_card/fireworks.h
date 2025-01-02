#pragma once
#include "particle.h"
#include "ofMain.h"

class Fireworks {
public:
    Fireworks(const ofVec2f& position)
        : startPosition(position){

        lifetime = ofRandom(2.0f, 3.0f);
        radius = ofRandom(1, 3);
    }

    void createParticles();
    void update(float deltaTime);
    void draw();
    bool isAlive() const { return !particles.empty(); }

private:
    std::vector<Particle> particles;
    size_t particleNumber = 1000;
    ofVec2f startPosition;
    int radius;
    float lifetime;
};



class FireworksGenerator {
public:
    void update(float deltaTime);
    void draw();

private:
    void createExplosion();

    std::vector<Fireworks> explosions;
    float explosionInterval = 1.0f;
    float timeSinceLastExplosion = 0.0f;
};