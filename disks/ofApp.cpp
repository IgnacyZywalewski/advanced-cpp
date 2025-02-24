#include "ofApp.h"

void ofApp::generateCircles(){
    for (int i = 0; i < circlesNum; i++) {
        float radius = ofRandom(2, 10);
        float mass = radius * 10;

        float xPos = ofRandom(radius, ofGetWidth() - radius);
        float yPos = ofRandom(radius, ofGetHeight() - radius);
        ofVec2f position = ofVec2f(xPos, yPos);

        ofVec2f velocity = ofVec2f(ofRandom(-20, 20), ofRandom(-20, 20));
        ofColor color = ofColor::fromHsb(ofRandom(255), 255, 255);

        circles.emplace_back(position, velocity, radius, mass, color);
    }
}

void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(frameRate);

    gui.setup();
    gui.add(timeStep.setup("Time Step (dt)", 5.0f, 1.0f, 30.0f));
    gui.add(radiusScale.setup("Radius Scale", 1.0f, 0.5f, 2.0f));
    gui.add(centerSlider.setup("center", { ofGetWidth() * .5, ofGetHeight() * .5 }, { 0, 0 }, { ofGetWidth(), ofGetHeight() }));

    prevRadiusScale = radiusScale;

    generateCircles();
}


void ofApp::update(){
    float dt = ofGetLastFrameTime() * timeStep;
    center.set(centerSlider->x, centerSlider->y);

    if (radiusScale != prevRadiusScale) {
        for (auto& circle : circles) {
            float scaleFactor = radiusScale / prevRadiusScale;
            circle.radius *= scaleFactor;
            circle.mass *= scaleFactor;
        }
        prevRadiusScale = radiusScale;
    }

    for (auto& circle : circles) {

        if (circle.position.x - circle.radius < 0) { // Lewa œciana
            circle.velocity.x *= -1;
            circle.position.x = circle.radius + 2;
        }
        if (circle.position.x + circle.radius > ofGetWidth()) { // Prawa œciana
            circle.velocity.x *= -1;
            circle.position.x = ofGetWidth() - circle.radius - 2;
        }
        if (circle.position.y - circle.radius < 0) { // Górna œciana
            circle.velocity.y *= -1;
            circle.position.y = circle.radius + 2;
        }
        if (circle.position.y + circle.radius > ofGetHeight()) { // Dolna œciana
            circle.velocity.y *= -1;
            circle.position.y = ofGetHeight() - circle.radius - 2;
        }

        applyPhysics(circle, dt);
    }

}


void ofApp::draw(){
    ofSetColor(255, 255, 255);
    ofDrawCircle(center, 5);
    
    for (const auto& circle : circles) {
        ofSetColor(circle.color);
        ofDrawCircle(circle.position, circle.radius);
    }

    gui.draw();
}


void ofApp::applyPhysics(Circle& circle, float dt) {
    //si³a grawitacji
    ofVec2f r = center - circle.position;
    float distance = r.length();
    distance = std::max(distance, 5.0f);
    float gravity = circle.mass * 50 / (distance * distance);
    ofVec2f gravityForce = r.getNormalized() * gravity;

    //opór aerodynamiczny
    float viscosity = getViscosity(circle.position);
    ofVec2f dragForce = -6.0f * PI * viscosity * circle.radius * circle.velocity;

    //si³a ca³kowita
    ofVec2f totalForce = gravityForce + dragForce;

    ofVec2f acceleration = totalForce / circle.mass;
    circle.velocity += acceleration * dt;
    circle.position += circle.velocity * dt;
}

float ofApp::getViscosity(const ofVec2f& position) {
    float x = 0.1f + 0.1f * sin(position.x * 0.02f);
    float y = 0.1f + 0.1f * cos(position.y * 0.02f);
    return x * y * 0.5f;
}