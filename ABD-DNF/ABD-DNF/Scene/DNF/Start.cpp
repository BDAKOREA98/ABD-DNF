#include "framework.h"
#include "Start.h"

Start::Start()
{
	quad = make_shared<Quad>(L"Resource/DNF/Map/Start2.jpg");
	trans = make_shared<Transform>();
	trans->SetScale({ 1.5f, 1.5f });

	rect = make_shared<RectCollider>(Vector2(300.0f,50.0f));
	rect->GetTransform()->AddVector2({ 0.0f, -100.0f });
	
	FONT->Add("WHITE", L"D2Coding", {1.0f,1.0f,1.0f});
	FONT->Add("RED", L"D2Coding", {1.0f,0.0f,0.0f});
	FONT->Add("BLACK", L"D2Coding", {0.0f,0.0f,0.0f});

	

}

Start::~Start()
{
}

void Start::Update()
{
	StartGame();

	quad->Update();
	trans->Update();
	rect->Update();
}

void Start::Render()
{
	trans->SetWorldBuffer(0);
	quad->Render();
	rect->Render();

	FONT->RenderText(L"GAME START", "RED", Vector2(450.0f,500.0f),Vector2(500.0f,100.0f));
	FONT->RenderText(L"space를 누르면 게임이 시작됩니다.", "WHITE", Vector2(450.0f,700.0f),Vector2(500.0f,100.0f));

}

void Start::PostRender()
{
}

void Start::StartGame()
{
	if (KEY_DOWN(VK_SPACE))
	{
		SCENE->NextScene();
	}
}
