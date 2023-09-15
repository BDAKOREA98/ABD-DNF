#include "framework.h"
#include "Program.h"

#include "../Scene/DNF/DNF.h"
#include "../Scene/DNF/DNF_2.h"

Program::Program()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	FONT->GetInstance();


	FONT->Add("D2Coding", L"D2Coding");
	Timer::GetInstance()->LockFPS(60);
}

Program::~Program()
{
	FONT->Delete();
}

void Program::Update()
{
	Timer::GetInstance()->Update();
	InputManager::GetInstance()->Update();
	CAMERA->Update();
	//_curScene->Update();

	EFFECT->Update();
	SOUND->Update();
	SCENE->Update();

	

}

void Program::Render()
{
	Device::GetInstance()->Clear();

	CAMERA->SetViewBuffer();
	CAMERA->SetProjectionBuffer();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ALPHA->SetState();
	//ADDITIVE->SetState();
	//_curScene->Render();
	FONT->GetDC()->BeginDraw();
	SCENE->Render();
	EFFECT->Render();

	ImGui::Text("FPS : %d", FPS);
	ImGui::Text("DeltaTime : %1f", DELTA_TIME);
	ImGui::Text("RunTime : %1f", RUN_TIME);
	CAMERA->PostRender();
	SCENE->PostRender();
	CAMERA->SetUIViewBuffer();

	
	
	FONT->GetDC()->EndDraw();

	//_curScene->PostRender();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}

void Program::ChangeScene()
{
	SCENE->NextScene();
}
