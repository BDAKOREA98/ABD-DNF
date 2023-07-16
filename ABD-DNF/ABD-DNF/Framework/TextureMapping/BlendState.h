#pragma once
class BlendState
{
public:
	BlendState();
	~BlendState();

	void SetState();

	void Alpha();
	void Additive();

	void Change();

private:
	ComPtr<ID3D11BlendState> _blendState;
	D3D11_BLEND_DESC _desc = {};
};

