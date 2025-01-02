#pragma once
#include <ofMain.h>

void drawStar(float x, float y, float radius1, float radius2, int points) {
    ofBeginShape();
    for (int i = 0; i < points * 2; i++) {
        float angle = i * TWO_PI / (points * 2);
        float radius = (i % 2 == 0) ? radius1 : radius2;
        float px = x + cos(angle) * radius;
        float py = y + sin(angle) * radius;
        ofVertex(px, py);
    }
    ofEndShape(true);
}

void drawChristmasTree(float x, float y, float width, float height, ofColor color) {
    ofSetColor(139, 69, 19);
    ofDrawRectangle(x + (2 * width / 5), y + height * 0.9f, width / 5, height * 0.1);

    ofSetColor(color);
    ofDrawTriangle(x + 20, y + height * 0.5,
        x + width / 2, y,
        x + width - 20, y + height * 0.5);

    ofDrawTriangle(x + 10, y + height * 0.7,
        x + width / 2, y,
        x + width - 10, y + height * 0.7);

    ofDrawTriangle(x, y + height * 0.9,
        x + width / 2, y + height * 0.2,
        x + width, y + height * 0.9);

    ofSetColor(255, 215, 0);
    float starSize = width * 0.1;
    drawStar(x + width / 2, y, starSize, starSize / 2, 5);
}

void drawGround(float x, float y, float w, float h)
{
    ofSetColor(200, 200, 200);

    ofBeginShape();
    for (float i = 0; i <= w; i += 1.0f) {
        float waveHeight = 20.0f;
        float frequency = 0.01f;
        float offsetY = waveHeight * sin(i * frequency);\
        ofVertex(x + i, y + offsetY);
    }
    ofVertex(x + w, y + h);
    ofVertex(x, y + h);
    ofEndShape(true);
}
