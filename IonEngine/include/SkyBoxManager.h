#ifndef SKYBOXMANAGER_H
#define SKYBOXMANAGER_H

class RenderType;
class NullSkyBox;
class SkyBox;
class Camera;

class SkyBoxManager {
private:
	friend class Scene;

	RenderType* CurSky;
	NullSkyBox* nullS;

	void RenderSkyBox(Camera* pCam);

public:
	SkyBoxManager();
	~SkyBoxManager();
	SkyBoxManager(const SkyBoxManager&) = delete;
	SkyBoxManager& operator=(const  SkyBoxManager&) = delete;

	void SetSceneSkyBox(SkyBox* sky);
};

#endif