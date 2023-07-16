#pragma once
class VertexBuffer
{
public:
	VertexBuffer(void* data, UINT stride, UINT count, UINT offset = 0);
	~VertexBuffer();

	void SetIA_VertexBuffer(UINT slot = 0);

private:
	void CreateVertexBuffer();

	ComPtr<ID3D11Buffer> vertexBuffer;

	void* _data = nullptr;
	UINT _stride = 0;
	UINT _count = 0;
	UINT _offset = 0;
};

