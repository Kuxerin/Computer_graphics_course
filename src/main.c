#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdbool.h>
#include <obj/model.h>
#include <obj/load.h>
#include <obj/draw.h>
#include <obj/info.h>
#include <init.h>
#include <callbacks.h>
#include <camera.h>
#include <math.h>
#include <lights.h>
#include <skybox.h>
#include <help.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

double cubePosX = 0.0;
double cubePosY = 0.0;
double cubeDefaultPosY = 0.0;
double cubePosZ = 0.0;
double cubeAmplitude = 5.0;

void idle();
void render();
void handleKeys( unsigned char key, int x, int y );
void handleSpecialKeys( int key, int x, int y );
void handleMouse( int button, int state, int x, int y );
void init_models();
void init_camera();
void init_textures();
void init_lights();
void renderModels();
void renderLight();

int shownHelp = NO_HELP;
Light light;
Camera camera;
Model cube, matches;
Texture textures[11];


int main( int argc, char* args[] )
{
	glutInit( &argc, args );
	glutInitContextVersion( 2, 1 );

	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	glutCreateWindow("Graf");
	
	if( !initGL() )
	{
		printf( "Unable to initialize graphics library!\n" );
		return 1;
	}
	printf( "\n=================== \nOpenGL successfully initalized! \n=================== \n \n " );
	
	init_camera();
	init_models();
	init_textures();
	init_lights();

	printf( "\n=================== \n \nRENDERING ... \n \n=================== \n" );
	
	glutDisplayFunc( render );
	glutReshapeFunc( reshape );
	glutIdleFunc( idle );
	glutKeyboardFunc( handleKeys );
	glutSpecialFunc( handleSpecialKeys );
	glutMouseFunc( handleMouse );
	glutMainLoop();

	return 0;
}

void idle()
{
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	
	static int firstTime = 0;
	if (firstTime == 0)
	{
		firstTime = currentTime;
	}
	currentTime = currentTime - firstTime;
	
	double speed = 0.50;
	
	double t = ((((double)currentTime) / 1000) * speed);
	double lambdaY = sin(t) * cubeAmplitude;
	cubePosY = lambdaY + cubeDefaultPosY;

	glutPostRedisplay();

}

void render()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	
	glPushMatrix();
		renderCamera( &camera );
		renderModels();
		renderLight();
		renderSkybox(	80.0, textures[4], textures[5], textures[6],
						textures[7], textures[8], textures[9]			);
		if( shownHelp == HELP ) { renderHelp( textures[10] ); };
						
	glPopMatrix();
	
    glutSwapBuffers();
}

void handleKeys( unsigned char key, int x, int y )
{
		switch( key )
		{
			case '+': increaseIntensity( &light ); break;
			case '-': decreaseIntensity( &light ); break;
			case 'w': case 'a': case 's': case 'd': case 'q': case 'e': moveCamera( &camera, key ); cameraData( &camera ); break;
		}
		
		glutPostRedisplay();
}

void handleSpecialKeys( int key, int x, int y )
{
	toggleHelp( key, &shownHelp );
	
	glutPostRedisplay();
}


void handleMouse( int button, int state, int x, int y )
{
	if( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
	{
		moveCamerabyMouse( &camera, x, y );
	}
}


void init_camera()
{
	initCamera( &camera, 10.0, M_PI / 2, M_PI / 4, 0, 0 );
	
	printf( "\n=================== \nCamera successfully initialized! \n=================== \n \n" );
}

void init_models()
{
	load_model( &cube, "OBJECTS/cube.obj" ); 
	
	printf( "\n=================== \nCUBE successfully loaded! \n=================== \nModel info: \n---------- \n" );
	print_model_info( &cube );
	print_bounding_box( &cube );
	printf( "\n************************** \n \n" );
	
	load_model( &matches, "OBJECTS/gyufatriexp.obj" );
	
	printf( "\n=================== \nMATCHES successfully loaded! \n=================== \nModel info: \n---------- \n" );
	print_model_info( &matches );
	print_bounding_box( &matches );
	printf( "\n************************** \n" );
}

void init_textures()
{
	glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
	
	loadTextures( &textures[0], "TEXTURES/box.jpg" );
	loadTextures( &textures[1], "TEXTURES/Matches/matches_top.jpg" );
	loadTextures( &textures[2], "TEXTURES/Matches/matches_side.png" );
	loadTextures( &textures[3], "TEXTURES/Matches/matches_bottom.png" );
	loadTextures( &textures[4], "TEXTURES/Skybox/Vasa/top.jpg" );
	loadTextures( &textures[5], "TEXTURES/Skybox/Vasa/front.jpg" );
	loadTextures( &textures[6], "TEXTURES/Skybox/Vasa/right.jpg" );
	loadTextures( &textures[7], "TEXTURES/Skybox/Vasa/left.jpg" );
	loadTextures( &textures[8], "TEXTURES/Skybox/Vasa/bottom.jpg" );
	loadTextures( &textures[9], "TEXTURES/Skybox/Vasa/back.jpg" );
	loadTextures( &textures[10], "TEXTURES/help.jpg" );
	
	glTexEnvf( GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE );
	glEnable( GL_TEXTURE_2D );
	
	printf( "\n=================== \nTextures successfully loaded! \n=================== \n" );
}

void init_lights()
{
	RGB lightColor;
	initRGB( &lightColor, 1.0, 1.0, 1.0 );
	pos3D lightPosition;
	
	initPos3D( &lightPosition, 10.0, 50.0, 10.0 );
	initLights( &light, 1.0, lightColor, lightPosition, GL_LIGHT0 );
	
	printf( "\n=================== \nLights successfully initalized! \n=================== \nDetails: \n---------- " );
	
	printLightDetails( &light );
}


void renderModels()
{
	glPushMatrix();
		glTranslatef( cubePosX, cubePosY, cubePosZ );
		glBindTexture( GL_TEXTURE_2D, textures[0].id );
		draw_model( &cube );
	glPopMatrix();
	
	//glTranslatef( 20.0, 0.0, 0.0 );
	glTranslatef( 8.0, 0.0, 0.0 );
	glBindTexture( GL_TEXTURE_2D, textures[1].id );
	draw_model( &matches );
}

void renderLight()
{
	renderALight( &light );
}