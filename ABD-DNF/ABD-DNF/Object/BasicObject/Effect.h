#pragma once
class Effect
{
public:
	Effect(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed = 0.1f, Action::Type type = Action::Type::END);
	Effect(string name, wstring file, wstring xmlPath, Vector2 size, float speed = 0.1f, Action::Type type = Action::Type::END);
	~Effect();

	void Update();
	void Render();

	void Play(Vector2 pos);
	void End();

	bool _isActive = false;
private:
	void CreateAction_ByFrame(string name, wstring file, Vector2 maxFrame, Vector2 size, float speed = 0.1f, Action::Type type = Action::Type::END);
	void CreateAction_ByXML(string name, wstring file, wstring xmlPath, Vector2 size, float speed = 0.1f, Action::Type type = Action::Type::END);

	string _name;

	shared_ptr<Transform> _transform;
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;
};

