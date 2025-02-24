#pragma once
#include "ofMain.h"

class Particle {
public:
    Particle() = default;

    Particle(float x, float y)
        :locked(false), position(ofVec2f(x, y)), velocity(ofVec2f(0.0f, 0.0f)), acceleration(ofVec2f(0.0f, 0.0f)) { }

    void apply_force(ofVec2f force) 
    {
        acceleration += (force / mass);
    }

    void update() 
    {
        if (!locked) 
        {
            velocity *= 0.99f;
            velocity += acceleration;
            position += velocity;
            acceleration *= 0;
        }
    }

    void draw(ofColor color, int radius)
    {
        ofSetColor(color);
        ofDrawCircle(position.x, position.y, radius);
    }

    ofVec2f get_position() const { return position; }
    void set_position(ofVec2f new_pos) { position = new_pos; }

    ofVec2f get_velocity() const { return velocity; }
    void set_velocity(ofVec2f new_vel) { velocity = new_vel; }

    void set_acceleration(ofVec2f new_acc) { acceleration = new_acc; }

    void set_lock(bool new_lock) { locked = new_lock; }

private:
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    float mass = 1.0f;
    bool locked;
};