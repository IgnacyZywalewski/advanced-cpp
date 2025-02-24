#pragma once

#include "ofMain.h"
#include "ofxGui.h"

struct Circle {
    ofVec2f position;
    ofVec2f velocity;
    float radius;       
    float mass;
    ofColor color;

    Circle(ofVec2f pos, ofVec2f vel, float r, float m, ofColor col)
        : position(pos), velocity(vel), radius(r), mass(m), color(col) {}
};


class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

    void generateCircles();
    void applyPhysics(Circle& circle, float dt);
    float getViscosity(const ofVec2f& position);

    const int circlesNum = 1000;
    const int frameRate = 60;
    vector<Circle> circles;
    ofVec2f center;

    ofxPanel gui;
    ofxFloatSlider timeStep;
    ofxFloatSlider radiusScale;
    float prevRadiusScale;
    ofxVec2Slider centerSlider;
};
