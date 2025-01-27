#ifndef TEXTURES_H
#define TEXTURES_H

#include <GL/glut.h>

typedef GLubyte Pixel[];

typedef struct Texture 
{ 
    GLuint id;
	char filename[100];
	Pixel* image;
} Texture;


void loadTextures( Texture* texture, const char filename[100] );

#endif /* TEXTURES_H */
