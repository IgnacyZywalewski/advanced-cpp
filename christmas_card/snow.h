#pragma once
#include "particle.h"
#include "ofMain.h"

class Snow {

public:
	void generateParticle();
	void update(float deltaTime);
	void drawParticles();

private:
	std::vector<Particle> snow_particles;

	ofColor color = 255;
	ofVec2f velocity = { 0.0f , 0.0f };
	float lifetime = 30.0f;
	float gravity = 10.0f;

	float timeSinceLastParticle = 0.0f;
	float spawnTime = 0.00001f;
};