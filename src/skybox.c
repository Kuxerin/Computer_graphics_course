#include <skybox.h>
#include <stdio.h>

void renderSkybox	( 	float boxsize, 
						Texture top_texture,
						Texture front_texture,
						Texture right_texture,
						Texture left_texture,
						Texture bottom_texture,
						Texture back_texture
					)
					{
						glDisable( GL_LIGHT0 );
						GLfloat f1[] = { 1.0, 1.0, 1.0 };
						GLfloat f2[] = { 0.0, 0.0, 0.0 };
						glMaterialfv( GL_FRONT, GL_EMISSION, f1 );
						glTranslatef( 0.0, 0.0, 0.0 );
						
						glPushMatrix();

							glBindTexture( GL_TEXTURE_2D, top_texture.id );
							glBegin( GL_QUADS );
								glNormal3f( 0.0f, 1.0f, 0.0f );
								glTexCoord2f( 0.0,0.0 );
								glVertex3f( -boxsize, boxsize, -boxsize );
								
								glNormal3f( 0.0f, 1.0f, 0.0f );
								glTexCoord2f( 0.0,1.0 );
								glVertex3f( boxsize, boxsize, -boxsize );
								
								glNormal3f( 0.0f, 1.0f, 0.0f );
								glTexCoord2f( 1.0,1.0 );
								glVertex3f( boxsize, boxsize, boxsize );
								
								glNormal3f( 0.0f, 1.0f, 0.0f );
								glTexCoord2f( 1.0,0.0 );
								glVertex3f( -boxsize, boxsize, boxsize );
							glEnd();
							
							glBindTexture(GL_TEXTURE_2D, front_texture.id);
							glBegin(GL_QUADS);
								glNormal3f( 0.0f, 0.0f, 1.0f );
								glTexCoord2f( 1.0,0.0 );
								glVertex3f( -boxsize, boxsize, boxsize );
								
								glNormal3f( 0.0f, 0.0f,1.0f );
								glTexCoord2f( 0.0,0.0 );
								glVertex3f( boxsize, boxsize, boxsize );
								
								glNormal3f( 0.0f, 0.0f, 1.0f );
								glTexCoord2f( 0.0,1.0 );
								glVertex3f( boxsize, -boxsize, boxsize );
								
								glNormal3f( 0.0f, 0.0f, 1.0f );
								glTexCoord2f( 1.0,1.0 );
								glVertex3f( -boxsize, -boxsize, boxsize );
							glEnd();

							glBindTexture( GL_TEXTURE_2D, left_texture.id );
							glBegin(GL_QUADS);
								glNormal3f( 1.0f, 0.0f, 0.0f );
								glTexCoord2f( 1.0,0.0 );
								glVertex3f( boxsize, boxsize, boxsize );
								
								glNormal3f( 1.0f, 0.0f, 0.0f );
								glTexCoord2f( 0.0,0.0 );
								glVertex3f( boxsize, boxsize, -boxsize );
								
								glNormal3f( 1.0f, 0.0f, 0.0f );
								glTexCoord2f( 0.0,1.0 );
								glVertex3f( boxsize, -boxsize, -boxsize );
								
								glNormal3f( 1.0f, 0.0f, 0.0f );
								glTexCoord2f( 1.0,1.0 );
								glVertex3f( boxsize, -boxsize, boxsize );
							glEnd();

							glBindTexture(GL_TEXTURE_2D, right_texture.id);
							glBegin(GL_QUADS);
								glNormal3f( -1.0f, 0.0f, 0.0f );
								glTexCoord2f( 1.0,0.0 );
								glVertex3f( -boxsize, boxsize, -boxsize );
								
								glNormal3f( -1.0f, 0.0f, 0.0f );
								glTexCoord2f( 0.0,0.0 );
								glVertex3f( -boxsize, boxsize, boxsize);
								
								glNormal3f( -1.0f, 0.0f, 0.0f );
								glTexCoord2f( 0.0,1.0 );
								glVertex3f( -boxsize, -boxsize, boxsize );
								
								glNormal3f( -1.0f, 0.0f, 0.0f );
								glTexCoord2f( 1.0,1.0 );
								glVertex3f( -boxsize, -boxsize, -boxsize );
							glEnd();

							glBindTexture(GL_TEXTURE_2D, bottom_texture.id);
							glBegin(GL_QUADS);
								glNormal3f( 0.0f, -1.0f, 0.0f );
								glTexCoord2f( 1.0,0.0 );
								glVertex3f( -boxsize, -boxsize, boxsize );
								
								glNormal3f( 0.0f, -1.0f, 0.0f );
								glTexCoord2f( 0.0,0.0 );
								glVertex3f( boxsize, -boxsize, boxsize );
								
								glNormal3f( 0.0f, -1.0f, 0.0f );
								glTexCoord2f( 0.0,1.0 );
								glVertex3f( boxsize, -boxsize, -boxsize);
								
								glNormal3f( 0.0f, -1.0f, 0.0f );
								glTexCoord2f( 1.0,1.0 );
								glVertex3f( -boxsize, -boxsize, -boxsize);
							glEnd();

							glBindTexture(GL_TEXTURE_2D, back_texture.id);
							glBegin(GL_QUADS);
								glNormal3f( 0.0f, 0.0f, -1.0f );
								glTexCoord2f( 1.0,0.0 );
								glVertex3f( boxsize, boxsize, -boxsize );
								
								glNormal3f( 0.0f, 0.0f, -1.0f );
								glTexCoord2f( 0.0,0.0 );
								glVertex3f( -boxsize, boxsize, -boxsize );
								
								glNormal3f( 0.0f, 0.0f, -1.0f );
								glTexCoord2f( 0.0,1.0 );
								glVertex3f( -boxsize, -boxsize, -boxsize );
								
								glNormal3f( 0.0f, 0.0f, -1.0f );
								glTexCoord2f( 1.0,1.0 );
								glVertex3f( boxsize, -boxsize, -boxsize );
							glEnd();
							
						glPopMatrix();	
						
						glMaterialfv(GL_FRONT, GL_EMISSION, f2);
						glEnable(GL_LIGHT0);
					}
					
