#include "ball.h"

void Ball::draw() 
{
    ofSetColor(200, 0, 0);
    ofDrawCircle(position, radius);
}

void Ball::mousePressed(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_LEFT && ofVec2f(x, y).distance(position) <= radius)
    {
        isDragging = true;
    }
}

void Ball::mouseDragged(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_LEFT && isDragging) 
    {
        position.set(x, y);
    }
}

void Ball::mouseReleased(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_LEFT) 
    {
        isDragging = false;
    }
}