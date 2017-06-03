#ifndef SHADERTEXTURE_H
#define SHADERTEXTURE_H

#include "ShaderBase.h"
#include "Matrix.h"

class Texture;
class ShaderTexture_DrawCmd;

class ShaderTexture : public ShaderBase
{
public:
	ShaderTexture(const ShaderTexture&) = delete;				 // Copy constructor
	ShaderTexture(ShaderTexture&&) = default;                    // Move constructor
	ShaderTexture& operator=(const ShaderTexture&) & = default;  // Copy assignment operator
	ShaderTexture& operator=(ShaderTexture&&) & = default;       // Move assignment operator
	~ShaderTexture();		  							         // Destructor


	ShaderTexture();

	virtual void SetToContext(ID3D11DeviceContext* devcon) override;

	void SetTextureResourceAndSampler(Texture* tex);
	void SendCamMatrices(const Matrix& view, const Matrix& proj);
	void SendWorld(const Matrix& world);

	//void AddDrawCommand(Camera* pCam, Model* pMod, const Matrix& mat, Texture** texArray);
	void AddDrawCommand(Camera * pCam, ShaderTexture_DrawCmd * pCmd);
	virtual void RenderShader(ID3D11DeviceContext* devcon) override;

private:
	// add your own material 
	ID3D11Buffer*	mpcbViewProj;

	struct ViewProjData
	{
		Matrix mView;
		Matrix mProjection;
	};

	ID3D11Buffer*	mpcbWorld;

	struct WorldData
	{
		Matrix World;
		// The texture might change too, but that's done through mpTextureRV
	};
};

#endif // !SHADERTEXTURE_H