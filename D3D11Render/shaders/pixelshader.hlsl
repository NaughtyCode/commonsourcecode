struct PS_INPUT
{
	float3 vNormal		: NORMAL;
};

float4 PSMain( PS_INPUT Input ) : SV_TARGET
{
	float4 color = float4(0.35,0.35,0.6,1.0);
	return color;
}
