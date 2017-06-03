#include "RenderTestScene.h"
#include "SphereTest.h"


RenderTestScene::RenderTestScene()
{
}

RenderTestScene::~RenderTestScene()
{
	delete gObj_Array;
}

void RenderTestScene::Initialize()
{
	SetSkyBox("SkyBox_ONE");

	//*
	Vect pos = Vect(0, 0, 0);
	int count = 0;
	int size = 10l;
	gObj_Array = new SphereTest*[size*size*size];

	for (int i = 0; i < size; i++) {
		pos[y] = 0;
		for (int j = 0; j < size; j++) {
			pos[z] = 0;
			for (int k = 0; k < size; k++) {
				gObj_Array[count] = new SphereTest(pos);
				pos += Vect(0, 0, 7);
				count++;
			}
			pos += Vect(0, 7, 0);
		}
		pos += Vect(7, 0, 0);
	}
	DebugMsg::out("Num Spheres: %d\n", count);
	//*/
}

void RenderTestScene::SceneEnd()
{
}
