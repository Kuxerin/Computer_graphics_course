#ifndef LIGHTS_H
#define LIGHTS_H

#include <GL/glut.h>
#include <stdio.h>
#include <utils.h>

typedef struct Light
{
	double intensity;
	RGB color;
	pos3D position;
	GLenum id;
} Light;

void initLights( Light* light, double intensity, RGB color, pos3D position, GLenum id );
void renderALight( Light* light );
void increaseIntensity( Light* light );
void decreaseIntensity( Light* light );

#endif /* LIGHTS_H */