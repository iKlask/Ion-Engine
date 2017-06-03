#include "MainMenuScene.h"

#include "MainMenuScreen.h"
#include "DummyTank.h"
#include "RotateCam.h"


void MainMenuScene::Initialize()
{
	SetTerrain("Terrain_Rock");
	SetSkyBox("SkyBox_ONE");

	obj_Tank = new DummyTank();
	obj_MenuScreen = new MainMenuScreen();
	//obj_WorldPlane = new WorldPlane();
	obj_RotCam = new RotateCam(obj_Tank->GetDummyTankPos());

	this->SetCamera(obj_RotCam);

	//obj_WorldPlane->SubmitEntry();
	obj_Tank->SubmitEntry();
}

void MainMenuScene::SceneEnd()
{
	obj_Tank->SubmitExit();
	//obj_WorldPlane->SubmitExit();
}

MainMenuScene::~MainMenuScene()
{
	delete obj_Tank;
	//delete obj_WorldPlane;
	delete obj_MenuScreen;
}
