#ifndef _GraphicsObject_Texture
#define _GraphicsObject_Texture

#include "GraphicsObject_Base.h"

class Texture;
class ShaderTexture;
class ShaderTexture_DrawCmd;

class GraphicsObject_Texture : public GraphicsObject_Base
{
public:
	GraphicsObject_Texture() = delete;												// Defualt constructor deleted
	GraphicsObject_Texture(const GraphicsObject_Texture&) = delete;					// Copy constructor
	GraphicsObject_Texture(GraphicsObject_Texture&&) = default;						// Move constructor
	GraphicsObject_Texture& operator=(const GraphicsObject_Texture&) & = default;	// Copy assignment operator
	GraphicsObject_Texture& operator=(GraphicsObject_Texture&&) & = default;		// Move assignment operator
	~GraphicsObject_Texture();		  												// Destructor

	void SetTexture(Texture* tex);
	void SetTexture(Texture* tex, int meshnum);

	virtual void Render(Camera* mCam) override;

	GraphicsObject_Texture(Model* model, ShaderBase *pShaderObj);	//(no texture)
	GraphicsObject_Texture(Model *model, ShaderBase *pShaderObj, Texture *pTex);
	GraphicsObject_Texture(Model *model, ShaderBase *pShaderObj, Texture *pTex, Texture *pTex2);
	GraphicsObject_Texture(Model *model, ShaderBase *pShaderObj, Texture *pTex, Texture *pTex2, Texture *pTex3);
	GraphicsObject_Texture(Model *model, ShaderBase *pShaderObj, Texture *pTex, Texture *pTex2, Texture *pTex3, Texture *pTex4);

private:
	ShaderTexture_DrawCmd*			pDrawCmd;
	ShaderTexture*					pShader;
	Texture**						MeshTex;
};

#endif _GraphicObject_Texture
