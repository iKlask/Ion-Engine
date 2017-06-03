#ifndef SkyBox_H
#define SkyBox_H

#include "RenderType.h"

class Model;
class Camera;
class Texture;
class ShaderBase;
class GraphicsObject_Texture;

/////////////////////////////////////////////////
///	\ingroup SKY-BOX
/// \class SkyBox
///	\brief The Skybox Object used with the SkyBoxAssets manager allows users to define a 3D textured cubemap to use as a skybox.
/////////////////////////////////////////////////
class SkyBox : public RenderType
{
private:
	Model* pSky;
	GraphicsObject_Texture* pGobj;
	void BuildSkyBox(float s);

	SkyBox() {};
public:
	SkyBox(float s, ShaderBase* pShader, Texture* pTex);
	SkyBox(const SkyBox&) = delete;				// Copy constructor
	SkyBox& operator=(const SkyBox&) & = delete;  // Copy assignment operator
	~SkyBox();

	virtual void Render(Camera* pCam) override;
};

#endif // !SkyBoxObject_H