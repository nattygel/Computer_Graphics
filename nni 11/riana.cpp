// #include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    /**
    * Part A 
    */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    // Draw a Red 1x1 Square centered at origin
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(-0.5f, -0.5f);    // x, y
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glFlush();  // Render now

    /**
    * Part B - please uncomment
    
    // Scene
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    glBegin(GL_QUADS); 
        // Grass quad
        glColor3f(0.0f, 0.6f, 0.5f);
        glVertex2f(-0.5f, 0.1f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.1f);

        // Sky quad
        glColor3f(0.0f, 0.0f, 0.4f);
        glVertex2f(0.5f, 0.1f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(-0.5f, 0.1f);

        // Tree quad
        glColor3f(0.7f, 0.4f, 0.2f);
        glVertex2f(-0.3f, 0.1f);
        glVertex2f(-0.27f, 0.1f);
        glVertex2f(-0.27f, 0.3f);
        glVertex2f(-0.3f, 0.3f);

        //  Building quad
        glColor3f(0.7f, 0.3f, 0.3f);
        glVertex2f(0.1f, -0.3f);
        glVertex2f(0.3f, -0.3f);
        glVertex2f(0.3f, 0.3f);
        glVertex2f(0.1f, 0.3f);

       //Windows Quads
        glColor3f(0.0f, 0.3f, 0.8f);
        glVertex2f(0.22f, 0.2f);
        glVertex2f(0.27f, 0.2f);
        glVertex2f(0.27f, 0.25f);
        glVertex2f(0.22f, 0.25f);

        glVertex2f(0.22f, 0.1f);
        glVertex2f(0.27f, 0.1f);
        glVertex2f(0.27f, 0.15f);
        glVertex2f(0.22f, 0.15f);

        glVertex2f(0.22f, 0.0f);
        glVertex2f(0.27f, 0.0f);
        glVertex2f(0.27f, 0.05f);
        glVertex2f(0.22f, 0.05f);

        glVertex2f(0.12f, 0.2f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.17f, 0.25f);
        glVertex2f(0.12f, 0.25f);

        glVertex2f(0.12f, 0.1f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.17f, 0.15f);
        glVertex2f(0.12f, 0.15f);

        glVertex2f(0.12f, 0.0f);
        glVertex2f(0.17f, 0.0f);
        glVertex2f(0.17f, 0.05f);
        glVertex2f(0.12f, 0.05f);

        //Door quad
        glColor3f(0.9f, 0.5f, 0.5f);
        glVertex2f(0.19f, -0.3f);
        glVertex2f(0.21f, -0.3f);
        glVertex2f(0.21f, -0.1f);
        glVertex2f(0.19f, -0.1f);

  
    glEnd();

    glBegin(GL_TRIANGLES);
       // Tree leaves
        glColor3f(0.0f, 0.6f, 0.0f); 
        glVertex2f(-0.33f, 0.3f);
        glVertex2f(-0.24f, 0.3f);
        glVertex2f(-0.285f, 0.5f);

    glEnd();

    glFlush();  // Render now
    */
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("OpenGL Screen"); // Create a window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}