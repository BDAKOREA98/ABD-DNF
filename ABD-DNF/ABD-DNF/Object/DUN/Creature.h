#pragma once
class Creature
{
public:
	Creature();
	virtual ~Creature();

	virtual void Update() abstract;

	virtual void Render() abstract;

	virtual void PostRender() abstract;





private:

	

};

