#pragma once
class ConstantBuffer
{
public:
	ConstantBuffer(void* data, UINT dataSize);
	virtual ~ConstantBuffer();

	void Update_Resource();

	void SetVS_Buffer(UINT slot);
	void SetPS_Buffer(UINT slot);

private:
	ComPtr<ID3D11Buffer> _constantBuffer;

	void* _data;
	UINT _dataSize;
};

