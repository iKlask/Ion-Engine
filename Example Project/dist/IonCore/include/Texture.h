// Texture
// Andre Berthiaume, July, 2016

#ifndef _Texture
#define _Texture

#include <Windows.h>
#include <string>
#include <d3d11.h>
#include "DirectXTex.h"

class Texture
{
public:
	Texture(const Texture&) = delete;				 // Copy constructor
	Texture(Texture&&) = delete;                    // Move constructor
	Texture& operator=(const Texture&) & = delete;  // Copy assignment operator
	Texture& operator=(Texture&&) & = delete;       // Move assignment operator
	~Texture();									     // Destructor
	Texture() = delete;

	//	Bi:		D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT
	//	Tri:	D3D11_FILTER_MIN_MAG_MIP_LINEAR
	//	Ani:	D3D11_FILTER_ANISOTROPIC

	//Texture(LPCWSTR filepath, D3D11_FILTER filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR, UINT isotropic_level = 4, bool ComputeMip = false, size_t miplevel = 0, DirectX::TEX_FILTER_FLAGS filterflags = DirectX::TEX_FILTER_LINEAR );
	Texture(const char* filepath, D3D11_FILTER filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR, UINT isotropic_level = 4, bool ComputeMip = false, size_t miplevel = 0, DirectX::TEX_FILTER_FLAGS filterflags = DirectX::TEX_FILTER_LINEAR);

	void SetToContext(ID3D11DeviceContext* devcon, int texResSlot = 0, int sampSlot = 0);
	const DirectX::Image* GetImage();
	float getWidth();
	float getHeight();
	

private:
	ID3D11ShaderResourceView* mpTextureRV;
	ID3D11SamplerState* mpSampler;
	DirectX::ScratchImage scrtTex;
	float width;
	float height;
};

#endif _Texture