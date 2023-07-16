#include "framework.h"
#include "DNF.h"

DNF::DNF()
{
	
	_map1 = make_shared<Map>();
	_player = make_shared<Player>();

}

DNF::~DNF()
{
}

void DNF::Update()
{

	_map1->Update();
	_player->Update();
}

void DNF::Render()
{
	_map1->Render();
	_player->Render();
}

void DNF::PostRender()
{
	_player->PostRender();
}
