#include "particle.h"

void Particle::update(float deltaTime, float gravity, const ofVec3f& platformPosition, float platformSize)
{
    velocity.y -= gravity * deltaTime;
    position += velocity * deltaTime;

    if (position.y - radius <= platformPosition.y)
    {
        if (position.x >= platformPosition.x - platformSize / 2 &&
            position.x <= platformPosition.x + platformSize / 2 &&
            position.z >= platformPosition.z - platformSize / 2 &&
            position.z <= platformPosition.z + platformSize / 2)
        {
            velocity.y = -velocity.y * 0.8f;
            position.y = platformPosition.y + radius;
        }
    }

    lifetime -= deltaTime;
}

bool Particle::isAlive() const
{
    return lifetime > 0;
}
