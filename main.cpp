/*
	The Code Below is used to develop a Diamond Pattern.


	1. Start with Identifying the First Diamond
	2. Put in the coordinates for the First Diamond
	3. Create a for-loop to to create diamonds at the same time
	4. Introduce an outer for-loop to cater for the y - axis.

*/


//#include <windows.h> // for MS Windows
// GLUT, include glu.h and gl.h

#include <GL/glut.h>





/* Initialize OpenGL Graphics */

void initGL() {

// Set "clearing" or background color
    glClearColor(0.333, 0.420, 0.184, 0.0f);

    //Enabling Use Of 'glVertex2i()'
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    //initialize the variables.
    GLint x = 50;
    GLint y = 50;
    //GLint colorCode = 1;

    //imagine a diamond pattern

    /*
                                (x, y + 25)
                            /				\
                        /						\
                                                    \
                    /								\
                                                        \
                /											\
            /												\
        /
  (x - 25, y)		(x, y)   	(x + 25, y)
            \
              \												/
                \										/
                  \									/
                    \							/
                      \						/
                         \				/
                           \		/
                                (x - 25, y)
    */


    //setting the (x, y)
    GLint jump = 4;

    for(y = 50; y <= 350; y += jump * 2) {

        for(x = 50; x <= 350; x += jump * 2) {


            //Initiate The First Diamond
            glBegin(GL_QUADS);
            glColor3f(0.392, 0.584, 0.929);
            glVertex2i(x - jump, y);
            glVertex2i(x, y + jump);
            glVertex2i(x + jump, y);
            glVertex2i(x, y - jump);
            glEnd();

        }

    }


    glFlush(); // Render now
}




/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutCreateWindow("Diamond Pattern"); // Create window with the given title
    glutInitWindowSize(640, 480); // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register callback handler for window re-paint event
    initGL(); // Our own OpenGL initialization
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}