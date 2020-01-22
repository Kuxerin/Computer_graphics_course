#include <GL/glut.h>
#include <callbacks.h>

void reshape( GLsizei width, GLsizei height )
{   
   glViewport( 0, 0, width, height );
 
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   
   gluPerspective( 50.0, (GLdouble)width / (GLdouble)height, 0.01, 1000.0 );
}