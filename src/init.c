#include <GL/glut.h>
#include <stdio.h>
#include <stdbool.h>

bool initGL()
{
	glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(1.0, 0.1, 1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
	
	GLenum error = glGetError();
	if( error != GL_NO_ERROR )
	{
		printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
		return false;
	}
	
	return true;
}