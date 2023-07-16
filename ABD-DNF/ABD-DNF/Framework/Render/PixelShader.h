#pragma once
class PixelShader : public Shader
{
public:
	PixelShader(wstring path);
	~PixelShader();

	void CreateBlob(wstring path);
	void CreatePixelShader();

	virtual void Set() override;

private:
	ComPtr<ID3D11PixelShader> _ps;
};

