// ShaderColorVary
// Andre Berthiaume, july 2016

#ifndef _ShaderColorVary
#define _ShaderColorVary

#include "ShaderBase.h"
#include "Matrix.h"

class ShaderColorVary : public ShaderBase
{
public:
	ShaderColorVary(const ShaderColorVary&) = delete;				 // Copy constructor
	ShaderColorVary(ShaderColorVary&&) = default;                    // Move constructor
	ShaderColorVary& operator=(const ShaderColorVary&) & = default;  // Copy assignment operator
	ShaderColorVary& operator=(ShaderColorVary&&) & = default;       // Move assignment operator
	~ShaderColorVary();		  							         // Destructor

	ShaderColorVary();

	virtual void SetToContext(ID3D11DeviceContext* devcon) override;

	void SendCamMatrices(const Matrix& view, const Matrix& proj);
	void SendWorldColor(const Matrix& world);

	void AddDrawCommand(Camera* pCam, Model* pMod, const Matrix& mat);
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

#endif _ShaderColorVary
