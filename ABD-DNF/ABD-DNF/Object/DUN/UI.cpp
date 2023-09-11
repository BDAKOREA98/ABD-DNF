#include "framework.h"
#include "UI.h"


UI::UI()
{
	hp = make_shared<HP>();
	

}

UI::~UI()
{
}

void UI::Update()
{
	

	hp->Update();
	
}

void UI::PostRender()
{

	hp->PostRender();

}

void UI::Debug()
{
	

}

