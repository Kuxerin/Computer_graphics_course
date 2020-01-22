#include <lights.h>

void initLights( Light* light, double intensity, RGB color, pos3D position, GLenum id )
{
	light->intensity = intensity;
	light->color = color;
	light->position = position;
	light->id = id;
	
	glEnable( GL_LIGHTING );
	glEnable( light->id );
}

void renderALight( Light* light )
{
	GLfloat position[] =	{
								light->position.x,
								light->position.y,
								light->position.z, 
								0.0					
							};
    GLfloat color[] =	{
							light->color.R * light->intensity,
							light->color.G * light->intensity,
							light->color.B * light->intensity
						}; 
	
	glLightfv( light->id, GL_POSITION, position );
	glLightfv( light->id, GL_AMBIENT, color );
	glLightfv( light->id, GL_DIFFUSE, color );
	glLightfv( light->id, GL_SPECULAR, color );
}

void printLightDetails( Light* light )
{
	printf( "\n" );
	printf( "Intensity: %0.3f\n", light->intensity );
	printf( "Color: R: %0.3f, G: %0.3f, B: %0.3f \n", light->color.R, light->color.G, light->color.B );
	printf( "Position: X: %0.3f, Y: %0.3f, Z: %0.3f \n", light->position.x, light->position.y, light->position.z );
	printf( "Id: %d \n", light->id );
}

void increaseIntensity( Light* light )
{
	if( light->intensity  < 2.0)
	{
		light->intensity = light->intensity + 0.05;
		printf( "\nLight intensity increased from %0.3lf to %0.3lf. \n", light->intensity - 0.05, light->intensity );
	}
	else
	{
		light->intensity = 2.0;
		printf( "\nLight intensity cannot be higher than %0.3lf. \n", light->intensity );
	}
}

void decreaseIntensity( Light* light )
{
	if( light->intensity  > 0.0)
	{
		light->intensity = light->intensity - 0.05;
		printf( "\nLight intensity decreased from %0.3lf to %0.3lf. \n", light->intensity + 0.05, light->intensity );
	}
	else
	{
		light->intensity = 0.0;
		printf( "\nLight intensity cannot be lower than %0.3lf. \n", light->intensity );
	}
}


