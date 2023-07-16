#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring path)
    : Quad()
{
    _srv = ADD_SRV(path);
    _size = _srv.lock()->GetImageSize();

    _actionBuffer = make_shared<ActionBuffer>();
    _actionBuffer->_data.imageSize = _srv.lock()->GetImageSize();
}

Sprite::Sprite(wstring path, Vector2 size)
    : Quad()
{
    _srv = ADD_SRV(path);
    _size = size;

    _actionBuffer = make_shared<ActionBuffer>();
    _actionBuffer->_data.imageSize = _srv.lock()->GetImageSize();
}

Sprite::~Sprite()
{
}

void Sprite::Update()
{
    _reverseBuffer->Update_Resource();
    _actionBuffer->Update_Resource();
    Quad::Update();
}

void Sprite::Render()
{
    _reverseBuffer->SetPS_Buffer(0);
    _actionBuffer->SetPS_Buffer(1);
    Quad::Render();
}

void Sprite::CreateVertices()
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

void Sprite::CreateData(wstring path)
{
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Texture), _vertices.size());
    _indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());
    _vs = ADD_VS(L"Shader/TextureVS.hlsl");
    _ps = ADD_PS(L"Shader/ActionPS.hlsl");

    _reverseBuffer = make_shared<IntBuffer>();
}
