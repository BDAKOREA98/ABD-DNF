#include "framework.h"
#include "MobHP.h"
MobHP::MobHP()
{
	_quadTransform = make_shared<Transform>();
	_quad = make_shared<Quad>(L"Resource/DNF/interface/Button.png", Vector2(150, 25));
	_quad->SetPS(ADD_PS(L"Shader/MonsterHP.hlsl"));

	_buffer = make_shared<BarBuffer>();
	_buffer->_data.ratio = 1.0f;
}

MobHP::~MobHP()
{
}

void MobHP::Update()
{
	_quadTransform->Update();

	_buffer->Update_Resource();
}

void MobHP::PostRender()
{
	_quadTransform->SetWorldBuffer(0);
	_buffer->SetPS_Buffer(0);
	_quad->Render();
}