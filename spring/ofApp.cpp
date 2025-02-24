#include "ofApp.h"

void ofApp::create_string(int particle_number)
{
    for (int i = 0; i < particle_number; i++)
    {
        particles.emplace_back(ofGetWidth() / 2.0f, i * spacing + 20.0f);

        if (i != 0)
        {
            springs.emplace_back();
        }
    }

    particles[0].set_lock(true);
}

void ofApp::setup()
{
    ofBackground(0);

    create_string(10);
}


void ofApp::update()
{
    for (int i = 0; i < particles.size(); i++) 
    {
        if (i != 0)
        {
            springs[i - 1].update(particles[i], particles[i-1], spacing, k);
        }
        particles[i].apply_force(gravity);
        particles[i].update();
    }
}

void ofApp::draw()
{
    for (int i = particles.size() - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            ofColor color = { 255, 0, 0 };
            particles[i].draw(color, 10);
        }
        else if (i == particles.size() - 1)
        {
            springs[i-1].draw(particles[i], particles[i-1]);

            ofColor color = { 0, 0, 255 };
            particles[i].draw(color, 20);
        }
        else
        {
            springs[i-1].draw(particles[i], particles[i - 1]);

            ofColor color = { 255, 255, 0 };
            particles[i].draw(color, 5);           
        }
    }
}


void ofApp::mousePressed(int x, int y, int button)
{
    Particle& head = particles[0];
    Particle& tail = particles[particles.size() - 1];

    if ((ofVec2f(x, y) - head.get_position()).length() < 16)
    {
        dragged_particle = &head;
    }
    else if ((ofVec2f(x, y) - tail.get_position()).length() < 16)
    {
        dragged_particle = &tail;
        dragged_particle->set_lock(true);
    }
}

void ofApp::mouseDragged(int x, int y, int button)
{
    if (dragged_particle != nullptr) 
    {
        dragged_particle->set_position(ofVec2f(static_cast<float>(x), static_cast<float>(y)));
        dragged_particle->set_velocity(ofVec2f(0.0f, 0.0f));
    }
}

void ofApp::mouseReleased(int x, int y, int button)
{
    if (dragged_particle != nullptr)
    {
        if (dragged_particle != &particles[0])
        {
            dragged_particle->set_lock(false);
        }
        dragged_particle = nullptr;
    }
}

void ofApp::resetSimulation()
{
    for (int i = 0; i < particles.size(); i++)
    {
        particles[i].set_position(ofVec2f(ofGetWidth() / 2.0f, i * spacing + 20.0f));
        particles[i].set_velocity(ofVec2f(0.0f, 0.0f));
        particles[i].set_acceleration(ofVec2f(0.0f, 0.0f));
        particles[i].set_lock(i == 0);
    }
}

void ofApp::keyPressed(int key)
{
    if (key == 'r' || key == 'R') 
    {
        resetSimulation();
    }
}