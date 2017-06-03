#ifndef ShaderWireframeColor_H
#define ShaderWireframeColor_H

#include "ShaderBase.h"
#include "Matrix.h"

class ShaderWireframeColor_DrawCmd;

class ShaderWireframeColor : public ShaderBase
{
public:
	ShaderWireframeColor(const ShaderWireframeColor&) = delete;				 // Copy constructor
	ShaderWireframeColor( ShaderWireframeColor&&) = default;                    // Move constructor
	ShaderWireframeColor& operator=(const ShaderWireframeColor&) & = default;  // Copy assignment operator
	ShaderWireframeColor& operator=(ShaderWireframeColor&&) & = default;       // Move assignment operator
	~ShaderWireframeColor();		  							         // Destructor

	 ShaderWireframeColor();

	virtual void SetToContext(ID3D11DeviceContext* devcon) override;

	void SendCamMatrices(const Matrix& view, const Matrix& proj);
	void SendWorldColor(const Matrix& world, const Vect& col);

	void AddDrawCommand(Camera* pCam, Model* pMod, const Matrix& mat, Vect* meshColArray);
	void AddDrawCommand(Camera * pCam, ShaderWireframeColor_DrawCmd * pCmd);
	virtual void RenderShader(ID3D11DeviceContext* devcon) override;

private:
	struct CamMatrices
	{
		Matrix View;
		Matrix Projection;
	};

	ID3D11Buffer*           mpBufferCamMatrices;

	struct Data_WorldColor
	{
		Matrix World;
		Vect Color;
	};

	ID3D11Buffer*           mpBuffWordColor;
};

#endif //ShaderWireframeColor_H
