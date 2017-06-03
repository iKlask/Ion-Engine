#ifndef LEVELONE_H
#define LEVELONE_H

#include "Scene.h"

class Tank;
class DummyTank;
class WorldPlane;
class FirstPersonCam;
class Hud;

class LevelOne : public Scene {
public:
	LevelOne() {};
	~LevelOne();
	LevelOne(const LevelOne&) = delete;
	LevelOne& operator=(const LevelOne&) = delete;
private:
	virtual void Initialize() override;
	virtual void SceneEnd() override;

	Tank* obj_Tank;
	FirstPersonCam* fpCam;
	Hud* obj_HUD;
};
#endif