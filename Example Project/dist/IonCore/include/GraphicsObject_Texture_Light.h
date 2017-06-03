#ifndef _GraphicsObject_Texture_Light
#define _GraphicsObject_Texture_Light

#include "GraphicsObject_Base.h"

struct LightData;
class Vect;
class Texture;
class ShaderTextureLight;
class ShaderTextureLight_DrawCmd;

class GraphicsObject_Texture_Light : public GraphicsObject_Base
{
public:
	GraphicsObject_Texture_Light() = delete;													// Defualt constructor deleted
	GraphicsObject_Texture_Light(const GraphicsObject_Texture_Light&) = delete;					// Copy constructor
	GraphicsObject_Texture_Light(GraphicsObject_Texture_Light&&) = default;						// Move constructor
	GraphicsObject_Texture_Light& operator=(const GraphicsObject_Texture_Light&) & = default;	// Copy assignment operator
	GraphicsObject_Texture_Light& operator=(GraphicsObject_Texture_Light&&) & = default;		// Move assignment operator
	~GraphicsObject_Texture_Light();		  													// Destructor


	void SetLightColors(const Vect& color);

	void SetLightColors(const Vect& amb_ref, const Vect& diff_ref, const Vect& spec_ref);
	void SetLightColors(const Vect & amb_ref, const Vect & diff_ref, const Vect & spec_ref, int meshNum);
	void SetTexture(Texture* tex);
	void SetTexture(Texture* tex, int meshNum);

	virtual void Render(Camera* mCam) override;

	GraphicsObject_Texture_Light(Model *model, ShaderBase *pShaderObj);
	/*
	GraphicsObject_Texture_Light(Model *model, ShaderTextureLight *pShaderObj, Texture *pTex, const Vect & amb_ref, const Vect & diff_ref, const Vect & spec_ref = Vect(.7, .7, .7, 150));
	GraphicsObject_Texture_Light(Model *model, ShaderTextureLight *pShaderObj, Texture *pTex, Texture *pTex2, const Vect & amb_ref, const Vect & diff_ref, const Vect & spec_ref = Vect(.7, .7, .7, 150));
	GraphicsObject_Texture_Light(Model *model, ShaderTextureLight *pShaderObj, Texture *pTex, Texture *pTex2, Texture *pTex3, const Vect & amb_ref, const Vect & diff_ref, const Vect & spec_ref = Vect(.7, .7, .7, 150));
	GraphicsObject_Texture_Light(Model *model, ShaderTextureLight *pShaderObj, Texture *pTex, Texture *pTex2, Texture *pTex3, Texture *pTex4, const Vect & amb_ref, const Vect & diff_ref, const Vect & spec_ref = Vect(.7, .7, .7, 150));
	//*/

	//	GraphicsObject_Texture_Light(Model *model, ShaderTextureLight *pShaderObj, Texture *pTex, const Vect &LightColor, const Vect &LightPos);

	GraphicsObject_Texture_Light(Model *model, ShaderBase *pShaderObj, Texture *pTex, const Vect &LightColor);
	GraphicsObject_Texture_Light(Model *model, ShaderBase *pShaderObj, Texture *pTex, Texture *pTex2, const Vect &LightColor);
	GraphicsObject_Texture_Light(Model *model, ShaderBase *pShaderObj, Texture *pTex, Texture *pTex2, Texture *pTex3, const Vect &LightColor);
	GraphicsObject_Texture_Light(Model *model, ShaderBase *pShaderObj, Texture *pTex, Texture *pTex2, Texture *pTex3, Texture *pTex4, const Vect &LightColor);

private:
	ShaderTextureLight_DrawCmd*	pDrawCmd;
	ShaderTextureLight*			pShader;
	Texture**					MeshTex;
	LightData*					light_data;
};

#endif _GraphicObject_Light_Texture
