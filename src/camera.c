#include <GL/glut.h>
#include <math.h>
#include <camera.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

void initCamera( Camera* camera, double zoom, double hAngle, double vAngle, double mousePosX, double mousePosY )
{
	camera->zoom = zoom;
	camera->hAngle = hAngle;
	camera->vAngle = vAngle;
	camera->mousePosX = mousePosX;
	camera->mousePosY = mousePosY;
}

void renderCamera( Camera* camera )
{
	gluLookAt
	( 			cos( camera->hAngle ) * cos( camera->vAngle ) * camera->zoom,
				sin( camera->vAngle ) * camera->zoom,
				sin( camera->hAngle ) * cos( camera->vAngle ) * camera->zoom,
				0.0, 0.0, 0.0, // looking point
				cos( camera->hAngle ) * cos( camera->vAngle + ( M_PI / 2 ) ),
				sin( camera->vAngle + ( M_PI / 2 ) ),
				sin( camera->hAngle ) * cos( camera->vAngle + ( M_PI / 2 ) )
	);
}

void moveCamera( Camera* camera, unsigned char key )
{
	switch( key )
	{	
		case 'w': camera->vAngle = camera->vAngle + 0.05; break;
		case 'a': camera->hAngle = camera->hAngle - 0.05; break;
		case 's': camera->vAngle = camera->vAngle - 0.05; break;
		case 'd': camera->hAngle = camera->hAngle +	0.05; break;
		case 'q': if( camera->zoom < 60.0 ) { camera->zoom = camera->zoom + 0.1; break; }
				  else { camera->zoom = 60.0; break; }
		case 'e': if( camera->zoom > 5.0 ) { camera->zoom = camera->zoom - 0.1; break; }
				  else { camera->zoom = 5.0; break; }
	}
}

void moveCamerabyMouse( Camera* camera, int x, int y )
{
	camera->hAngle += (x - camera->mousePosX) * 0.01;
	camera->vAngle += (y - camera->mousePosY) * 0.01;
		
	camera->mousePosX = x;
	camera->mousePosY = y;
}

void cameraData( Camera* camera )
{
	printf( "\n" );
	printf( "Zoom: %0.3f\n", camera->zoom );
	printf( "Horizontal Angle: %0.3f\n", camera->hAngle );
	printf( "Vertical Angle: %0.3f\n", camera->vAngle );
}