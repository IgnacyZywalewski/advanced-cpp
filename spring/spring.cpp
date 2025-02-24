#include "spring.h"

void Spring::update(Particle& a, Particle& b, float restLength, float k)
{
    ofVec2f force = b.get_position() - a.get_position();

    float stretch = force.length() - restLength;

    force = force.getNormalized();

    force *= k * stretch;

    a.apply_force(force);
    b.apply_force(-force);
}

void Spring::draw(Particle& a, Particle& b)
{
    ofSetColor(252, 238, 33);
    ofSetLineWidth(5);
    ofDrawLine(a.get_position().x, a.get_position().y, b.get_position().x, b.get_position().y);
}