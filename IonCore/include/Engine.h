#ifndef ENGINE_H
#define ENGINE_H

#include <d3d11.h>
#include "Align16.h"

#include "GameTimer.h"
#include "WindowRenderer.h"		//	So all engine children have access

class Engine : public Align16
{
public:
	Engine( const char* windowName, const int Width,const int Height);
	Engine() {};
	virtual ~Engine();
private:
	GameTimer mTimer;
	void CalculateFrameStats();

	virtual void Initialize() = 0;
	virtual void LoadContent() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void UnLoadContent() = 0;

	//Messages
	virtual void OnMouseDown(WPARAM btnState, int xval, int yval);
	virtual void OnMouseUp(WPARAM btnState, int xval, int yval);
	virtual void OnMouseMove(WPARAM btnState, int xval, int yval);
	virtual void OnMouseWheel(short delta);
protected:
	float GetTimeInSeconds() { return mTimer.TotalTime(); };
	void run();

	void setWidthHeight(const int width, const int height);
	void setWindowName(const char *pWindowName);
	int getHeight() { return WindowRenderer::GetHeight(); };
	int getWidth() { return WindowRenderer::GetWidth(); };

	void SetClearColor(float red, float green, float blue, float alpha);
	void SetClearColor(const Vect& col);

	void setVsync(bool enable);
	void setDXReport(bool enable);
};

#endif _Engine