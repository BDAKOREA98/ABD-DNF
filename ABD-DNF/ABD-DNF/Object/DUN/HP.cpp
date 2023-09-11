#include "framework.h"
#include "HP.h"

HP::HP()
{
	_quadTransform = make_shared<Transform>();
	_quad = make_shared<Quad>(L"Resource/DNF/interface/solid.png", Vector2(200, 200));
	_quad->SetPS(ADD_PS(L"Shader/HpBarPS.hlsl"));

	_buffer = make_shared<BarBuffer>();
	_buffer->_data.ratio = 1.0f;
}

HP::~HP()
{
}

void HP::Update()
{
	_quadTransform->Update();

	_buffer->Update_Resource();
}

void HP::PostRender()
{
	_quadTransform->SetWorldBuffer(0);
	_buffer->SetPS_Buffer(0);
	_quad->Render();
}
