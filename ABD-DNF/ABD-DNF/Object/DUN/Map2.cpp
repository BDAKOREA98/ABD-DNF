#include "framework.h"
#include "Map2.h"

Map2::Map2()
{
	_mapquad = _mapquad = make_shared<Quad>(L"Resource/DNF/Map/BattleMap.png");

	
	_maptrans = make_shared<Transform>();

	_maptrans->SetPosition(CENTER);
	_maptrans->SetScale({ 1.0f, 1.2f });
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
	_blockcol2->GetTransform()->SetPosition(Vector2(0.0f, +100.0f));
	_blockcol3->GetTransform()->SetPosition(Vector2(_maptrans->GetWorldPos().x * 3 - 134.0f, 0.0f));
	_blockcol4->GetTransform()->SetPosition(Vector2(-_maptrans->GetWorldPos().x * 3 + 134.0f, 0.0f));







	_blockcol1->SetColorRed();
	_blockcol2->SetColorRed();
	_blockcol3->SetColorRed();
	_blockcol4->SetColorRed();

}

Map2::~Map2()
{
}

void Map2::Update()
{
	_mapquad->Update();
	_maptrans->Update();
	_mapcol->Update();

	/*if (_mapcol->IsCollision(_blockcol1))
	{
		_blockcol1->SetColorRed();
	}
	if (_mapcol->IsCollision(_blockcol2))
	{
		_blockcol2->SetColorRed();
	}
	if (_mapcol->IsCollision(_blockcol3))
	{
		_blockcol3->SetColorRed();
	}
	if (_mapcol->IsCollision(_blockcol4))
	{
		_blockcol4->SetColorRed();
	}*/



	_blockcol1->Update();
	_blockcol2->Update();
	_blockcol3->Update();
	_blockcol4->Update();
}

void Map2::Render()
{
	_maptrans->SetWorldBuffer(0);
	_mapquad->Render();


	_blockcol1->Render();
	_blockcol2->Render();
	_blockcol3->Render();
	_blockcol4->Render();

	//_mapcol->Render();
}

void Map2::PostRender()
{

	ImGui::Text("Map1");
	ImGui::Text("POS.X : %1f", _maptrans->GetPos().x);
	ImGui::Text("POS>Y : %1f", _maptrans->GetPos().y);
	ImGui::Text("WORLDPOS.X : %1f", _maptrans->GetWorldPos().x);
	ImGui::Text("WORLDPOS.Y : %1f", _maptrans->GetWorldPos().y);


}

Vector2 Map2::leftBottom()
{

	Vector2 quadHalfSize = _mapquad->GetSize() * 0.5f;

	float x = _maptrans->GetWorldPos().x - quadHalfSize.x - 500;
	float y = -1000;

	return Vector2(x, y);
}

Vector2 Map2::rightTop()
{
	Vector2 quadHalfSize = _mapquad->GetSize() * 0.5f;

	float x = _maptrans->GetWorldPos().x + quadHalfSize.x + 500;
	float y = 1000;

	return Vector2(x, y);
}