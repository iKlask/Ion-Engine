#ifndef LoseScene_H
#define LoseScene_H

#include "Scene.h"

//class Tank;
//class WorldPlane;
//class FirstPersonCam;
class LoseScreenObject;

class LoseScene : public Scene {
public:
	LoseScene() {};
	~LoseScene();
	LoseScene(const LoseScene&) = delete;
	LoseScene& operator=(const LoseScene&) = delete;
private:
	virtual void Initialize() override;
	virtual void SceneEnd() override;

	LoseScreenObject* obj;
};
#endif