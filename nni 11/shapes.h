#include <GL/gl.h>
#include <cmath>


struct Color {
    float r, g, b;
};

void crateCircle(double ori_x, double ori_y, double radius, Color color);

void crateEllipse(float xCenter, float yCenter, float radiusX, float radiusY, float viewAngle, Color color);

void vase();

void stalk(float x0, float y0, float x1, float y1, float x2, float y2);

void Follower(double ori_x, double ori_y, double radius, Color colorStamen , Color colorPistil);

void drawFollowers();