#ifndef ShaderSprite_H
#define ShaderSprite_H

#include "ShaderBase.h"
#include "Matrix.h"

class Texture;
class ShaderSprite_DrawCmd;

class ShaderSprite : public ShaderBase
{
public:
	ShaderSprite(const ShaderSprite&) = delete;				 // Copy constructor
	ShaderSprite(ShaderSprite&&) = default;                    // Move constructor
	ShaderSprite& operator=(const ShaderSprite&) & = default;  // Copy assignment operator
	ShaderSprite& operator=(ShaderSprite&&) & = default;       // Move assignment operator
	~ShaderSprite();		  							         // Destructor


	ShaderSprite();

	virtual void SetToContext(ID3D11DeviceContext* devcon) override;

	void SetTextureResourceAndSampler(Texture* tex);
	void SendCamMatrices(const Matrix& view, const Matrix& proj);
	void SendWorld(const Matrix& world, const Matrix & uv_mat);

	//void AddDrawCommand(Camera* pCam, Model* pMod, const Matrix& mat_world, const Matrix& mat_uv, Texture* tex);
	void AddDrawCommand(Camera * pCam, ShaderSprite_DrawCmd * pCmd);
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
		Matrix UV;
	};
};

#endif // !ShaderSprite_H