#include <GL/glut.h>
#include <SOIL/soil.h>
#include <stdio.h>
#include <textures.h>

void loadTextures( Texture* texture, const char filename[100] )
{
    GLuint texture_name;
    glGenTextures( 1, &( texture->id ) );

    int width;
    int height;
	
	texture->image = (Pixel*)SOIL_load_image( filename, &width, &height, 0, SOIL_LOAD_RGB );
	if( texture->image == NULL )
	{
		printf( "Loading texture: %s has failed!", filename );
	}
	
    glBindTexture( GL_TEXTURE_2D, texture->id );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (Pixel*)texture->image );

	glTexParameterf( GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP );
	glTexParameterf( GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP );

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
}

