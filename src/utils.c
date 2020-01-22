#include <utils.h>

void initPos3D( pos3D* pos, double x, double y, double z )
{
	pos->x = x;
	pos->y = y;
	pos->z = z;
}

void initSize3D( size3D* size, double sizeX, double sizeY, double sizeZ )
{
	size->sizeX = sizeX;
	size->sizeY = sizeY;
	size->sizeZ = sizeZ;
}

void initRGB( RGB* color, double R, double G, double B )
{
	color->R = R;
	color->G = G;
	color->B = B;
}
