#include "snow.h"

void Snow::generateParticle()
{
	float positionX = ofRandomWidth();
	float positionY = -50.0f;
	ofVec2f position = { positionX , positionY };

	float radius = ofRandom(1, 3);

	snow_particles.emplace_back(position, velocity, color, radius, lifetime);
}

void Snow::update(float deltaTime)
{
	for (auto it = snow_particles.begin(); it != snow_particles.end(); )
	{
		it->updateGravity(deltaTime, gravity);
		it->updateOffset(deltaTime);

		if (!it->isAlive()) it = snow_particles.erase(it);
		else it++;
	}

	timeSinceLastParticle += deltaTime;
	if (timeSinceLastParticle >= spawnTime)
	{
		generateParticle();
		timeSinceLastParticle = 0.0f;
	}
}

void Snow::drawParticles()
{
	for (auto &particle : snow_particles)
	{
		ofSetColor(color);
		ofDrawCircle(particle.getPosition(), particle.getRadius());
	}
}