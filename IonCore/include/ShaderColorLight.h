// ShaderColorLight
// Andre Berthiaume, Feb 2017

#ifndef _ShaderColorLight
#define _ShaderColorLight

#include "ShaderBase.h"
#include "Matrix.h"

struct LightData;
class ShaderColorLight_DrawCmd;

class ShaderColorLight : public ShaderBase
{

public:
	ShaderColorLight(const ShaderColorLight&) = delete;				 // Copy constructor
	ShaderColorLight(ShaderColorLight&&) = default;                    // Move constructor
	ShaderColorLight& operator=(const ShaderColorLight&) & = default;  // Copy assignment operator
	ShaderColorLight& operator=(ShaderColorLight&&) & = default;       // Move assignment operator
	~ShaderColorLight();		  							         // Destructor

	ShaderColorLight();

	virtual void SetToContext(ID3D11DeviceContext* devcon) override;

	void SetDirectionalLightParameters(const Vect& dir, const Vect& amb = Vect(1, 1, 1), const Vect& dif = Vect(1, 1, 1), const Vect& sp = Vect(1, 1, 1));
	void SetPointLightParameters(int light_num, const Vect& pos, float r, const Vect& att, const Vect& amb = Vect(1, 1, 1), const Vect& dif = Vect(1, 1, 1), const Vect& sp = Vect(1, 1, 1));
	void SetSpotLightParameters(int light_num, const Vect& pos, float r, const Vect& att, const Vect& dir, float spotExp, const Vect& amb = Vect(1, 1, 1), const Vect& dif = Vect(1, 1, 1), const Vect& sp = Vect(1, 1, 1));

	void SendCamMatrices(const Matrix& view, const Matrix& proj);
	void SetFogParamerters(const float& fog_start, const float& fog_range, const Vect& fog_color);
	void SendLightParameters(const Vect& eyepos);
	void SendWorldAndMaterial(const Matrix& world, const Vect& amb = Vect(.5f, .5f, .5f), const Vect& dif = Vect(.5f, .5f, .5f), const Vect& sp = Vect(.5f, .5f, .5f));

	//void AddDrawCommand(Camera* pCam, Model * pMod, const Matrix & mat, LightData * lightArray);
	void AddDrawCommand(Camera * pCam, ShaderColorLight_DrawCmd * pCmd);
	virtual void RenderShader(ID3D11DeviceContext* devcon) override;

private:
	struct Material
	{
		Vect Ambient;
		Vect Diffuse;
		Vect Specular;
	};

	struct PhongADS
	{
		Vect Ambient;
		Vect Diffuse;
		Vect Specular;
	};

	struct FogLight
	{
		Vect FogColor;
		float FogStart;
		float FogRange;
	};

	FogLight FogLightData;

	struct DirectionalLight
	{
		PhongADS Light;
		Vect Direction;
	};

	DirectionalLight DirLightData;

	struct PointLight
	{
		PhongADS Light;
		Vect Position;
		Vect Attenuation;
		float Range;
	};

	PointLight PointLightData[3];

	struct SpotLight
	{
		PhongADS Light;
		Vect Position;
		Vect Attenuation;
		Vect Direction;
		float SpotExp;
		float Range;
	};

	SpotLight SpotLightData[3];

	struct CamMatrices
	{
		Matrix View;
		Matrix Projection;
	};

	ID3D11Buffer*  mpBufferCamMatrices;

	struct Data_WorldAndMaterial
	{
		Matrix World;
		Matrix WorlInv;
		Material Mat;
	};

	ID3D11Buffer*	mpBuffWordAndMaterial;

	struct Data_LightParams
	{
		DirectionalLight DirLight;
		PointLight PntLight[3];
		SpotLight SptLight[3];
		FogLight FgLight;
		//Vect FogStart;
		//Vect FogRange;
		//Vect FogColor;
		Vect EyePosWorld;
	};

	ID3D11Buffer*  mpBufferLightParams;

};

#endif _ShaderColorLight

