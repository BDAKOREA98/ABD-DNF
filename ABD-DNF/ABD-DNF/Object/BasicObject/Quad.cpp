#include "framework.h"
#include "Quad.h"

Quad::Quad(wstring path)
{
    _srv = ADD_SRV(path);
    _size = _srv.lock()->GetImageSize();

    CreateVertices();
    CreateData(path);
}

Quad::Quad(wstring path, Vector2 size)
    : _size(size)
{
    _srv = ADD_SRV(path);

    CreateVertices();
    CreateData(path);

}

Quad::~Quad()
{
}

void Quad::Update()
{
}

void Quad::Render()
{
    _vertexBuffer->SetIA_VertexBuffer();
    _indexBuffer->SetIA_IndexBuffer();
    _vs.lock()->SetIA_InputLayOut();
    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    _srv.lock()->SetSRV(0);
    SAMPLER->SetSampler();

    _vs.lock()->Set();
    _ps.lock()->Set();

    DC->DrawIndexed(_indices.size(), 0, 0);
}

void Quad::CreateVertices()
{
    Vertex_Texture v;

    Vector2 halfSize = _size * 0.5f;

    v.pos = { -halfSize.x, halfSize.y, 0.0f }; // 왼쪽 위
    v.color = { 1.0f, 0.0f, 0.0f, 1.0f };
    v.uv = { 0.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { halfSize.x, halfSize.y, 0.0f }; // 오른쪽 위
    v.color = { 0.0f, 1.0f, 0.0f, 1.0f };
    v.uv = { 1.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { halfSize.x, -halfSize.y, 0.0f }; // 오른쪽 아래
    v.color = { 0.0f, 0.0f, 1.0f, 1.0f };
    v.uv = { 1.0, 1.0f };
    _vertices.push_back(v);

    v.pos = { -halfSize.x, -halfSize.y, 0.0f }; // 왼쪽 아래
    v.color = { 0.0f, 0.0f, 0.0f, 1.0f };
    v.uv = { 0.0f, 1.0f };
    _vertices.push_back(v);

    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);

    _indices.push_back(0);
    _indices.push_back(2);
    _indices.push_back(3);
}

void Quad::CreateData(wstring path)
{
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Texture), _vertices.size());
    _indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());
    _vs = ADD_VS(L"Shader/TextureVS.hlsl");
    _ps = ADD_PS(L"Shader/TexturePS.hlsl");
}
