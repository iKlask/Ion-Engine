#ifndef _GraphicsObject_Sprite
#define _GraphicsObject_Sprite

#include "GraphicsObject_Base.h"

class Texture;
class ShaderSprite;
class Image;
struct Rect;
class ShaderSprite_DrawCmd;
//#include "Image.h"

class GraphicsObject_Sprite : public GraphicsObject_Base
{
public:
	GraphicsObject_Sprite() = delete;												// Defualt constructor deleted
	GraphicsObject_Sprite(const GraphicsObject_Sprite&) = delete;					// Copy constructor
	GraphicsObject_Sprite(GraphicsObject_Sprite&&) = default;						// Move constructor
	GraphicsObject_Sprite& operator=(const GraphicsObject_Sprite&) & = default;	// Copy assignment operator
	GraphicsObject_Sprite& operator=(GraphicsObject_Sprite&&) & = default;		// Move assignment operator
	~GraphicsObject_Sprite();		  												// Destructor

	virtual void Render(Camera* mCam) override;

	GraphicsObject_Sprite(Model *model, ShaderBase *pShaderObj, Image* image, const Rect& rect);
	float getPosX() {	return origPosX;	};
	float getPosY() {	return origPosY;	};

private:
	Matrix			pMatrix_uv;
	Matrix			pMatrix_orig;

	ShaderSprite*	pShader;
	Image*			pImage;
	ShaderSprite_DrawCmd* pDrawCmd;

	float			origWidth;
	float			origHeight;
	float			origPosX;
	float			origPosY;
};

#endif _GraphicObject_Texture
