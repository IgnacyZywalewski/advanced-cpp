#include "emiter.h"
#include "particle.h"

void Emiter::update(float deltaTime, float lifetime, float spawnTime, float gravity)
{
    for (auto it = particles.begin(); it != particles.end();)
    {
        it->update(deltaTime, gravity, platformPosition, platformSide);

        if (!it->isAlive())
            it = particles.erase(it);
        else
            ++it;
    }

    timeSinceLastParticle += deltaTime;
    if (timeSinceLastParticle >= spawnTime)
    {
        generateParticle(lifetime);
        timeSinceLastParticle = 0.0f;
    }
}


void Emiter::generateParticle(float lifetime)
{
    float x = ofRandom(-50, 50) * velocityScale.x;
    float y = ofRandom(250, 300) * velocityScale.y;
    float z = ofRandom(-50, 50) * velocityScale.z;
    ofVec3f velocity = { x, y, z };

    ofColor color = ofColor::fromHsb(ofRandom(255), 255, 255);
    int radius = ofRandom(1, 5);

    particles.emplace_back(position, velocity, color, radius, lifetime);
}

void Emiter::drawEmiter() 
{
    ofSetColor(255);
    ofDrawSphere(position, 10);
}

void Emiter::drawParticles(float radiusScale) 
{
    for (const auto& particle : particles) 
    {
        ofSetColor(particle.getColor());
        ofDrawSphere(particle.getPosition(), particle.getRadius() * radiusScale);
    }
}

void Emiter::drawPlatform()
{
    ofSetColor(128);
    ofPushMatrix();
    ofTranslate(platformPosition);
    ofRotateXDeg(90);
    ofDrawRectangle(-platformSide / 2, -platformSide / 2, platformSide, platformSide);
    ofPopMatrix();
}
