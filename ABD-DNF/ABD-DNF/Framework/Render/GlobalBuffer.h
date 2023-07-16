#pragma once

class MatrixBuffer : public ConstantBuffer
{
public:

	struct Data
	{
		XMMATRIX matrix;
	};

	MatrixBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
		_data.matrix = XMMatrixIdentity();
	}

	virtual ~MatrixBuffer() {}

	void SetData(XMMATRIX matrix)
	{
		matrix = XMMatrixTranspose(matrix);
		_data.matrix = matrix;
	}

	Data _data;
};

class ColorBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT4 color;
	};

	ColorBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
		_data.color = XMFLOAT4();
	}

	virtual ~ColorBuffer() {}

	void SetColor(XMFLOAT4 color)
	{
		_data.color = color;
	}

	Data _data;
};

class FrameBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT2 maxFrame = XMFLOAT2();
		XMFLOAT2 curFrame = XMFLOAT2();
	};

	FrameBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
	}

	virtual ~FrameBuffer() {}

	Data _data;
};

class ActionBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		Vector2 startPos;
		Vector2 size;
		Vector2 imageSize;
		int padding[2];
	};

	ActionBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
	}

	virtual ~ActionBuffer() {}

	Data _data;
};

class IntBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		int value1 = 0;
		int value2 = 0;
		int value3 = 0;
		int value4 = 0;
	};

	IntBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
	}

	virtual ~IntBuffer() {}

	Data _data;
};

class FilterBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		int selected = 0;
		int value1 = 0;
		int value2 = 0;
		int value3 = 0;

		Vector2 imageSize;
		Vector2 radialCenter;
	};

	FilterBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
	}

	virtual ~FilterBuffer() {}

	Data _data;
};

class ButtonBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		int state = 0;
		float hover = 0.0f;
		float click = 0.0f;
		int padding = 0;
	};

	ButtonBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
	}

	virtual ~ButtonBuffer() {}

	Data _data;
};

class BarBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		float ratio = 0.0f;
		int padding[3];
	};

	BarBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{
	}

	virtual ~BarBuffer() {}

	Data _data;
};

