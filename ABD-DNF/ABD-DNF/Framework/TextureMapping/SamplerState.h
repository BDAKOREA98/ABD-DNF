#pragma once
class SamplerState
{
public:
	SamplerState();
	~SamplerState();

	void SetSampler(UINT slot = 0);

private:
	ComPtr<ID3D11SamplerState> samplerState;
};

