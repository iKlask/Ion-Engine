#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "SceneManagerBroker.h"

class Scene;
class CollisionCommandBase;
class IonCamera;
class CollidableGroupBase;
class Camera;
class Terrain;

/////////////////////////////////////////////////
/// \ingroup SCENE
/// \class SceneManager
///	\brief System manager for storage and access to the current scene.
///
///	The SceneManager is a singleton that allows the user to 
///	get the current scene and set the current scene.
///
/////////////////////////////////////////////////
class SceneManager
{
	enum class SceneChangeState {
		NO_CHANGE,
		PENDING_CHANGE
	};

	friend class SceneChangeCommand;
	friend class IonEngine;

private:
	Scene * NULLSCENE;
	Scene * Current_Scene;
	SceneChangeCommand * pSChangeCmd;
	SceneManagerBroker SceneMang_Broker;

	SceneChangeState curState;

	SceneManager();										// Private constructor
	~SceneManager();										// Only this class can delete
	SceneManager(const SceneManager&) = delete;				// Prevent copy-construction
	SceneManager& operator=(const SceneManager&) = delete;	// Prevent assignment

	static SceneManager* ptrInstance;
	static SceneManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new SceneManager;
		return *ptrInstance;
	};

	void privUpdate();
	void privDraw();
	void privDelete();
	void privStartScene();

	void privSetCurScene(Scene* const Input_Scene);
	Scene * privGetCurrentScene();


	void privSubmitSceneChange(Scene* const input_scene);
	void privSceneChange(Scene* const input_scene);

	void privRegisterCollDelete(CollisionCommandBase* cmd);
	void privRegisterColGroup(CollidableGroupBase* col);

	/* Functions for friend classes to use*/
	static void Update() { Instance().privUpdate(); };
	static void Draw() { Instance().privDraw(); };
	static void StartScene() { Instance().privStartScene(); };
	static void Delete() { Instance().privDelete(); };
	/*====================================*/
public:
	//static void SetCurScene(Scene* const Input_Scene) { Instance().privSetCurScene(Input_Scene); };

	/////////////////////////////////////////////////
	///	\brief Function for acquiring a pointer to the current scene.
	///
	///	\return Pointer to the current scene object
	/////////////////////////////////////////////////
	static Scene * GetCurrentScene() { return Instance().privGetCurrentScene(); };

	/////////////////////////////////////////////////
	///	\brief Function for changing the scene.
	///
	///	This function will submit the passed in input_scene to become the
	///	current scene after the next update cycle. This will destroy the old
	///	scene and initialize the input_scene.
	///
	///	\param input_scene Constant pointer to scene object to be set as current scene.
	/////////////////////////////////////////////////
	static void SceneChange(Scene* const input_scene) { Instance().privSubmitSceneChange(input_scene); };

	/////////////////////////////////////////////////
	///	\brief Function for setting the current Scene's Camera
	///
	///	This function will set the Current Scene's Camera to the passed in 
	///	IonCamera pointer.
	///
	///	\param input_cam pointer to IonCamera object to be set as the current camera.
	/////////////////////////////////////////////////
	static void SetSceneCamera(IonCamera* input_cam);

	/////////////////////////////////////////////////
	///	\brief Function for acquiring a pointer to the current 2D Camera.
	///
	///	\return Pointer to the current 2D camera object
	/////////////////////////////////////////////////
	static Camera* GetCurSceneCam3D();

	/////////////////////////////////////////////////
	///	\brief Function for acquiring a pointer to the current 3D Camera.
	///
	///	\return Pointer to the current 3D camera object
	/////////////////////////////////////////////////
	static Camera* GetCurSceneCam2D();

	/////////////////////////////////////////////////
	///	\brief Function for acquiring a pointer to the current scene's Terrain.
	///
	///	\return Pointer to the current scene Terrain
	/////////////////////////////////////////////////
	static Terrain* GetCurrentTerrain();

	// =====================================================
	//static void RegisterCollDelete(CollisionCommandBase* cmd) { Instance().privRegisterCollDelete(cmd); };
	static void RegisterColGroup(CollidableGroupBase* col) { Instance().privRegisterColGroup(col); };
};
#endif SCENEMANAGER_H