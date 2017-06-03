#ifndef _GraphicsObject_Color
#define _GraphicsObject_Color

#include "GraphicsObject_Base.h"
//#include "Vect.h"

class ShaderColor;
class Vect;
class ShaderColor_DrawCmd;

class GraphicsObject_Color : public GraphicsObject_Base
{
public:
	GraphicsObject_Color() = delete;											// Defualt constructor deleted
	GraphicsObject_Color(const GraphicsObject_Color&) = delete;					// Copy constructor
	GraphicsObject_Color(GraphicsObject_Color&&) = default;						// Move constructor
	GraphicsObject_Color& operator=(const GraphicsObject_Color&) & = default;	// Copy assignment operator
	GraphicsObject_Color& operator=(GraphicsObject_Color&&) & = default;		// Move assignment operator
	~GraphicsObject_Color();		  											// Destructor

	void SetColor(const Vect& col);
	void SetColor(const Vect& col, int meshnum);

	virtual void Render(Camera* mCam) override;

	GraphicsObject_Color(Model* model, ShaderBase* pShaderObj);

private:
	ShaderColor_DrawCmd*			pDrawCmd;
	ShaderColor*					pShader;
	Vect*							MeshColors;
};

#endif _GraphicObject_Color
