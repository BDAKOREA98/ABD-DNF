#pragma once
class DNF_2 : public Scene
{
public:
	DNF_2();
	~DNF_2();

	virtual void Update() override;
	virtual void Render() override;

private:

	shared_ptr<Map2> _map;
};

