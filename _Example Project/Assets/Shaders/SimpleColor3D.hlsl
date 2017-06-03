//--------------------------------------------------------------------------------------
// Constant Buffer Variables
//--------------------------------------------------------------------------------------

#pragma pack_matrix( row_major )
/*
cbuffer WVPBuffer : register( b0 )
{
	float4x4 World;
	float4x4 View;
	float4x4 Projection;
}
//*/

cbuffer CamData : register(b0)
{
	float4x4 View;
	float4x4 Projection;
}

cbuffer InstanceData : register(b1)
{
	float4x4 World;
	float4 SelectedColor;
};

//--------------------------------------------------------------------------------------
struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
    float4 Color : COLOR;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT VS( float4 Pos : POSITION, float4 Color : COLOR )
{
    VS_OUTPUT output;
    output.Pos = mul( Pos, World);
    output.Pos = mul( output.Pos, View);
    output.Pos = mul( output.Pos, Projection);
    //output.Color = Color;
	output.Color = Pos * 2.0 + float4(0.5, 0.5, 0.5, 0.0);
    return output;
}


//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS( VS_OUTPUT input ) : SV_Target
{
    return input.Color;
}
