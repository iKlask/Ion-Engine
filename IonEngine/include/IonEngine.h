#ifndef IONENGINE_H
#define IONENGINE_H

#include "Engine.h"

class SceneManager;

/////////////////////////////////////////////////
/// \class IonEngine
///	\brief Main engine class
///
///	IonEngine is a singlton class for the main engine.
///	This class provides a few methods for accessing and setting
///	various parameters of the window and engine. The engine is simply started
/// by calling the Run() function.
/////////////////////////////////////////////////

class IonEngine : public Engine
{
	friend class FreezeTime;
private:
	IonEngine() = default;								// Private constructor
	IonEngine(const IonEngine&) = delete;				// Prevent copy-construction
	IonEngine& operator=(const IonEngine&) = delete;	// Prevent assignment
	~IonEngine() = default;								// Only this class can delete

	char title_buffer[256]; // probably overkill


	static IonEngine* ptrInstance;
	static IonEngine& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new IonEngine;
		return *ptrInstance;
	};

	virtual void Initialize();
	virtual void LoadContent();
	virtual void Update();
	virtual void Draw();
	virtual void UnLoadContent();

	/////////////////////////////////////////////////
	///	\ingroup RESOURCES
	///	\brief Public engine function for loading assets/resources
	///
	///	Within the LoadResources() function the user is able to load external
	///	resources like Models, Textures, Shaders, etc using the appropriate 
	///	Asset Managers (ModelAssets, TextureAssets, ImageAssets, ShaderAssets, 
	///	TerrainAssets, and SkyBoxAssets).
	/////////////////////////////////////////////////
	void LoadResources();

	/////////////////////////////////////////////////
	///	\ingroup SCENE
	///	\brief Public engine function for initialization of the engine.
	///
	///	Within the InitializeEngine() function the user can set up start up
	///	operations such as setting window dimensions, creation of the first scene,
	///	initialization of singletons, etc...
	/////////////////////////////////////////////////
	void InitializeEngine();

	/////////////////////////////////////////////////
	///	\ingroup SCENE
	///	\brief Public engine function that is called when shitting down
	///
	///	Within the EngineEnd() function the user can preform cleanup on objects that normally
	/// aren't cleaned up elsewhere (like singletons).
	/////////////////////////////////////////////////
	void EngineEnd();

	static float GetTime() { return Instance().GetTimeInSeconds(); };

	bool enableDebugInfo;
public:
	/////////////////////////////////////////////////
	///	\brief Function that starts the Engine
	/////////////////////////////////////////////////
	static void Run() { 
		Instance().run();

		delete ptrInstance;
		ptrInstance = nullptr;
	}

	/////////////////////////////////////////////////
	///	\brief Function for setting the window name
	///
	///	\param Window_Name char string for new window name
	/////////////////////////////////////////////////
	static void SetWindowName(const char* Window_Name) { Instance().setWindowName(Window_Name); };
	/////////////////////////////////////////////////
	///	\brief Function for setting the window width and height
	///
	///	\param Window_Width int for window width
	///	\param Window_Height int for window height
	/////////////////////////////////////////////////
	static void SetWidthHeight(const int Window_Width, const int Window_Height) { Instance().setWidthHeight(Window_Width, Window_Height); };
	/////////////////////////////////////////////////
	///	\brief Function for setting the Background color of the window
	///
	///	\param Col Color Vect ref for background color
	/////////////////////////////////////////////////
	static void SetBackgroundColor(const Vect& Col);
	/////////////////////////////////////////////////
	///	\brief Function for setting the Background color of the window
	///
	///	\param fl_Red Color float for red value
	///	\param fl_Green Color float for green value
	///	\param fl_Blue Color float for blue value
	///	\param fl_Alpha Color float for alpha value
	/////////////////////////////////////////////////
	static void SetBackgroundColor(const float fl_Red, const float fl_Green, const float fl_Blue, const float fl_Alpha) { Instance().SetClearColor(fl_Red, fl_Green, fl_Blue, fl_Alpha); };

	/////////////////////////////////////////////////
	///	\brief Function for getting the window width
	///
	///	\return int width of window
	/////////////////////////////////////////////////
	static int GetWindowWidth() { return Instance().getWidth(); };
	/////////////////////////////////////////////////
	///	\brief Function for getting the window height
	///
	///	\return int height of window
	/////////////////////////////////////////////////
	static int GetWindowHeight() { return Instance().getHeight(); };

	/////////////////////////////////////////////////
	///	\brief Function for enabling debug output in the window title
	///
	///	\param enable bool to enable
	/////////////////////////////////////////////////
	static void EnableDebugTitle(bool enable) { Instance().enableDebugInfo = enable; };
};

#endif