
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

private:
	
	shared_ptr<HP> hp;
	

	
	

	CallBack _event;

	
};

