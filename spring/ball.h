#pragma once
#include "ofMain.h"

class Ball {
public:
    Ball(ofVec2f position, float radius)
        : position(position), radius(radius), isDragging(false) { }

    void draw();
    void mousePressed(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    ofVec2f getPosition() const { return position; };
    void setPosition(ofVec2f newPosition) { position = newPosition; };
    bool isBeingDragged() const { return isDragging; };

private:
    ofVec2f position;
    float radius;
    bool isDragging;
};
