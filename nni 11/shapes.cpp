#include "shapes.h"



void crateCircle(double ori_x, double ori_y, double radius, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);                        
    for (int i = 0; i <= 360; i++) {
        double angle = 2 * M_PI * i / 300;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        glVertex2d(ori_x + x, ori_y + y);
    }
    glEnd();
}

void crateEllipse(float xCenter, float yCenter, float radiusX, float radiusY, float viewAngle, Color color)
{
    glColor3f(color.r, color.g, color.b);
    glPushMatrix(); 

    glTranslatef(xCenter, yCenter, 0.0f); 
    glRotatef(viewAngle, 0.0f, 0.0f, 1.0f);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 1000; ++i) {
        float theta = 2.0f * static_cast<float>(M_PI) * static_cast<float>(i) / 1000;
        float x = radiusX * cosf(theta);
        float y = radiusY * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glPopMatrix(); 
}

void vase() 
{
    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);                        
    double radius = 100;
    double ori_x = 300;                         
    double ori_y = 100;
    for (int i = 0; i <= 150; i++) {
        double angle = 2 * M_PI * i / 300;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        glVertex2d(ori_x + x, ori_y + y);
    }
    glEnd();

    glColor3f(0.0f, 0.5f, 1.0f);
    glRectf(260,100, 340, 300) ;

    crateEllipse(300.0f, 300.0f,40.0f, 20.0f,0, {0.0f, 0.5f, 1.0f});
    crateEllipse(300.0f, 298.0f,37.0f, 20.0f, 0, {1.0f, 1.0f, 1.0f});
}

void stalk(float x0, float y0, float x1, float y1, float x2, float y2) 
{

    glColor3f(0.0f, 0.5f, 0.0f);

    glLineWidth(4.0f);

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 1000; ++i) {
        float t = static_cast<float>(i) / 1000.0f;
        float x = (1 - t) * (1 - t) * x0 + 2 * (1 - t) * t * x1 + t * t * x2;
        float y = (1 - t) * (1 - t) * y0 + 2 * (1 - t) * t * y1 + t * t * y2;
        glVertex2f(x, y);
    }
    glEnd();
}

void Follower(double ori_x, double ori_y, double radius, Color colorStamen , Color colorPistil)
{

    for (int i = 0; i < 4; ++i) {
        double angle = 2 * M_PI * i / 4; 
        double circle_x = ori_x + 40 * cos(angle); 
        double circle_y = ori_y + 40 * sin(angle); 
        crateCircle(circle_x, circle_y, 25, colorPistil); 
    }
    crateCircle(ori_x, ori_y, radius, colorStamen); 
}

void drawFollowers()
{
    vase();

    stalk(310, 280, 300, 300,300,600);
    stalk(300, 280, 310, 350,200,500);
    stalk(300, 280, 310, 350,350,450);

    crateEllipse(227.0f, 385.0f,40.0f, 20.0f,30, {0.0f, 0.5f, 0.0f});
    crateEllipse(283.0f, 450.0f,40.0f, 20.0f,45, {0.0f, 0.5f, 0.0f});

    crateEllipse(358.0f, 350.0f,40.0f, 20.0f,-30, {0.0f, 0.5f, 0.0f});

    crateEllipse(342.0f, 510.0f,40.0f, 20.0f,0, {0.0f, 0.5f, 0.0f});
    crateEllipse(262.0f, 525.0f,40.0f, 20.0f,-30, {0.0f, 0.5f, 0.0f});


    Follower(300, 600, 30 ,{0.8f, 0.6f, 0.8f},{0.8549f, 0.6471f, 0.1255f});
    Follower(200, 500, 30 ,{0.678f, 0.847f, 0.902f},{0.8039f, 0.3608f, 0.3608f});
    Follower(350, 450, 30 ,{0.5804f, 0.0f, 0.8275f},{0.5451f, 0.5059f, 0.5059f});

    glFlush();
}


