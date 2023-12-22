#include "Figura.h"


Figura::Figura() {
	mode = 1;
	count = 4;
	facesCount = count;
	for (int i = 0;i < 4;++i)
		scale[i] = 1;
	points = new point[count];
	ConstructPyramid();
}
Figura::Figura(int a) : mode(a) {
	for (int i = 0;i < 4;++i)
		scale[i] = 1;
	switch (mode) {
	case 1: {
		count = 4;
		facesCount = count;
		points = new point[count];
		ConstructPyramid();
		break;
	}
	case 2: {
		count = 6;
		facesCount = 5;
		points = new point[count];
		ConstructPrism();
		break;
	}
	}
}
Figura::~Figura() {
	switch (mode) {
	case 1: {
		delete[] points;
		delete[] base;
		for (int i = 0;i < count;++i)
			delete[] faces[i].points;
		delete[] faces;
		break;
	}
	case 2: {
		delete[] points;
		delete[] base;
		for (int i = 0;i < count - 1;++i)
			delete[] faces[i].points;
		delete[] faces;
		break;
	}
	}
}

void Figura::ConstructPyramid() {
	double grad = -90;
	grad -= 360 / ((count - 1) * 2);
	int i;
	for (i = 0;i < count - 1;++i) {
		points[i].x = 200 + 50 * cos((PI * grad) / 180);
		points[i].y = 300 - 50 * sin((PI * grad) / 180);
		points[i].z = 0;
		grad += 360 / (count - 1);
	}
	points[count-1] = { 200,300,100 };
	FindMid();
	Axis = 'X';
	base = Copy();
	Rotate(-75);

	faces = new Face[count];
	faces[count - 1].points = new point[count - 1];
	faces[count - 1].count = count - 1;
	faces[count - 1].code = count - 1;
	for (int i = 0;i < count - 1;i++) {
		faces[i].code = i;
		faces[i].count = 3;
		faces[i].points = new point[3];
	}
	RenewFaces();
}
void Figura::ConstructPrism() {
	double grad = -90;
	grad -= 360 / ((count / 2) * 2);
	int i;
	for (i = 0;i < count / 2;++i) {
		points[i].x = 400 + 50 * cos((PI * grad) / 180);
		points[i].y = 300 - 50 * sin((PI * grad) / 180);
		points[i].z = 50;

		points[i + (count / 2)].x = 400 + 50 * cos((PI * grad) / 180);
		points[i + (count / 2)].y = 300 - 50 * sin((PI * grad) / 180);
		points[i + (count / 2)].z = -50;
		grad += 360 / (count / 2);
	}
	FindMid();
	Axis = 'X';
	base = Copy();
	Rotate(-105);

	faces = new Face[count - 1];
	faces[(count / 2) + 1].points = new point[count / 2];
	faces[(count / 2) + 1].count = (count / 2) + 1;
	faces[(count / 2) + 1].code = (count / 2) + 1;

	faces[(count / 2)].points = new point[count / 2];
	faces[(count / 2)].count = (count / 2);
	faces[(count / 2)].code = (count / 2);

	for (int i = 0;i < (count / 2);i++) {
		faces[i].code = i;
		faces[i].count = 4;
		faces[i].points = new point[4];
	}
	RenewFaces();
}
void Figura::DScale(double dx, double dy, double dz, double d) {
	scale[0] += dx;
	scale[1] += dy;
	scale[2] += dz;
	scale[3] += d;
}

point Figura::GetPoint(int i) {
	point p;
	p.x = int(base[i].x);
	p.y = int(base[i].y);
	p.z = int(base[i].z);
	return p;
}
int Figura::GetCount() {
	return count;
}
void Figura::FindMid() {
	double X = 0, Y = 0, Z = 0;
	for (int i = 0;i < count;++i) {
		X += points[i].x;
		Y += points[i].y;
		Z += points[i].z;
	}
	mid.x = X / count;
	mid.y = Y / count;
	mid.z = Z / count;
}
void Figura::ChangeAxis(char c) {
	Axis = c;
}
point* Figura::Copy() {
	point* d = new point[count];
	for (int i = 0;i < count;++i) {
		d[i] = points[i];
	}
	return d;
}

void Figura::Move(int dX, int dY, int dZ) {
	for (int i = 0;i < count;++i) {
		points[i].x += dX;
		points[i].y += dY;
		points[i].z += dZ;

		base[i].x += dX;
		base[i].y += dY;
		base[i].z += dZ;
	}
	mid.x += dX;
	mid.y += dY;
	mid.z += dZ;
}
void Figura::Rotate(int grad) {
	point d;
	double cs, sn;
	cs = cos((PI * grad) / 180);
	sn = sin((PI * grad) / 180);
	switch (Axis) {
	case 'X': {
		for (int i = 0;i < count;++i) {
			d = { 0, points[i].y - mid.y, points[i].z - mid.z };
			points[i].y = mid.y + d.y * cs + d.z * sn;
			points[i].z = mid.z + d.y * (-sn) + d.z * cs;

			d = { 0, base[i].y - mid.y, base[i].z - mid.z };
			base[i].y = mid.y + d.y * cs + d.z * sn;
			base[i].z = mid.z + d.y * (-sn) + d.z * cs;
		}
		break;
	}
	case 'Y': {
		for (int i = 0;i < count;++i) {
			d = { points[i].x - mid.x, 0, points[i].z - mid.z };
			points[i].x = mid.x + d.x * cs + d.z * sn;
			points[i].z = mid.z + d.x * (-sn) + d.z * cs;

			d = { base[i].x - mid.x, 0, base[i].z - mid.z };
			base[i].x = mid.x + d.x * cs + d.z * sn;
			base[i].z = mid.z + d.x * (-sn) + d.z * cs;
		}
		break;
	}
	case 'Z': {
		for (int i = 0;i < count;++i) {
			d = { points[i].x - mid.x, points[i].y - mid.y, 0 };
			points[i].x = mid.x + d.x * cs + d.y * sn;
			points[i].y = mid.y + d.x * (-sn) + d.y * cs;

			d = { base[i].x - mid.x, base[i].y - mid.y, 0 };
			base[i].x = mid.x + d.x * cs + d.y * sn;
			base[i].y = mid.y + d.x * (-sn) + d.y * cs;
		}
		break;
	}
	};
}
void Figura::Scale(bool flag, double a) {
	if (flag) {
		DScale(0, 0, 0, a);
		for (int i = 0;i < count;++i) {
			base[i].x = mid.x + (points[i].x - mid.x) * scale[0] * scale[3];
			base[i].y = mid.y + (points[i].y - mid.y) * scale[1] * scale[3];
			base[i].z = mid.z + (points[i].z - mid.z) * scale[2] * scale[3];
		}
		return;
	}
	switch (Axis) {
	case 'X': {
		DScale(a, 0, 0, 0);
		for (int i = 0;i < count;++i) {
			base[i].x = mid.x + (points[i].x - mid.x) * scale[0] * scale[3];
			base[i].y = mid.y + (points[i].y - mid.y) * scale[1] * scale[3];
			base[i].z = mid.z + (points[i].z - mid.z) * scale[2] * scale[3];
		}
		break;
	}
	case 'Y': {
		DScale(0, a, 0, 0);
		for (int i = 0;i < count;++i) {
			base[i].x = mid.x + (points[i].x - mid.x) * scale[0] * scale[3];
			base[i].y = mid.y + (points[i].y - mid.y) * scale[1] * scale[3];
			base[i].z = mid.z + (points[i].z - mid.z) * scale[2] * scale[3];
		}
		break;
	}
	case 'Z': {
		DScale(0, 0, a, 0);
		for (int i = 0;i < count;++i) {
			base[i].x = mid.x + (points[i].x - mid.x) * scale[0] * scale[3];
			base[i].y = mid.y + (points[i].y - mid.y) * scale[1] * scale[3];
			base[i].z = mid.z + (points[i].z - mid.z) * scale[2] * scale[3];
		}
		break;
	}
	};
}

void Figura::RenewFaces() {
	int i = 0;
	switch (mode) {
	case 1:
		point p = base[count - 2];
		faces[count - 1].count = count - 1;
		for (;i < count - 1;i++) {
			faces[i].count = 3;
			faces[i].points[0] = base[count - 1];
			faces[i].points[1] = base[i];
			faces[i].points[2] = p;
			p = base[i];
			faces[count - 1].points[i] = base[i];
		}

		for (int j = 0;j < count;j++) {
			faces[j].equation_plane();
			if (faces[j].f(mid.x, mid.y, mid.z) < 0) {
				faces[j].sign();
			}
		}
		break;
	case 2:
		point p1 = base[(count / 2) - 1];
		point p2 = base[count - 1];
		faces[count / 2].count = (count / 2);
		faces[count / 2 + 1].count = (count / 2);
		for (;i < count / 2;i++) {

			faces[i].count = 4;

			faces[i].points[0] = base[i];
			faces[i].points[1] = base[i + (count / 2)];

			faces[i].points[2] = p2;
			faces[i].points[3] = p1;
			p1 = base[i];
			p2 = base[i + (count / 2)];
		}
		i--;
		for (;i >= 0;i--) {
			faces[count / 2].points[i] = base[i];
			faces[count / 2 + 1].points[i] = base[i + (count / 2)];
		}

		for (int j = 0;j < count - 1;j++) {
			faces[j].equation_plane();
			if (faces[j].f(mid.x, mid.y, mid.z) < 0) {
				faces[j].sign();
			}
		}
		break;
	}


}


Face Figura::FindFaceMid(Face face) {
	double X = 0, Y = 0, Z = 0;
	for (int i = 0;i < face.count;++i) {
		X += face.points[i].x;
		Y += face.points[i].y;
		Z += face.points[i].z;
	}
	face.mid.x = X / face.count;
	face.mid.y = Y / face.count;
	face.mid.z = Z / face.count;
	return face;
}

Face* Figura::getFaces() {
	return faces;
}

Face* Figura::SortFaces() {
	Face* f = new Face[5];
	for (int i = 0;i < 5;++i) {
		f[i] = FindFaceMid(faces[i]);
	}
	Face temp;

	int flag = 1;
	while (flag == 1) {
		flag = 0;
		for (int i = 0;i < 4;++i) {
			if (f[i].mid.z < f[i + 1].mid.z) {
				temp = f[i];
				f[i] = f[i + 1];
				f[i + 1] = temp;
				flag = 1;
			}
		}
	}
	return f;
}

void Face::equation_plane() {
	float a1 = points[1].x - points[0].x;
	float b1 = points[1].y - points[0].y;
	float c1 = points[1].z - points[0].z;
	float a2 = points[2].x - points[0].x;
	float b2 = points[2].y - points[0].y;
	float c2 = points[2].z - points[0].z;
	float a = b1 * c2 - b2 * c1;
	float b = a2 * c1 - a1 * c2;
	float c = a1 * b2 - b1 * a2;
	float d = (-a * points[0].x - b * points[0].y - c * points[0].z);
	plane[0] = a;
	plane[1] = b;
	plane[2] = c;
	plane[3] = d;
}

void Face::sign() {
	plane[0] = -plane[0];
	plane[1] = -plane[1];
	plane[2] = -plane[2];
	plane[3] = -plane[3];
}

float Face::f(float X, float Y, float Z) {
	return (X * plane[0] + Y * plane[1] + Z * plane[2] + plane[3]);
}

void Face::visibility(point v) {
	float result = v.x * plane[0] + v.y * plane[1] + v.z * plane[2];
	if (result >= -300)
		isVisible = 0;
	else
		isVisible = 1;
}

void Face::FindFaceMid() {
	double X = 0, Y = 0, Z = 0;
	for (int i = 0;i < count;++i) {
		X += points[i].x;
		Y += points[i].y;
		Z += points[i].z;
	}
	mid.x = X / count;
	mid.y = Y / count;
	mid.z = Z / count;
}
