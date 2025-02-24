#pragma once

#include "ofMain.h"
#include "spring.h"
#include "particle.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void create_string(int particle_number);
    void mousePressed(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void resetSimulation();
    void keyPressed(int key);

private:
    std::vector<Particle> particles;
    std::vector<Spring> springs;
    float spacing = 5.0f;
    float k = 0.1f;
    ofVec2f gravity = { 0.0f, 0.1f };
    Particle* dragged_particle = nullptr;
};
