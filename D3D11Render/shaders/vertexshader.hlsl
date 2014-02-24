cbuffer cbPerObject : register( b0 )
{
	matrix		g_mWorldViewProjection	: packoffset( c0 );
	matrix		g_mWorld				: packoffset( c4 );
};

struct VS_INPUT
{
	float4 vPosition : POSITION;
};

struct VS_OUTPUT
{
	float3 vNormal : NORMAL;
};

VS_OUTPUT VSMain( VS_INPUT Input )
{
	VS_OUTPUT Output;
	Output.vNormal=Input.vPosition.xyz;
	return Output;
}
