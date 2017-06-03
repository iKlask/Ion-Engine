#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "Scene.h"

class Tank;
class DummyTank;
class WorldPlane;
class FirstPersonCam;
class Hud;

class LevelTwo : public Scene {
public:
	LevelTwo() {};
	~LevelTwo();
	LevelTwo(const LevelTwo&) = delete;
	LevelTwo& operator=(const LevelTwo&) = delete;
private:
	virtual void Initialize() override;
	virtual void SceneEnd() override;

	Tank* obj_Tank;
	FirstPersonCam* fpCam;
	Hud* obj_HUD;
};
#endif