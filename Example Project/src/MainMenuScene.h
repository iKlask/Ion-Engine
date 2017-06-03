#ifndef MainMenuScene_H
#define MainMenuScene_H

//#include "IonCore.h"
#include "Scene.h"

class DummyTank;
class WorldPlane;
class RotateCam;
class MainMenuScreen;

class MainMenuScene : public Scene {
public:
	MainMenuScene() {};
	~MainMenuScene();
	MainMenuScene(const MainMenuScene&) = delete;
	MainMenuScene& operator=(const MainMenuScene&) = delete;
private:
	virtual void Initialize() override;
	virtual void SceneEnd() override;

	DummyTank* obj_Tank;
	//WorldPlane* obj_WorldPlane;
	RotateCam* obj_RotCam;
	MainMenuScreen* obj_MenuScreen;


};
#endif