#pragma once
class Start : public Scene
{
public:

	Start();
	~Start();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render() override;
	void PostRender();

	void StartGame();

private:

	shared_ptr<Quad> quad;
	shared_ptr<Transform> trans;

	shared_ptr<RectCollider> rect;



};

