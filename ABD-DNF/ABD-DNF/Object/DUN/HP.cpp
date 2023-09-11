#include "framework.h"
#include "HP.h"

HP::HP()
{
	_mainTransform = make_shared<Transform>();


	_quadTransform = make_shared<Transform>();
	_quad = make_shared<Quad>(L"Resource/DNF/interface/solid.png", Vector2(200, 200));
	_quad->SetPS(ADD_PS(L"Shader/HpBarPS.hlsl"));
	
	_quadTransform2 = make_shared<Transform>();
	_quad2 = make_shared<Quad>(L"Resource/DNF/interface/bottom.png", Vector2(200, 100));

	_quadTransform->SetParent(_mainTransform);
	_quadTransform2->SetParent(_mainTransform);

	_quadTransform->SetPosition({ -150.0f, +160.0f });
	_quadTransform2->SetPosition({ -150.0f, 100.0f });

	_mainTransform->SetPosition({ -180.0f, -186.0f });
	
	_buffer = make_shared<BarBuffer>();
	
}

HP::~HP()
{
}

void HP::Update()
{

	_quadTransform2->Update();
	_quad2->Update();

	_mainTransform->Update();
	
	
	_quadTransform->Update();
	_quad->Update();


	SetRatio(_ratio);
	
}

void HP::PostRender()
{
	_mainTransform->SetWorldBuffer(0);
	

	
	
	_buffer->SetPS_Buffer(0);
	_quadTransform2->SetWorldBuffer(1);
	_quad2->Render();

	
	_quadTransform->SetWorldBuffer(1);
	_quad->Render();



}
