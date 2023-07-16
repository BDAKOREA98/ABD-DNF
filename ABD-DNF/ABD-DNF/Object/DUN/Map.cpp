#include "framework.h"
#include "Map.h"

Map::Map()
{
	_mapquad = make_shared<Quad>(L"Resource/DNF/Map/1.png");
	_maptrans = make_shared<Transform>();

	_maptrans->SetPosition(CENTER);

	

}

Map::~Map()
{
}

void Map::Update()
{
	_mapquad->Update();
	_maptrans->Update();
}

void Map::Render()
{
	_maptrans->SetWorldBuffer(0);
	_mapquad->Render();

}

void Map::PostRender()
{
}
