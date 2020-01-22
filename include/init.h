#ifndef INIT_H
#define INIT_H

#include <math.h>
#include <obj/model.h>
#include <obj/load.h>
#include <obj/draw.h>
#include <obj/info.h>

bool initGL();
void init_models();
void init_camera();
void init_textures();
void init_lights();

#endif /* INIT_H */
