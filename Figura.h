#pragma once
#include <math.h>
#define PI 3.14159265358979323846

struct point {
	double x;
	double y;
	double z;
};

class Face {
public:
	point* points;
	point mid;
	int count;      // кол-во точек
	int code;
	float plane[4];
	void equation_plane();
	void sign();
	void visibility(point v);
	void FindFaceMid();
	float f(float X, float Y,float Z);
	bool isVisible;
};

class Figura
{
public:
	Figura();
	Figura(int a);
	~Figura();
	void ConstructPyramid();
	void ConstructPrism();
	void DScale(double dx, double dy, double dz, double d);
	int GetCount();
	int getFacesCount() { return facesCount; };
	point GetPoint(int i);
	point getMid() { return mid; };
	void FindMid();
	void ChangeAxis(char c);
	point* Copy();
	void Move(int dX, int dY, int dZ);
	void Rotate(int grad);
	void Scale(bool flag, double a);
	void RenewFaces();
	Face FindFaceMid(Face face);
	Face* getFaces();
	Face* SortFaces();
	int getMode() { return mode; };
	/*void yToZero();*/
private:
	Face* faces;
	point* points;
	point* base;
	point mid;
	char Axis;
	int count;
	int facesCount;
	double scale[4];
	int mode;
};

