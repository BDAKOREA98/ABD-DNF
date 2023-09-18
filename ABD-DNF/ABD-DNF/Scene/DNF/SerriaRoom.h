#pragma once
class SerriaRoom : public Scene
{
public:
	SerriaRoom();
	~SerriaRoom();
	
		
	void Update() override;
	void Render() override;
	void PostRender();
	void Text();
	void MapCollision();

private:

	int count = 0;

	shared_ptr<Map_Serria> map;

	shared_ptr<Quad> serria;
	shared_ptr<Transform> trans;
	shared_ptr<Transform> trans2;

	shared_ptr<Quad> Textbar;
	shared_ptr<Transform> texttrans;

	shared_ptr<Quad> playerQuad;
	shared_ptr<Transform> playertrans;




};

