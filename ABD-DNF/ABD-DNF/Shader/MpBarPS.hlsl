Texture2D resource : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
    float4 pos : SV_POSITION;
    float4 color : COLOR;
    float2 uv : UV;
};

cbuffer BarBuffer : register(b0)
{
    float ratio;
    int padding[3];
};

float4 PS(PixelInput input) : SV_TARGET
{
    float2 resultUV;
    resultUV.x = input.uv.x;
    resultUV.y = input.uv.y;

    
    
    if (resultUV.y < ratio)
        return float4(0, 0, 0, 0);

    
    
    float4 color = resource.Sample(samp, resultUV);

    color.z = 1;
    
    
    
    return color;
}