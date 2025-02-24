#include "ofApp.h"

void ofApp::setup()
{
    ofBackground(0);

    //gui
    gui.setup();
    gui.add(radiusScale.setup("Radius Scale", 1.0f, 0.5f, 5.0f));
    gui.add(lifetimeScale.setup("Life time", 30.0f, 5.0f, 50.0f));
    gui.add(spawTimeSlider.setup("Spawn time", 0.01f, 0.0001f, 0.1f));
    gui.add(gravitySlider.setup("Gravity Force", 100, 0, 500));
    gui.add(velocitySlider.setup("Velocity Scale", ofVec3f(1.0f, 1.0f, 1.0f), ofVec3f(0.0f, 0.0f, 0.0f), ofVec3f(2.0f, 2.0f, 2.0f)));
    gui.add(emiterSlider.setup("Emiter Position", ofVec3f(0, 0, 0), ofVec3f(-(ofGetWidth() * 0.5), -(ofGetHeight() * 0.5), -1000), ofVec3f(ofGetWidth(), ofGetHeight(), 1000)));

    //kamera
    cam.setNearClip(0.1);
    cam.setFarClip(10000);
    cameraPosition.set(0, (ofGetHeight() / 2) - 200, 1000);
    cam.setPosition(cameraPosition);
    cam.lookAt(ofVec3f(0, (ofGetHeight() / 2) - 200, 0));

    lastFrameTime = ofGetElapsedTimef();
}


void ofApp::update()
{
    float currentTime = ofGetElapsedTimef();
    float deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    ofVec3f velocityScale = ofVec3f(velocitySlider->x, velocitySlider->y, velocitySlider->z);
    emiter.setVelocityScale(velocityScale);

    ofVec3f emiterPosition = ofVec3f(emiterSlider->x, emiterSlider->y, emiterSlider->z);
    emiter.setPosition(emiterPosition);

    emiter.update(deltaTime, lifetimeScale, spawTimeSlider, gravitySlider);
}


void ofApp::draw()
{
    cam.begin();

    ofPushMatrix();
    ofRotateXDeg(rotationY);
    ofRotateYDeg(rotationX);

    emiter.drawPlatform();
    emiter.drawEmiter();
    emiter.drawParticles(radiusScale);
   
    ofPopMatrix();

    cam.end();

    gui.draw();
}


void ofApp::mouseScrolled(ofMouseEventArgs& args)
{
    float scrollSpeed = 50.0f;
    ofVec3f camPos = cam.getPosition();
    float newZ = camPos.z - args.scrollY * scrollSpeed;

    cam.setPosition(camPos.x, camPos.y, newZ);
}


void ofApp::mousePressed(int x, int y, int button)
{
    isDragging = true;
    activeButton = button;
    lastMouse.set(x, y);
}


void ofApp::mouseReleased(int x, int y, int button)
{
    if (button == activeButton)
    {
        isDragging = false;
        activeButton = -1;
    }
}


void ofApp::mouseDragged(int x, int y, int button)
{
    if (!isDragging || button != activeButton) return;

    float deltaX = x - lastMouse.x;
    float deltaY = y - lastMouse.y;

    if (activeButton == OF_MOUSE_BUTTON_LEFT)
    {
        float scale = cam.getPosition().z / 1000.0f;
        cameraPosition.x = cam.getPosition().x - deltaX * scale;
        cameraPosition.y = cam.getPosition().y + deltaY * scale;

        cam.setPosition(cameraPosition.x, cameraPosition.y, cam.getPosition().z);
    }
    else if (activeButton == OF_MOUSE_BUTTON_RIGHT)
    {
        rotationX += deltaX * 0.1f;
        rotationY += deltaY * 0.1f;
    }

    lastMouse.set(x, y);
}

//OF_MOUSE_BUTTON_MIDDLE