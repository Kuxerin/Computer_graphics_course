#include <GL/glut.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils.h"
#include "textures.h"
#include "help.h"

void toggleHelp( int key, ShownHelp* shownHelp )
{
	if( key == GLUT_KEY_F1 )
	{
		if( *shownHelp == NO_HELP ) { *shownHelp = HELP; printf("\nShowing help... \n "); }
		else if ( *shownHelp == HELP ) { *shownHelp = NO_HELP; printf("\nStopped showing help... \n ");}
	}
}

void renderHelp( Texture shownHelpTexture )
{
	glPushMatrix();
	
		GLint viewport[4];
		GLdouble modelview[16];
		GLdouble projection[16];
		double w = glutGet( GLUT_WINDOW_WIDTH );
		double h = glutGet( GLUT_WINDOW_HEIGHT );
		glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
		glGetDoublev( GL_PROJECTION_MATRIX, projection );
		glGetIntegerv( GL_VIEWPORT, viewport );
		double depth=0.01;
		
		pos3D upperRight;
		pos3D upperLeft;
		pos3D lowerRight;
		pos3D lowerLeft;

		gluUnProject( w, h, depth, modelview, projection, viewport, &upperRight.x, &upperRight.y, &upperRight.z );
		gluUnProject( 0, h, depth, modelview, projection, viewport, &upperLeft.x, &upperLeft.y, &upperLeft.z );
		gluUnProject( w, 0, depth, modelview, projection, viewport, &lowerRight.x, &lowerRight.y, &lowerRight.z );
		gluUnProject( 0, 0, depth, modelview, projection, viewport, &lowerLeft.x, &lowerLeft.y, &lowerLeft.z );
		
		double hRatio = (double)h/w;
		double wRatio = (double)w/h;
		if( h > w )
		{
			wRatio = 1.0;
		} else
		{
			hRatio = 1.0;
		}
			
		glEnable( GL_BLEND );
		glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
		glDisable( GL_LIGHTING );
		glBindTexture( GL_TEXTURE_2D, shownHelpTexture.id );
		
		glBegin( GL_QUADS );
			glTexCoord2f( -( ( wRatio - 1 ) / 2 ), hRatio - ( ( hRatio - 1 ) / 2 ) );
			glVertex3f( lowerLeft.x, lowerLeft.y, lowerLeft.z );
			
			glTexCoord2f( wRatio -( ( wRatio - 1 ) / 2 ), hRatio - ( ( hRatio - 1 ) / 2 ) );
			glVertex3f( lowerRight.x, lowerRight.y, lowerRight.z );
			
			glTexCoord2f( wRatio -( ( wRatio - 1 ) / 2 ), -( hRatio - 1 ) / 2 );
			glVertex3f( upperRight.x, upperRight.y, upperRight.z );
			
			glTexCoord2f( -( ( wRatio - 1) / 2 ), -( hRatio - 1 ) / 2 );
			glVertex3f( upperLeft.x, upperLeft.y, upperLeft.z );
		glEnd();
		
		glEnable( GL_LIGHTING );
		glDisable( GL_BLEND );
				
	glPopMatrix();
}
