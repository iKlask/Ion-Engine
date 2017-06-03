#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "RegistrationState.h"

//All game objects have access:
#include <map>
#include <list>
#include <assert.h>

/////////////////////////////////////////////////
///	\ingroup DEFAULT-EVENTS
/// \class GameObject
///	\brief Base class that all game entities derive from.
///
///	The base GameObject class gives an object the simple operations
///	of submitting commands to call SceneEntry() and SceneExit() functions. The GameObject
///	class also acts as a base class for implementing different event calls via
///	Updatable, Drawable, Alarmable, Inputable, and Collidable.
/////////////////////////////////////////////////
class GameObject {
	friend class GameObjectEntryCommand;
	friend class GameObjectExitCommand;

private:
	RegistrationState curr_RegState;

	GameObjectEntryCommand* pRegCmd;
	GameObjectExitCommand* pDeregCmd;

	void ConnectToScene();
	void DisconnectFromScene();
protected:
	/////////////////////////////////////////////////
	///	\brief Function which is called upon a registered scene entry
	///
	///	This is a pure virtual function to be overriden by the user.
	///	The SceneEntry() function will be called if the current object's SubmitEntry()
	///	function has been called elsewhere. This is used when dynamically creating objects during
	/// a scene.
	///
	///	This function for example might house registration function calls which need to be
	///	called on the entry to the scene.
	/////////////////////////////////////////////////
	virtual void SceneEntry() = 0;

	/////////////////////////////////////////////////
	///	\brief Function which is called upon a registered scene exit
	///
	///	This is a pure virtual function to be overriden by the user.
	///	The SceneExit() function will be called if the current object's SubmitExit()
	///	function has been called elsewhere. This is used when dynamically destroying objects during
	/// a scene.
	///
	///	This function for example might house deregistration function calls which need to be
	///	called on the exit from the scene.
	/////////////////////////////////////////////////
	virtual void SceneExit() = 0;
public:
	GameObject();
	virtual ~GameObject();
	GameObject(const GameObject&) = delete;
	GameObject& operator=(const  GameObject&) = delete;

	/////////////////////////////////////////////////
	///	\brief Public Function to register a call for the GameObject's SceneEntry() function
	///
	///	This function submits a command to call the SceneEntry() function on
	///	the next update cycle. This is used when dynamically creating objects during
	/// a scene.
	///
	///	For example, this function might be called from a factory that is reusing
	/// an already created object to register it to the scene (instead of creating a whole new object).
	/////////////////////////////////////////////////
	void SubmitEntry();

	/////////////////////////////////////////////////
	///	\brief Public Function to register a call for the GameObject's SceneEntry() function
	///
	///	This function submits a command to call the SceneEntry() function on
	///	the next update cycle. This is used when dynamically destroying objects during
	/// a scene.
	///
	///	For example, this function might be called from a factory that is removing
	/// an object from the scene (but not destroying it completely).
	/////////////////////////////////////////////////
	void SubmitExit();
};

#endif GAMEOBJECT_H