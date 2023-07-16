#include "framework.h"
#include "PixelShader.h"

PixelShader::PixelShader(wstring path)
{
    CreateBlob(path);
    CreatePixelShader();
}

PixelShader::~PixelShader()
{
}

void PixelShader::CreateBlob(wstring path)
{
    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    D3DCompileFromFile(path.c_str(),
        nullptr, nullptr, "PS", "ps_5_0", flags, 0, _blob.GetAddressOf(), nullptr);
}

void PixelShader::CreatePixelShader()
{
    DEVICE->CreatePixelShader(_blob->GetBufferPointer(),
        _blob->GetBufferSize(), nullptr, IN _ps.GetAddressOf());
}

void PixelShader::Set()
{
    DC->PSSetShader(_ps.Get(), nullptr, 0);
}
