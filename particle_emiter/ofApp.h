#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "emiter.h"

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseScrolled(ofMouseEventArgs& args);

private:
    ofCamera cam;
    bool isDragging = false;
    int activeButton = -1;
    ofVec2f lastMouse;
    float rotationX = 0.0f;
    float rotationY = 0.0f;
    ofVec3f cameraPosition;

    Emiter emiter;
    float lastFrameTime = 0.0f;

    ofxPanel gui;
    ofxFloatSlider radiusScale;
    ofxFloatSlider lifetimeScale;
    ofxFloatSlider spawTimeSlider;
    ofxFloatSlider gravitySlider;
    ofxVec3Slider velocitySlider;
    ofxVec3Slider emiterSlider;
};
