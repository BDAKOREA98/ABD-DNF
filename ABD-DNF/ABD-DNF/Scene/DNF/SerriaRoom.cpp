#include "framework.h"
#include "SerriaRoom.h"

SerriaRoom::SerriaRoom()
{
	map = make_shared<Map_Serria>();




	trans = make_shared<Transform>();

	serria = make_shared<Quad>(L"Resource/DNF/interface/Serria2.jpg");
	serria->SetPS(ADD_PS(L"Shader/Serria.hlsl"));
	trans2 = make_shared<Transform>();
	trans2->SetParent(trans);


	trans->SetPosition({ -1000.0f, -800.0f	});

	playerQuad = make_shared<Quad>(L"Resource/DNF/interface/Player.png");
	playerQuad->SetPS(ADD_PS(L"Shader/playerText.hlsl"));
	playertrans = make_shared<Transform>();
	playertrans->SetParent(trans);
	
	playertrans->AddVector2({ 0.0f, -100.0f });
	

	Textbar = make_shared<Quad>(L"Resource/DNF/interface/TextBar.png");
	Textbar->SetPS(ADD_PS(L"Shader/TEXT.hlsl"));
	texttrans = make_shared<Transform>();
	texttrans->SetParent(trans);
	texttrans->SetPosition({ +500.0f, 0.0f });


}

SerriaRoom::~SerriaRoom()
{
}

void SerriaRoom::Update()
{
	

	CAMERA->SetTarget(PLAYER->GetCol()->GetTransform());
	CAMERA->SetLeftBottom(map->leftBottom());
	CAMERA->SetRightTop(map->rightTop());
	serria	 ->Update();
		trans->Update();
		trans2->Update();

	map->Update();

	Textbar->Update();
	texttrans->Update();
	playerQuad->Update();
	playertrans->Update();

	MapCollision();
	PLAYER->Update();
}

void SerriaRoom::Render()
{
	trans->SetWorldBuffer(0);
	map->Render();
	PLAYER->Render();
	
	Text();


	
}

void SerriaRoom::PostRender()
{
	ImGui::Text("Count : %d", count);
}

void SerriaRoom::Text()
{

	if (count >= 7)
	{
		PLAYER->Text = true;
	}

	if (PLAYER->GetCol()->IsCollision(map->GetNPC()) && KEY_DOWN(VK_LBUTTON) )
	{
		
			PLAYER->Text = false;
			count++;
	}
	
	if (count == 1)
	{
		
		texttrans->SetWorldBuffer(1);
		Textbar->Render();
		trans2->SetWorldBuffer(1);
		serria->Render();
		FONT->RenderText(L"세리아", "WHITE", Vector2(550.0f, 470.0f));
		FONT->RenderText(L"안녕하세요 모험가님", "BLACK", Vector2(550.0f, 550.0f));
		FONT->RenderText(L"마우스를 누르세요", "RED", Vector2(950.0f, 600.0f));


	}
	else if (count == 2)
	{
		texttrans->SetWorldBuffer(1);
		Textbar->Render();
		playertrans->SetWorldBuffer(1);
		playerQuad->Render();
		FONT->RenderText(L"Player", "WHITE", Vector2(550.0f, 470.0f));
		FONT->RenderText(L"?????", "BLACK", Vector2(550.0f, 550.0f));

	}
	else if (count == 3)
	{
		texttrans->SetWorldBuffer(1);
		Textbar->Render();
		trans2->SetWorldBuffer(1);
		serria->Render();
		FONT->RenderText(L"세리아", "WHITE", Vector2(550.0f, 470.0f));
		FONT->RenderText(L"   안내를 맡은 세리아라고 합니다.", "BLACK", Vector2(550.0f, 550.0f));
		FONT->RenderText(L"마우스를 누르세요", "RED", Vector2(950.0f, 600.0f));

	}
	else if (count == 4)
	{
		texttrans->SetWorldBuffer(1);
		Textbar->Render();
		playertrans->SetWorldBuffer(1);
		playerQuad->Render();
		FONT->RenderText(L"Player", "WHITE", Vector2(550.0f, 470.0f));
		FONT->RenderText(L"무슨 안내??", "BLACK", Vector2(550.0f, 550.0f));

	}
	else if (count == 5)
	{
		texttrans->SetWorldBuffer(1);
		Textbar->Render();
		trans2->SetWorldBuffer(1);
		serria->Render();
		FONT->RenderText(L"세리아", "WHITE", Vector2(550.0f, 470.0f));
		FONT->RenderText(L"   간단한 조작키를 안내 해드리려고 합니다.", "BLACK", Vector2(550.0f, 550.0f));
		FONT->RenderText(L"마우스를 누르세요", "RED", Vector2(950.0f, 600.0f));

	}
	else if (count == 6)
	{
		texttrans->SetWorldBuffer(1);
		Textbar->Render();
		playertrans->SetWorldBuffer(1);
		playerQuad->Render();
		FONT->RenderText(L"Player", "WHITE", Vector2(550.0f, 470.0f));
		FONT->RenderText(L"........", "BLACK", Vector2(550.0f, 550.0f));

	}
	else if (count == 7)
	{
		texttrans->SetWorldBuffer(1);
		Textbar->Render();
		trans2->SetWorldBuffer(1);
		serria->Render();
		FONT->RenderText(L"세리아", "WHITE", Vector2(550.0f, 470.0f));
		FONT->RenderText(L"   \'방향키\' 를 이용하여 이동하실 수 있습니다.", "BLACK", Vector2(550.0f, 550.0f));
		FONT->RenderText(L"   한번 움직여 보시겠습니까??.", "BLACK", Vector2(550.0f, 570.0f));
		
		FONT->RenderText(L"마우스를 누르세요", "RED", Vector2(950.0f, 600.0f));

		
	}
	else if (count == 8 && KEY_DOWN(VK_LBUTTON))
	{
		texttrans->SetWorldBuffer(1);
		Textbar->Render();
		trans2->SetWorldBuffer(1);
		serria->Render();
		FONT->RenderText(L"세리아", "WHITE", Vector2(550.0f, 470.0f));
		FONT->RenderText(L"   \'X\' 를 이용하여하실 수 있습니다.", "BLACK", Vector2(550.0f, 550.0f));
		FONT->RenderText(L"   한번 움직여 보시겠습니까??.", "BLACK", Vector2(550.0f, 570.0f));

		FONT->RenderText(L"마우스를 누르세요", "RED", Vector2(950.0f, 600.0f));


	}


}

void SerriaRoom::MapCollision()
{
	if (map->GetBottom()->Block(PLAYER->GetCol()))
	{


		
		SCENE->NextScene();

	}
	if (map->GetLeft()->Block(PLAYER->GetCol()))
	{


	}
	if (map->GetRight()->Block(PLAYER->GetCol()))
	{
		
		

	}
	if (map->GetTop()->Block(PLAYER->GetCol()))
	{


	}


}
