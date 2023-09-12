
#pragma once


class UI
{
public:
	UI();
	~UI();

	void Update();
	void PostRender();

	void SetEvent(CallBack fn) { _event = fn; }
	
	void Debug();

	shared_ptr<HP> hp;
	shared_ptr<MP> mp;
private:
	
	

	
	

	CallBack _event;

	
};

