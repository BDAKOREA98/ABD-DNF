#pragma once
class VertexShader : public Shader
{
public:
	VertexShader(wstring path);
	~VertexShader();

	void CreateBlob(wstring path);
	void CreateInputLayout();
	void CreateVertexShader();

	void SetIA_InputLayOut();
	virtual void Set() override;

private:
	ComPtr<ID3D11InputLayout> _inputLayOut;
	ComPtr<ID3D11VertexShader> _vs;
};

