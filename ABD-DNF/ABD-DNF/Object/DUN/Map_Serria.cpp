#include "framework.h"
#include "Map_Serria.h"

Map_Serria::Map_Serria()
{
	{_mapquad = make_shared<Quad>(L"Resource/DNF/Map/Serriaroom.jpg");
	
	_maptrans = make_shared<Transform>();

	_maptrans->SetPosition(CENTER);
	_maptrans->SetScale({ 1.2f, 1.2f });

	_mapcol = make_shared<RectCollider>(Vector2(_mapquad->GetImageSize().x, _mapquad->GetImageSize().y / 2));
	_mapcol->GetTransform()->SetParent(_maptrans);
	_mapcol->GetTransform()->AddVector2(Vector2(0.0f, -_mapquad->GetImageSize().y / 4));


	_blockcol1 = make_shared<RectCollider>(Vector2(_mapquad->GetImageSize().x, 100.0f));
	_blockcol2 = make_shared<RectCollider>(Vector2(_mapquad->GetImageSize().x, 100.0f));
	_blockcol3 = make_shared<RectCollider>(Vector2(100.0f, _mapquad->GetImageSize().y));
	_blockcol4 = make_shared<RectCollider>(Vector2(100.0f, _mapquad->GetImageSize().y));

	_blockcol1->GetTransform()->SetParent(_maptrans);
	_blockcol2->GetTransform()->SetParent(_maptrans);
	_blockcol3->GetTransform()->SetParent(_maptrans);
	_blockcol4->GetTransform()->SetParent(_maptrans);


	_blockcol1->GetTransform()->SetPosition(Vector2(0.0f, -_maptrans->GetWorldPos().y - 30.0f));
	_blockcol2->GetTransform()->SetPosition(Vector2(0.0f, +50.0f));
	_blockcol3->GetTransform()->SetPosition(Vector2(_maptrans->GetWorldPos().x, 0.0f));
	_blockcol4->GetTransform()->SetPosition(Vector2(-_maptrans->GetWorldPos().x, 0.0f));



	_NPC = make_shared<RectCollider>(Vector2( 100.0f, 200.0f ));
	_NPC->GetTransform()->SetParent(_maptrans);


	_blockcol1->SetColorRed();
	_blockcol2->SetColorRed();
	_blockcol3->SetColorRed();
	_blockcol4->SetColorRed();
	}

	_maptrans->AddVector2(Vector2(0.0f, 300.0f));
	
}

Map_Serria::~Map_Serria()
{
}

void Map_Serria::Update()
{
	_mapquad->Update();
	_maptrans->Update();
	_mapcol->Update();
	_NPC->Update();



	

	_blockcol1->Update();
	_blockcol2->Update();
	_blockcol3->Update();
	_blockcol4->Update();
}

void Map_Serria::Render()
{
	_maptrans->SetWorldBuffer(0);
	_mapquad->Render();
	_NPC->Render();

	

	_blockcol1->Render();
	_blockcol2->Render();
	_blockcol3->Render();
	_blockcol4->Render();

}

void Map_Serria::PostRender()
{

	ImGui::Text("Map1");
	ImGui::Text("POS.X : %1f", _maptrans->GetPos().x);
	ImGui::Text("POS>Y : %1f", _maptrans->GetPos().y);
	ImGui::Text("WORLDPOS.X : %1f", _maptrans->GetWorldPos().x);
	ImGui::Text("WORLDPOS.Y : %1f", _maptrans->GetWorldPos().y);


}

Vector2 Map_Serria::leftBottom()
{

	Vector2 quadHalfSize = _mapquad->GetImageSize() * 0.5f;

	float x = _maptrans->GetWorldPos().x - quadHalfSize.x;
	float y = quadHalfSize.y;

	return Vector2(x, y);
}

Vector2 Map_Serria::rightTop()
{
	Vector2 quadHalfSize = _mapquad->GetImageSize() * 0.5f;

	float x = _maptrans->GetWorldPos().x + quadHalfSize.x;
	float y = _maptrans->GetWorldPos().y + quadHalfSize.y;

	return Vector2(x, y);
}
