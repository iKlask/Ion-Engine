#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "Scene.h"

class Tank;
class DummyTank;
class WorldPlane;
class FirstPersonCam;
class Hud;

class LevelThree : public Scene {
public:
	LevelThree() {};
	~LevelThree();
	LevelThree(const LevelThree&) = delete;
	LevelThree& operator=(const LevelThree&) = delete;
private:
	virtual void Initialize() override;
	virtual void SceneEnd() override;

	Tank* obj_Tank;
	FirstPersonCam* fpCam;
	Hud* obj_HUD;
};
#endif