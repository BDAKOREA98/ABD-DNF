#include "framework.h"
#include "MP.h"

MP::MP()
{
	_mainTransform = make_shared<Transform>();


	_quadTransform = make_shared<Transform>();
	_quad = make_shared<Quad>(L"Resource/DNF/interface/solid.png", Vector2(200, 200));
	_quad->SetPS(ADD_PS(L"Shader/MpBarPS.hlsl"));

	_quadTransform2 = make_shared<Transform>();
	_quad2 = make_shared<Quad>(L"Resource/DNF/interface/bottom.png", Vector2(200, 100));

	_quadTransform->SetParent(_mainTransform);
	_quadTransform2->SetParent(_mainTransform);

	_quadTransform->SetPosition({ +150.0f, +160.0f });
	_quadTransform2->SetPosition({ +150.0f, 100.0f });

	_mainTransform->SetPosition({ +180.0f, -186.0f });
	_quad3 = make_shared<Quad>(L"Resource/DNF/interface/solid.png", Vector2(200, 200));
	_quadTransform3 = make_shared<Transform>();
	_quadTransform3->SetParent(_quadTransform);

	_buffer = make_shared<BarBuffer>();

}

MP::~MP()
{
}

void MP::Update()
{

	_quadTransform2->Update();
	_quad2->Update();

	_mainTransform->Update();


	_quadTransform3->Update();
	_quad3->Update();
	_quadTransform->Update();
	_quad->Update();


	SetRatio(_ratio);

}

void MP::PostRender()
{
	_mainTransform->SetWorldBuffer(0);




	_buffer->SetPS_Buffer(0);
	_quadTransform2->SetWorldBuffer(1);
	_quad2->Render();


	_quadTransform3->SetWorldBuffer(1);
	_quad3->Render();
	_quadTransform->SetWorldBuffer(1);
	_quad->Render();



}
