#ifndef GPUVERTTYPES_H
#define GPUVERTTYPES_H

#include "Align16.h"
#include "Vect.h"

struct StandardVertex : public Align16
{
	Vect Pos;
	float u;
	float v;
	Vect normal;
	Vect Color;
	int meshNum;

	//Sets Pos, U, V, Normal (from 3 floats), color (from 3 floats), and meshNum
	void set(float _x, float _y, float _z,
		float _u = 0, float _v = 0,
		float _nx = 0, float _ny = 0, float _nz = 0,
		float _r = 1, float _g = 1, float _b = 1, int num = 0)
	{
		Pos = Vect(_x, _y, _z);
		u = _u;
		v = _v;
		normal = Vect(_nx, _ny, _nz, 0);
		Color = Vect(_r, _g, _b);
		meshNum = num;
	}

	//Sets Pos, U,V, color(from vect), and meshNum
	void set(float _x, float _y, float _z, float _u, float _v, const Vect& c, int num = 0)
	{
		Pos = Vect(_x, _y, _z);
		u = _u;
		v = _v;
		Color = c;
		meshNum = num;
	}

	//Sets Pos, U,V, Normal(from vect), color(from vect), and meshNum
	void set(float _x, float _y, float _z, float _u, float _v, const Vect& n, const Vect& c, int num = 0)
	{
		Pos = Vect(_x, _y, _z);
		u = _u;
		v = _v;
		normal = n;
		Color = c;
		meshNum = num;
	}

	//Sets Pos, color(from vect), and meshNum. defualts U/V to 0
	void set(float _x, float _y, float _z, const Vect& c, int num = 0)
	{
		Pos = Vect(_x, _y, _z);
		u = 0;
		v = 0;
		Color = c;
		meshNum = num;
	}

	//Sets Pos, normal(from vect), color(from vect), and meshNum. defualts U/V to 0
	void set(float _x, float _y, float _z, const Vect& n, const Vect& c, int num = 0)
	{
		Pos = Vect(_x, _y, _z);
		u = 0;
		v = 0;
		normal = n;
		Color = c;
		meshNum = num;
	}

	//Sets Pos(from vect) and color(from vect)
	void set(const Vect& p, const Vect& c)
	{
		Pos = p;
		Color = c;
	}

	//Sets just the normal
	void setNorm(float _nx = 0, float _ny = 0, float _nz = 0)
	{
		normal = Vect(_nx, _ny, _nz, 0);
	}

	//Sets just the normal(from Vect)
	void setNorm(const Vect& n)
	{
		normal = n;
	}

	const Vect& getVect() {
		return Pos;
	}
};

struct TriangleByIndex : public Align16
{
	unsigned int v0;
	unsigned int v1;
	unsigned int v2;

	void set(int _v0, int _v1, int _v2)
	{
		v0 = _v0;
		v1 = _v1;
		v2 = _v2;
	}
};

#endif
