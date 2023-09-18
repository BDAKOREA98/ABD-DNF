Texture2D resource : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
    float4 pos : SV_POSITION;
    float4 color : COLOR;
    float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
    float2 resultUV;
    
    
    resultUV.x = input.uv.x;
    resultUV.y = input.uv.y;

    
    
    float4 color = resource.Sample(samp, resultUV);
    
    
    if (color.x + color.y + color.z >= 2.95f)
    {
        color = float4(1, 1, 1, 0);
    }
    
    
    
    
    
    return color;
}