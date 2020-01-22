#ifndef SKYBOX_H
#define SKYBOX_H

#include <textures.h>

void renderSkybox	( 	float size, 
						Texture top_texture,
						Texture front_texture,
						Texture right_texture,
						Texture left_texture,
						Texture bottom_texture,
						Texture back_texture
					);
					
#endif /* SKYBOX_H */