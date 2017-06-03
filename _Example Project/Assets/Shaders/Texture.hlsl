#pragma pack_matrix( row_major )

Texture2D mainTexture : register(t0);

SamplerState aSampler : register(s0);

cbuffer CamData : register(b0)
{
	float4x4 View;			
	float4x4 Projection;
}

cbuffer InstanceData : register(b1)
{
	float4x4 World;
	// Texture might change too, but that's done through mainTexture
};

//--------------------------------------------------------------------------------------

struct VS_INPUT
{
	float4 Pos : POSITION;
	float2 Tex : TEXCOORD;	// u v maps
};

struct VS_OUTPUT
{
	float4 Pos : SV_POSITION;
	float2 Tex : TEXCOORD;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT VS( VS_INPUT input)
{
	VS_OUTPUT output;
	output.Pos = mul(input.Pos, World);
	output.Pos = mul(output.Pos, View);
	output.Pos = mul(output.Pos, Projection);
	output.Tex = input.Tex;
	return output;
}


//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(VS_OUTPUT input) : SV_Target
{
	/**
	float TexColor = mainTexture.Sample(aSampler, input.Tex);
	//*========================================================
	// Fog Demo

	//==== These three should be passed-in using cbuffers ====
	float FogStart = 25;	// anything closer than this value will have no fog
	float FogRange = 25;	// fog contribution increases linearly until full fog at dist = FogStart + Range

	//float4 FogColor = float4(.2,.2,.2, 1); // grey
	float4 FogColor = float4(0.098039225f, 0.098039225f, 0.439215720f, 1.000000000f); // MidnightBlue
	//========================================================

	// Compute fog density as function of distance to eye
	float distToEye = length(msEyePos - input.PosMS);
	float foglerp = saturate((distToEye - FogStart) / FogRange);	// See https://msdn.microsoft.com/en-us/library/windows/desktop/bb509645(v=vs.85).aspx
	
	// blend litcolor with fog level
	TexColor = lerp(TexColor, FogColor, foglerp);	// See https://msdn.microsoft.com/en-us/library/windows/desktop/bb509618(v=vs.85).aspx
	///========================================================*/

	return mainTexture.Sample(aSampler, input.Tex);
}