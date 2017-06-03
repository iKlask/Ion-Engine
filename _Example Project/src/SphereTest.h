#ifndef SPHERETEST_H
#define SPHERETEST_H

#include "Drawable.h"
#include "Updatable.h"

#include "Align16.h"
#include "Matrix.h"

class Vect;
class GraphicsObject_Texture_Light;
class GraphicsObject_WireframeColor;

class SphereTest : public Drawable, public Updatable, public Align16
{
private:
	GraphicsObject_Texture_Light* gObj;
	//GraphicsObject_WireframeColor* gObj;
	Matrix world;
public:
	SphereTest() {};
	SphereTest(const Vect& pos);
	virtual ~SphereTest();
	SphereTest(const SphereTest&) = delete;;
	SphereTest& operator=(const SphereTest&) = delete;

	virtual void Draw() override;
	virtual void Update() override;
	virtual void SceneEntry() override;
	virtual void SceneExit() override;
};

#endif // !SPHERETEST_H

