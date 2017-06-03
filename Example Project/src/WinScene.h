#ifndef WinScene_H
#define WinScene_H

//#include "IonCore.h"
#include "Scene.h"


//class Tank;
//class WorldPlane;
//class FirstPersonCam;
class WinScreenObject;

class WinScene : public Scene {
public:
	WinScene() {};
	~WinScene();
	WinScene(const WinScene&) = delete;
	WinScene& operator=(const WinScene&) = delete;
private:
	virtual void Initialize() override;
	virtual void SceneEnd() override;

	WinScreenObject* obj;
};
#endif