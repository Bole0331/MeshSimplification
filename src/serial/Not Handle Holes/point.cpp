#include <cmath>
#include "point.h"

double point::length() const {
	return sqrt(x * x + y * y + z * z);
}

const point point::normalize() const {
	double l = length();
	return point(x / l , y / l , z / l);
}

bool point::operator == (const point & cmp) const {
	return  x == cmp.x  && y == cmp.y && z == cmp.z;
}

bool point::operator < (const point & cmp) const {
	if (x == cmp.x) {
		if (y == cmp.y) 
			return z < cmp.z;
		else return y < cmp.y;
	} else return x < cmp.x;
}

double point::operator [] (int t) const {
	if (t == 0) return x;
	else if (t == 1) return y;
	else if (t == 2) return z;
	else return 1.0;
}

double point::operator * (const point & cmp) const {
	return x * cmp.x + y * cmp.y + z * cmp.z;
}

const point operator * (const point & _p, double a) {
	return point(_p.x * a, _p.y * a, _p.z * a);
}

const point operator / (const point & _p, double a) {
	return point(_p.x / a, _p.y / a, _p.z / a);
}

const point operator + (const point & _p, const point & _q) {
	return point(_p.x + _q.x, _p.y + _q.y, _p.z + _q.z);
}

