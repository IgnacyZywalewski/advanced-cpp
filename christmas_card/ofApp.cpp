#include "ofApp.h"

void ofApp::setup()
{
	ofBackground(0, 0, 30);
	font.load("font.ttf", 100, true, true);
}

void ofApp::update()
{
	float currentTime = ofGetElapsedTimef();
	float deltaTime = currentTime - lastFrameTime;
	lastFrameTime = currentTime;

	snowEmiter.update(deltaTime);
	fireworks.update(deltaTime);
	stars.update(deltaTime);
}

void ofApp::draw()
{
	drawGround(0, ofGetHeight() - 260, ofGetWidth(), 260);

	fireworks.draw();
	stars.draw();

	drawChristmasTree(180, 160, 220, 450, { 0, 128, 0 });
    drawChristmasTree(20, 100, 250, 600, { 34, 139, 34 });

	drawChristmasTree(ofGetWidth() - 400, 160, 220, 450, {0, 128, 0});
	drawChristmasTree(ofGetWidth() - 270, 100, 250, 600, { 34, 139, 34 });
	
	snowEmiter.drawParticles();

	ofSetColor(255, 255, 255);
	font.drawString("Merry Christmas", ofGetWidth()/2 - 320, ofGetHeight()/2 - 100);
}	
