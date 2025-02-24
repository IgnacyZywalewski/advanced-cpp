#pragma once
#include "ofMain.h"
#include "particle.h"

class Spring {
public:
    void update(Particle& a, Particle& b, float restLength, float k);
    void draw(Particle& a, Particle& b);

private:
    float defaultRestLength = 50.0f;
};
