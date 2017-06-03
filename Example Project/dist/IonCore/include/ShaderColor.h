// ShaderColor
// Andre Berthiaume, july 2016

#ifndef _ShaderColor
#define _ShaderColor

#include "ShaderBase.h"
#include "Matrix.h"

class ShaderColor_DrawCmd;

class ShaderColor : public ShaderBase
{
public:
	ShaderColor(const ShaderColor&) = delete;				 // Copy constructor
	ShaderColor(ShaderColor&&) = default;                    // Move constructor
	ShaderColor& operator=(const ShaderColor&) & = default;  // Copy assignment operator
	ShaderColor& operator=(ShaderColor&&) & = default;       // Move assignment operator
	~ShaderColor();		  							         // Destructor

	ShaderColor();

	virtual void SetToContext(ID3D11DeviceContext* devcon) override;

	void SendCamMatrices(const Matrix& view, const Matrix& proj);
	void SendWorldColor(const Matrix& world, const Vect& col);

	//void AddDrawCommand(Camera* pCam, Model* pMod, const Matrix& mat, Vect* meshColArray);
	void AddDrawCommand(Camera * pCam, ShaderColor_DrawCmd * pCmd);
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

#endif _ShaderColor
