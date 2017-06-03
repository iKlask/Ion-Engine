#ifndef SCENE_H
#define SCENE_H

#include "UpdatableManager.h"
#include "DrawableManager.h"
#include "AlarmableManager.h"
#include "KeyboardEventManager.h"	//<- includes Inputable...
#include "TerrainObjectManager.h"
#include "SkyBoxManager.h"

#include "CollidableManager.h"	// <-- CommandBase

#include "CameraManager.h"
#include "SceneRegistrationBroker.h"	// <-- CommandBase

class CollisionGroupDeleteCommand;
//class CommandBase;	//Knows about commandBase?


/////////////////////////////////////////////////
///	\ingroup SCENE
/// \class Scene
///	\brief The space in which gameobjects exist.
///
///	The scene object is where the user puts together GameObjects and other classes to form
///	levels. The scene class takes care of updating all GameObjects that are registered within their
///	specified managers.
///
///	When deriving a new scene, the user must implement the two pure virtual functions:
///		- Initialize(): Code to be called upon initialization of the scene.
///		- SceneEnd(): Code to be called upon the end of the scene.
///
///	The scene class also allows access to setting/getting the current 
///	camera and registering collision pairs.
/////////////////////////////////////////////////
class Scene
{
private:
	friend class SceneManager;
	friend class GameObject;
	friend class Updatable;
	friend class Drawable;
	friend class Alarmable;
	friend class Inputable;
	friend class Collidable;

	UpdatableManager Update_Manager;
	DrawableManager Draw_Manager;
	AlarmableManager Alarm_Manager;
	KeyboardEventManager KeyboardEvent_Manager;
	CollidableManager Collison_Manager;
	TerrainObjectManager Terrain_Manager;
	SkyBoxManager SkyBox_Manager;

	SceneRegistrationBroker RegBroker;
	CameraManager Camera_Manager;

	typedef std::pair<ION_KEY, INPUT_EVENT> KeyEventPair;

	void Update();
	void Draw();

	void Register(Inputable* inputPtr, const KeyEventPair& key_pair);
	void Deregister(Inputable* inputPtr, const KeyEventPair& key_pair);

	void Register(Drawable* drwPtr);
	void Deregister(Drawable* drwPtr);

	void Register(Updatable* upPtr);
	void Deregister(Updatable* upPtr);

	void Register(const float& tme, Alarmable* alrPtr, const AlarmID& aID);
	void Deregister(Alarmable* alrPtr, const AlarmID& aID);

	void SubmitCommand(CommandBase* cmd);

	void RegisterDelete(CollisionCommandBase * cmd);

	void AddCollisionGroup(CollidableGroupBase* col);

	//void Register(CollisionGroupDeleteCommand* cmd);	//Collision

	void InitialzeDefaultSceneCamera() { this->Camera_Manager.InitialzeDefaultCamera(); };
protected:
	/////////////////////////////////////////////////
	///	\brief Registers two Collidable class types to test for collision.
	/////////////////////////////////////////////////
	template <typename C1, typename C2>
	void SetCollisionPair()
	{
		Collison_Manager.SetCollisionPair<C1, C2>();
	}

	/////////////////////////////////////////////////
	///	\brief Registers Collidable class type to test for collision with itself.
	/////////////////////////////////////////////////
	template <typename C>
	void SetCollisionSelf()
	{
		Collison_Manager.SetCollisionSelf<C>();
	}

	/////////////////////////////////////////////////
	///	\brief Registers Collidable class type to test for collision with Terrain.
	/////////////////////////////////////////////////
	template <typename C>
	void SetCollisionTerrain()
	{
		Collison_Manager.SetCollisionTerrain<C>();
	}

public:
	Scene();
	virtual ~Scene();
	Scene(const Scene&) = delete;				
	Scene& operator=(const Scene&) = delete;

	/////////////////////////////////////////////////
	///	\brief Function to be called upon initialization of the scene.
	///
	///	This function is a pure virtual function to be overriden by the user.
	///	Code within this function will be called upon the initialization of this scene.
	///	Therefore, construction and registration of objects for the scene should be placed here.
	/////////////////////////////////////////////////
	virtual void Initialize() = 0;

	/////////////////////////////////////////////////
	///	\brief Function to be called upon the end of the scene.
	///
	///	This function is a pure virtual function to be overriden by the user.
	///	Code within this function will be called upon the end of this scene.
	///	Therefore, destruction and deregistration of objects for the scene should be placed here.
	/////////////////////////////////////////////////
	virtual void SceneEnd() = 0;

	/////////////////////////////////////////////////
	///	\brief Function to get the current scene's camera.
	///
	///	\return Pointer to camera object.
	/////////////////////////////////////////////////
	Camera * GetCamera3D() { return this->Camera_Manager.Get3DCamera(); };

	/////////////////////////////////////////////////
	///	\brief Function to get the current scene's 2D camera.
	///
	///	\return Pointer to camera object.
	/////////////////////////////////////////////////
	Camera * GetCamera2D() { return this->Camera_Manager.Get2DCamera(); };

	/////////////////////////////////////////////////
	///	\brief Function to set the current scene's IonCamera.
	///
	///	\param cam Pointer to IonCamera object.
	/////////////////////////////////////////////////
	void SetCamera(IonCamera* cam) { Camera_Manager.SetCamera(cam); };

	/////////////////////////////////////////////////
	///	\brief Function to set the current scene's Terrain.
	///
	///	This function sets the current scene's terrain based off a key
	///	stored in TerrainAssets. If no Terrain is set then the scene's terrain is Null.
	///
	///	\param Terrain_Asset_Key const char pointer for key stored in TerrainAssets.
	/////////////////////////////////////////////////
	void SetTerrain(const char* Terrain_Asset_Key);

	/////////////////////////////////////////////////
	///	\brief Function to get the current scene's Terrain.
	///
	///	\return Terrain pointer of current scene terrain.
	/////////////////////////////////////////////////
	Terrain* GetCurTerrain();

	/////////////////////////////////////////////////
	///	\brief Function to set the current scene's SkyBox.
	///
	///	This function sets the current scene's skybox based off a key
	///	stored in SkyBoxAssets. If no skybox is set then the scene's skybox is Null.
	///
	///	\param Sky_Asset_Key const char pointer for key stored in SkyBoxAssets.
	/////////////////////////////////////////////////
	void SetSkyBox(const char* Sky_Asset_Key);
};

#endif SCENE_H

