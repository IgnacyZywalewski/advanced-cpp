#include "star.h"

void Star::update(float deltaTime)
{
    position += speed * deltaTime;
    speed.y += gravity * deltaTime;
    lifetime -= deltaTime;
}

void Star::draw() const
{
    ofSetColor(255, 255, 0);
    drawStar(position.x, position.y, radius1, radius2, points);
}

void StarGenerator::update(float deltaTime)
{
    timeSinceLastStar += deltaTime;

    if (timeSinceLastStar >= starInterval)
    {
        createStar();
        timeSinceLastStar = 0.0f;
    }

    for (auto& star : stars)
    {
        star.update(deltaTime);
    }

    stars.erase(std::remove_if(stars.begin(), stars.end(),
        [](const Star& star) { return !star.isAlive(); }), stars.end());

}


void StarGenerator::draw() const
{
    for (const auto& star : stars)
    {
        star.draw();
    }
}

void StarGenerator::createStar()
{
    bool spawnLeft = ofRandom(1.0f) < 0.5f;
    float startX = spawnLeft ? -100.0f : ofGetWidth() + 100.0f;
    float startY = ofRandom(200.0f, (ofGetHeight() / 2.0f) - 200.0f);

    float speedX = spawnLeft ? ofRandom(200, 300) : -ofRandom(200, 300);
    float speedY = -ofRandom(50, 70);

    ofVec2f position(startX, startY);
    ofVec2f speed(speedX, speedY);
    float radius1 = ofRandom(15, 20);
    float radius2 = ofRandom(5, 10);
    int points = 5;

    stars.emplace_back(position, speed, radius1, radius2, points);
}