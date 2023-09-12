#include "framework.h"
#include "Loading.h"

Loading::Loading()
{
	_maptrans = make_shared<Transform>();
	_mapquad = make_shared<Quad>(L"Resource/DNF/Inventory/chaewon.png");
	_maptrans->SetPosition(PLAYER->GetCol()->GetTransform()->GetWorldPos());
	
}

Loading::~Loading()
{
	

}

void Loading::Update()
{
	_maptrans->SetPosition({ PLAYER->GetCol()->GetTransform()->GetPos().x - 700.0f, PLAYER->GetCol()->GetTransform()->GetPos().y });
	_mapquad->Update();
	_maptrans->Update();

	if (KEY_DOWN(VK_LBUTTON))
	{
		SCENE->NextScene();
	}
}

void Loading::Render()
{
	_maptrans->SetWorldBuffer(0);
	_mapquad->Render();
}
