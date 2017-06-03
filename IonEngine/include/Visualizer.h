#ifndef VISUALIZER_H
#define VISUALIZER_H

//#include "Align16.h"

//#include "MathEngine.h"
#include <list>

#include "Vect.h" //<- Has Align16

class Matrix;
class GraphicsObject_WireframeColor;
class GraphicsObject_Color;
class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;
class Collidable;

class VizCommand;

#define USE_VISUALIZER 0

class Visualizer : public Align16
{
	friend class VizCommand;
	friend class IonEngine;
private:
	static Visualizer* ptrInstance;

	Visualizer();
	~Visualizer();
	Visualizer(const Visualizer&) = delete;
	Visualizer& operator=(const Visualizer&) = delete;

	static Visualizer& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Visualizer;
		return *ptrInstance;
	};

	Vect DEFAULT_COLOR;
	GraphicsObject_WireframeColor* GOUnitSphere;
	GraphicsObject_WireframeColor* GOUnitBox;


	void privRenderBSphere( Matrix& mSphere, const Vect& color);
	void privRenderAABB(Matrix& mBox, const Vect& color);
	void privRenderOBB(Matrix& mBox, const Vect& color);

	void privShowAll();

	static void RenderBSphere(Matrix& mSphere, const Vect& color) { Instance().privRenderBSphere(mSphere, color); };
	static void RenderAABB(Matrix& mBox, const Vect& color) { Instance().privRenderAABB(mBox, color); };
	static void RenderOBB(Matrix& mBox, const Vect& color) { Instance().privRenderOBB(mBox, color); };


	static void Delete();
public:
	static void ShowCollisionVolume(const Collidable* col, const Vect& color = Instance().DEFAULT_COLOR);

	static void ShowBSphere(const CollisionVolumeBSphere & sphere, const Vect & color = Instance().DEFAULT_COLOR);

	static void ShowAABB(const CollisionVolumeAABB & box, const Vect & color = Instance().DEFAULT_COLOR);
	static void ShowAABB(const Vect & min, const Vect & max, const Vect & color = Instance().DEFAULT_COLOR);

	static void ShowOBB(const CollisionVolumeOBB & box, const Vect & color = Instance().DEFAULT_COLOR);

	static void ShowPoint(const Vect& pos, const Vect & color = Instance().DEFAULT_COLOR);

	static void ShowAll() { Instance().privShowAll(); };
};

#endif
