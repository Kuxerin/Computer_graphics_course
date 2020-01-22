#ifndef UTILS_H
#define UTILS_H

typedef struct pos3D
{ 
    double x;
	double y;
	double z;
} pos3D;

typedef struct size3D
{ 
    double sizeX;
	double sizeY;
	double sizeZ;
} size3D;

typedef struct RGB
{ 
    double R;
	double G;
	double B;
} RGB;

void initPos3D( pos3D* pos, double x, double y, double z );
void initSize3D( size3D* sizes, double sizeX, double sizeY, double sizeZ );
void initRGB( RGB* color, double R, double G, double B );

#endif /* UTILS_H */