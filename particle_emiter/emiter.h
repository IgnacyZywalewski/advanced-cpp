#pragma once

#include "ofMain.h"
#include "particle.h"

class Emiter {
public:
	void drawEmiter();
	void drawPlatform();
	void setPosition(ofVec3f newPosition) { position = newPosition; }
	void generateParticle(float lifetime);
	void drawParticles(float radiusScale);
	void update(float deltaTime, float lifetime, float spawnTime, float gravity);
	void setVelocityScale(ofVec3f scale) { velocityScale = scale; }
	

private:
	std::vector<Particle> particles;

	float timeSinceLastParticle = 0.0f;

	ofVec3f velocityScale = { 1.0f, 1.0f, 1.0f };
	ofVec3f position = { 0.0f, 0.0f, 0.0f };

	float platformSide = 1000.0f;
	ofVec3f platformPosition = { 0, -200, 0 };
};