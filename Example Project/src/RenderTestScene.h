#ifndef RENDERTESTSCENE_H
#define RENDERTESTSCENE_H

#include "Scene.h"

class SphereTest;
class GraphicsObject_Texture_Light;

class RenderTestScene : public Scene
{
private:
	~RenderTestScene();
	RenderTestScene(const RenderTestScene&) = delete;
	RenderTestScene& operator=(const RenderTestScene&) = delete;
public:
	RenderTestScene();

	virtual void Initialize() override;
	virtual void SceneEnd() override;

	SphereTest** gObj_Array;
};


#endif // !RENDERTESTSCENE_H