#ifndef _GraphicsObject_WireframeColorAuto
#define _GraphicsObject_WireframeColorAuto

#include "GraphicsObject_Base.h"
//#include "Vect.h"

class ShaderColorVary;
class Vect;
//#include <d3d11.h>

class GraphicsObject_WireframeColorAuto : public GraphicsObject_Base
{
public:
	GraphicsObject_WireframeColorAuto() = delete;											// Defualt constructor deleted
	GraphicsObject_WireframeColorAuto(const GraphicsObject_WireframeColorAuto&) = delete;					// Copy constructor
	GraphicsObject_WireframeColorAuto(GraphicsObject_WireframeColorAuto&&) = default;						// Move constructor
	GraphicsObject_WireframeColorAuto& operator=(const GraphicsObject_WireframeColorAuto&) & = default;	// Copy assignment operator
	GraphicsObject_WireframeColorAuto& operator=(GraphicsObject_WireframeColorAuto&&) & = default;		// Move assignment operator
	~GraphicsObject_WireframeColorAuto();		  											// Destructor

	virtual void Render(Camera* mCam) override;

	GraphicsObject_WireframeColorAuto(Model* model, ShaderBase* pShaderObj );

private:
	ShaderColorVary*				pShader;
};

#endif _GraphicObject_Color
