#ifndef CAMERA_H
#define CAMERA_H

typedef struct camera
{
	double zoom;
	double hAngle;
	double vAngle;
	double mousePosX;
	double mousePosY;
} Camera;

void initCamera( Camera* camera, double zoom, double hAngle, double vAngle, double mousePosX, double mousePosY );
void renderCamera( Camera* camera );
void moveCamera( Camera* camera, unsigned char key );
void cameraData( Camera* camera );
void moveCamerabyMouse( Camera* camera, int x, int y );

#endif /* CAMERA_H */