#include "fireworks.h"

//eksplozja
void Fireworks::createParticles()
{
    for (size_t i = 0; i < particleNumber; i++)
    {
        float angle = ofRandom(0, TWO_PI);
        float speed = ofRandom(1, 50);

        float x = cos(angle) * speed;
        float y = sin(angle) * speed;
        ofVec2f velocity = { x, y };

        ofColor color = ofColor::fromHsb(ofRandom(255), 255, 255);

        particles.emplace_back(startPosition, velocity, color, radius, lifetime);
    }
}

void Fireworks::update(float deltaTime)
{
    for (auto it = particles.begin(); it != particles.end(); )
    {
        it->updateFireworks(deltaTime);

        if (!it->isAlive()) it = particles.erase(it);
        else ++it;
    }
}

void Fireworks::draw()
{
    for (auto& particle : particles)
    {
        ofSetColor(particle.getColor(), particle.getAlpha());
        ofDrawCircle(particle.getPosition(), particle.getRadius());
    }
}


//generator fajerwerkow
void FireworksGenerator::update(float deltaTime)
{
    for (auto it = explosions.begin(); it != explosions.end(); )
    {
        it->update(deltaTime);

        if (!it->isAlive()) it = explosions.erase(it);
        else ++it;
    }

    timeSinceLastExplosion += deltaTime;
    if (timeSinceLastExplosion >= explosionInterval)
    {
        createExplosion();
        timeSinceLastExplosion = 0.0f;
    }
}

void FireworksGenerator::draw()
{
    for (auto& explosion : explosions)
    {
        explosion.draw();
    }
}

void FireworksGenerator::createExplosion()
{
    ofVec2f position(ofRandom(100, ofGetWidth() - 100), ofRandom(50, ofGetHeight() / 3));
    Fireworks newExplosion(position);
    newExplosion.createParticles();
    explosions.push_back(newExplosion);
}
