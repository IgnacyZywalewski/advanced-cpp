#pragma once

#include "ofMain.h"
#include "snow.h"
#include "fireworks.h"
#include "star.h"
#include "objects.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

private:
	Snow snowEmiter;
	FireworksGenerator fireworks;
	StarGenerator stars;

	float lastFrameTime = 0.0f;
	float timeSinceLastExplosion = 0.0f;
	float explosionInterval = 5.0f;

	ofTrueTypeFont font;
};