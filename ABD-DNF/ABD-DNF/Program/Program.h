#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render();
	void ChangeScene();

private:
	shared_ptr<Scene> _curScene;
};

