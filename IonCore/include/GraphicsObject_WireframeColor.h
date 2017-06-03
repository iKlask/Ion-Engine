#ifndef _GraphicsObject_WireframeColor
#define _GraphicsObject_WireframeColor

#include "GraphicsObject_Base.h"
//#include "Vect.h"

class ShaderWireframeColor;
class Vect;
class ShaderWireframeColor_DrawCmd;
//#include <d3d11.h>

class GraphicsObject_WireframeColor : public GraphicsObject_Base
{
public:
	GraphicsObject_WireframeColor() = delete;											// Defualt constructor deleted
	GraphicsObject_WireframeColor(const GraphicsObject_WireframeColor&) = delete;					// Copy constructor
	GraphicsObject_WireframeColor(GraphicsObject_WireframeColor&&) = default;						// Move constructor
	GraphicsObject_WireframeColor& operator=(const GraphicsObject_WireframeColor&) & = default;	// Copy assignment operator
	GraphicsObject_WireframeColor& operator=(GraphicsObject_WireframeColor&&) & = default;		// Move assignment operator
	~GraphicsObject_WireframeColor();		  											// Destructor


	void SetColor(float r, float g, float b);
	void SetColor(float r, float g, float b, int meshnum);
	void SetColor(const Vect& col);
	void SetColor(const Vect& col, int meshnum);

	virtual void Render(Camera* mCam) override;
	void RenderCmd(Camera * mCam);

	GraphicsObject_WireframeColor(Model* model, ShaderBase* pShaderObj, const Vect& col = Vect(1.0f,1.0f,1.0f) );

private:
	ShaderWireframeColor_DrawCmd*	pDrawCmd;
	ShaderWireframeColor*			pShader;
	Vect*							MeshColors;
};

#endif _GraphicObject_Color
