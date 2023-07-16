#pragma once
class Device
{
private:
	Device();
	~Device();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new Device();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static Device* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;
	}

	ComPtr<ID3D11Device> GetDevice() { return device; }
	ComPtr<ID3D11DeviceContext> GetDC() { return deviceContext; }

	void Clear();
	void Present();

private:
	void CreateDeviceAndSwapChain();
	void CreateDoubleBuffer();

	static Device* _instance;

	ComPtr<ID3D11Device> device;
	ComPtr<ID3D11DeviceContext> deviceContext;
	ComPtr<IDXGISwapChain> swapChain;
	ComPtr<ID3D11RenderTargetView> renderTargetView;
};

