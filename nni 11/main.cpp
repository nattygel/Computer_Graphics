#include <GL/glut.h>
#include "shapes.cpp"
#include <iostream>


#define X_RESOLUTION 600
#define Y_RESOLUTION 800

#define WINDOW_X_OFFSET 600
#define WINDOW_Y_OFFSET 100

#define BUTTON_EXIT_X 500
#define BUTTON_EXIT_Y 0
#define BUTTON_EXIT_WIDTH 120
#define BUTTON_EXIT_HEIGHT 40

#define NAME_X 410
#define NAME_Y 780

#define TITLE_X 460
#define TITLE_Y 760


float aspect_ratio = static_cast<float>(X_RESOLUTION) / static_cast<float>(Y_RESOLUTION);


void InitGlut(int argc, char** argv) {
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(X_RESOLUTION, Y_RESOLUTION);
    glutInitWindowPosition(WINDOW_X_OFFSET, WINDOW_Y_OFFSET);
    glutInit(&argc, argv);
    glutCreateWindow("Computer Graphics");
}

void MyInit() {
    glClearColor(0.0f, 0.0f, 0.7f, 0.0f);    
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(40.0f);
}

void DrawButtonExit() {
    glColor3f(0.8f, 0.8f, 0.8f);
    glRectf(BUTTON_EXIT_X, 
            BUTTON_EXIT_Y + BUTTON_EXIT_HEIGHT, 
            BUTTON_EXIT_X + BUTTON_EXIT_WIDTH, 
            BUTTON_EXIT_Y);

    glColor3f(0.0f, 0.0f, 0.0f); 
    glRasterPos2f(BUTTON_EXIT_X + 30, BUTTON_EXIT_Y + 7 ); 
    for (char c : "Exit") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c); 
    }
}

void DrawTitleName()
{
    std::string name = "YAKOV VAXELBOM";
    std::string title = "FOLLOWERS";

    glColor3f(0.0f, 0.0f, 0.0f);
    
    glRasterPos2f(NAME_X, NAME_Y);
    for (char c : name) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glRasterPos2f(TITLE_X, TITLE_Y);
    for (char c : title) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
    }
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    drawFollowers();
    DrawTitleName();
    DrawButtonExit();
     glFlush();
}


void Mouse(int Button, int State, int X, int Y)
{
    // Adjust Y coordinate to match OpenGL coordinate system
    Y = Y_RESOLUTION - Y;

    // Calculate the button boundaries based on the current window size
    float buttonX = static_cast<float>(X_RESOLUTION - BUTTON_EXIT_WIDTH);
    float buttonY = static_cast<float>(Y_RESOLUTION - BUTTON_EXIT_HEIGHT);
    std::cout<< "buttonX " << buttonX << " buttonY " << buttonY << "   x :" << X << "   y : " << Y << std::endl;

    // Check if the left mouse button is pressed within the button boundaries
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN &&
        static_cast<float>(X) >= buttonX && static_cast<float>(X) <= buttonX + static_cast<float>(BUTTON_EXIT_WIDTH) &&
        static_cast<float>(Y) >= buttonY && static_cast<float>(Y) <= buttonY + static_cast<float>(BUTTON_EXIT_HEIGHT))
    {
        // Close the window
        int windowID = glutGetWindow();
        glutDestroyWindow(windowID);
    }
}


void Resize(GLsizei width, GLsizei height) {
    glViewport(0, 0, width, height);

    aspect_ratio = static_cast<float>(width) / static_cast<float>(height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width > height) {
        gluOrtho2D(-1.0f * aspect_ratio, X_RESOLUTION * aspect_ratio, -1.0f, Y_RESOLUTION);
    } else  {
        gluOrtho2D(-1.0f, X_RESOLUTION, -1.0f / aspect_ratio, Y_RESOLUTION / aspect_ratio);
    }
  
    glMatrixMode(GL_MODELVIEW);
}


void RegisterCallbacks() {
    glutDisplayFunc(Display);
    glutMouseFunc(Mouse); 
    glutReshapeFunc(Resize);
}

int main(int argc, char** argv) {
    
    InitGlut(argc, argv);
    
    MyInit();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0f, X_RESOLUTION, 0.0f, Y_RESOLUTION);
    // gluOrtho2D(200, 300, 0.0f, Y_RESOLUTION);
    RegisterCallbacks();
    glutMainLoop();

    return 0;
}


