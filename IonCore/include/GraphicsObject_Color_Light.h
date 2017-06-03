#ifndef _GraphicObject_Color_Light
#define _GraphicObject_Color_Light

#include "GraphicsObject_Base.h"

struct LightData;
class Vect;
class ShaderColorLight;
class ShaderColorLight_DrawCmd;

class GraphicsObject_Color_Light : public GraphicsObject_Base
{
public:
	GraphicsObject_Color_Light() = delete;													// Defualt constructor deleted
	GraphicsObject_Color_Light(const GraphicsObject_Color_Light&) = delete;					// Copy constructor
	GraphicsObject_Color_Light(GraphicsObject_Color_Light&&) = default;						// Move constructor
	GraphicsObject_Color_Light& operator=(const GraphicsObject_Color_Light&) & = default;	// Copy assignment operator
	GraphicsObject_Color_Light& operator=(GraphicsObject_Color_Light&&) & = default;		// Move assignment operator
	~GraphicsObject_Color_Light();		  													// Destructor

	void SetLightColors(const Vect& amb_ref, const Vect& diff_ref, const Vect& spec_ref = Vect(0.7f, 0.7f, 0.7f, 150));
	void SetLightColors(int meshNum, const Vect & amb_ref, const Vect & diff_ref, const Vect & spec_ref = Vect(0.7f, 0.7f, 0.7f, 150));

	virtual void Render(Camera* mCam) override;

	GraphicsObject_Color_Light(Model * model, ShaderBase * pShaderObj);
	GraphicsObject_Color_Light(Model * model, ShaderBase * pShaderObj, const Vect & colorLight);
	GraphicsObject_Color_Light(Model * model, ShaderBase * pShaderObj, const Vect & amb_ref, const Vect & diff_ref, const Vect & spec_ref);
private:
	ShaderColorLight_DrawCmd* pDrawCmd;
	ShaderColorLight*		pShader;
	LightData*				light_data;
};

#endif _GraphicObject_Light_Color
