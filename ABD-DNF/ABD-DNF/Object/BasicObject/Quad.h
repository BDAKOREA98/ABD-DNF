#pragma once
class Quad
{
protected:
	Quad() {}

public:
	Quad(wstring path);
	Quad(wstring path, Vector2 size);
	virtual ~Quad();

	virtual void Update();
	virtual void Render();

	virtual void CreateVertices();
	virtual void CreateData(wstring path);

	Vector2 GetImageSize() { return _srv.lock()->GetImageSize(); }
	Vector2 GetSize() { return _size; }

	void SetPS(shared_ptr<PixelShader> ps) { _ps = ps; }
	void SetVS(shared_ptr<VertexShader> vs) { _vs = vs; }

protected:
	vector<Vertex_Texture> _vertices;
	vector<UINT> _indices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;

	weak_ptr<VertexShader> _vs;
	weak_ptr<PixelShader> _ps;

	weak_ptr<SRV> _srv;

	Vector2 _size;
};

