#pragma once

struct Vertex
{
    XMFLOAT3 pos = { 0.0f,0.0f,0.0f };
};

struct Vertex_Texture
{
    XMFLOAT3 pos = { 0.0f,0.0f,0.0f };
    XMFLOAT4 color = { 0.0f, 0.0f, 0.0f,0.0f };
    XMFLOAT2 uv = { 0.0f, 0.0f };
};