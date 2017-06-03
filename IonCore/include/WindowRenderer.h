#ifndef WINDOWRENDERER_H
#define WINDOWRENDERER_H

#include <d3d11.h>
#include "Vect.h"

#include <string>

#include "Align16.h"

#define USE_BATCH_RENDER 1


class WindowRenderer : public Align16
{
	friend class Engine;
private:
	static WindowRenderer* ptrInstance;

	WindowRenderer() = default;									// Private constructor
	WindowRenderer(const WindowRenderer&) = delete;				// Prevent copy-construction
	WindowRenderer& operator=(const WindowRenderer&) = delete;	// Prevent assignment
	~WindowRenderer();

	static WindowRenderer& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new WindowRenderer;
		return *ptrInstance;
	};

	void privInitialize(const HINSTANCE& hInstance, int nCmdShow);

private:
	// Main window handle
	HWND      mhMainWnd = nullptr;
	HINSTANCE	g_hInst = nullptr;

	// DX application elements
	ID3D11Device* md3dDevice;					// Connects to the graphics card
	ID3D11DeviceContext* md3dImmediateContext;	// Settings for the GPU to use
	IDXGISwapChain* mSwapChain;					// image buffers used for rendering
	ID3D11RenderTargetView* mRenderTargetView;	// Where to send rendring operations (typically: points to one of the swap buffers)
	ID3D11DepthStencilView* mpDepthStencilView; // Needed to force depth-buffer operations
	ID3D11RasterizerState* FrontFaceAsCCWRS;

	ID3D11BlendState*			TransparentBS;

	D3D11_RASTERIZER_DESC	rd_normal;
	D3D11_RASTERIZER_DESC	rd_wireframe;

	Vect BackgroundColor;
	std::wstring mMainWndCaption;

	HRESULT InitWindow(const HINSTANCE& hInstance, int nCmdShow);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void InitializeDirect3D();
	//void CalculateFrameStats();
	void ReportLiveDXObjects();		// Debug utility
private:
	bool report;
	bool vsync;
	int mClientWidth;
	int mClientHeight;
	FLOAT dpiX;
	FLOAT dpiY;

	static int GetHeight() { return Instance().mClientHeight; };
	static int GetWidth() { return Instance().mClientWidth; };

	static void SetWidthHeight(const int width, const int height);
	static void SetWindowName(const char* text);



	static const HWND& GetHWNDWindow() { return Instance().mhMainWnd; };
	static void ClearBuffer();
	static void PresentBuffer();

	static void SetClearColor(const Vect& col);
	static void SetVsync(bool enable);
	static void SetDXReport(bool enable);

	static void Delete();
	static void Initialize(const HINSTANCE& hInstance, int nCmdShow) { Instance().privInitialize(hInstance, nCmdShow); };

public:

	static ID3D11Device* GetDevice() { return Instance().md3dDevice; };
	static ID3D11DeviceContext* GetDeviceContext() { return Instance().md3dImmediateContext; };
	static void SetRasterizer(D3D11_RASTERIZER_DESC rd);
	static void SetRasterizerWireframe();

	static void ResetRasterizer();
};


#endif // !RENDERER_H
