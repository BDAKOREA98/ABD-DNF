#include "framework.h"
#include "DNF_2.h"

DNF_2::DNF_2()
{
	_map = make_shared<Map2>();
}

DNF_2::~DNF_2()
{
}

void DNF_2::Update()
{
	_map->Update();
}

void DNF_2::Render()
{
	_map->Render();
}
