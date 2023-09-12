#include "framework.h"
#include "UI.h"


UI::UI()
{
	hp = make_shared<HP>();
	mp = make_shared<MP>();

}

UI::~UI()
{
}

void UI::Update()
{
	

	hp->Update();
	mp->Update();
	
}

void UI::PostRender()
{

	hp->PostRender();
	mp->PostRender();

}

void UI::Debug()
{
	

}

