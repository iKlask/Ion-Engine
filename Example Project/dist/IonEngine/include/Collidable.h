#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "GameObject.h"

#include "CollisionRegistrationCommand.h"
#include "CollisionDeregistrationCommand.h"

//#include "SceneManager.h" <- WHY? i guess through templates... ?
#include "Scene.h"

class CollisionCommandBase;
class Matrix;
class Model;
class CollisionVolume;
class CollisionVolumeBSphere;

/////////////////////////////////////////////////
/// \enum VolumeType
///	\brief Enum used with SetColliderModel() to determin the CollisionVolume type
/////////////////////////////////////////////////
enum VolumeType {
	BSPHERE,	/*!< Used with SetColliderModel() to set CollisionVolume to a BSPHERE*/
	AABB,		/*!< Used with SetColliderModel() to set CollisionVolume to an AABB*/
	OBB			/*!< Used with SetColliderModel() to set CollisionVolume to an OBB*/
};

/////////////////////////////////////////////////
///	\ingroup COLLISION-EVENTS
/// \class Collidable
///	\brief A virtual derived class of GameObject that allows the GameObject to test for collison.
///
///	A class that inherits from Collidable gains access to the Collision() function. 
/// This allows the user to execute code every time a collision is registered. This class
///	also contains functions and entities for storing/getting information about the collision model.
/////////////////////////////////////////////////
class Collidable : public virtual GameObject
{
private:
	RegistrationState curr_RegState = RegistrationState::CURRENTLY_DEREGISTERED;
	CollisionCommandBase* pRegCmd;
	CollisionCommandBase* pDeregCmd;
protected:
	/////////////////////////////////////////////////
	///	\brief Function that is called when collision with another Collidable GameObject is triggered
	///
	///	This is a virtual function to be overriden by the user for each Collidable
	///	GameObject that is paired for Collision.
	///
	///	The Collision function is called every frame that the registered and paired Collidable GameObjects are colliding.
	/// To register the current Collidable GameObject for collision, see CollisionRegister() and CollisionDeregister().
	///	To pair Collidable GameObjects for testing, see the Scene::SetCollisionPair() and Scene::SetCollisionSelf() functions.
	///
	///	\param ptrCol Pointer to the Collidable GameObject that is colliding with the current Collidable GameObject.
	/////////////////////////////////////////////////
	virtual void Collision(Collidable* ptrCol);


	Model* pColModel;					/*!< Pointer to the model that will be tested for collision */
	CollisionVolume* ColVolume;			/*!< Collision Volume of the model stored as a CollisionVolume */
	CollisionVolumeBSphere* Default_BSphere;


	/////////////////////////////////////////////////
	///	\brief Function to set the Collider Model and Collision Volume of this Collidable GameObject
	///
	///	This function assigns a model to the pointer pColModel and initialized the
	///	Collision Volume based on a VolumeType enum.
	///
	///	\param mod Pointer to model that this class will reference.
	///	\param volume VolumeType enum for the type of collision volume to use (defualts to BSHPERE)
	/////////////////////////////////////////////////
	void SetColliderModel(Model * mod, VolumeType volume = VolumeType::BSPHERE);

	/////////////////////////////////////////////////
	///	\brief Function to update the current Collidable placement
	///
	///	This function updates the current placement of the collision data
	/// based on the world matrix passed in as parameter mat.
	///
	///	\param mat World Matrix reference.
	/////////////////////////////////////////////////
	void UpdateCollisionData(Matrix& mat);

	/////////////////////////////////////////////////
	///	\brief Function to register this Collidable GameObject for collision
	///
	/// Registering the current Collidable GameObject adds this object
	///	to the list of Collidable's to be checked for collision each frame.
	///
	///	An example use of this function would go as follows:
	/// \code{.cpp} 
	///	Class::SceneEntry(){
	///		...
	///		CollisionRegister<Class>(*this);
	///	}
	///	\endcode
	/////////////////////////////////////////////////
	template<typename C>	//make const?
	void CollisionRegister(C* ptrCollision) {
		if (pRegCmd == nullptr) {
			pRegCmd = new CollisionRegistrationCommand<C>(ptrCollision);
		}
		assert(curr_RegState == RegistrationState::CURRENTLY_DEREGISTERED && "Collision already Registered");
		SceneManager::GetCurrentScene()->SubmitCommand(pRegCmd);
		curr_RegState = RegistrationState::CURRENTLY_REGISTERED;
	}

	/////////////////////////////////////////////////
	///	\brief Function to deregister this Collidable GameObject from collision
	///
	/// Deregistering the current Collidable GameObject removes this object
	///	from the list of Collidable's to be checked for collision each frame.
	///
	///	An example use of this function would go as follows:
	/// \code{.cpp} 
	///	Class::SceneExit(){
	///		...
	///		CollisionDeregister<Class>(*this);
	///	}
	///	\endcode
	template<typename C>	//make const?
	void CollisionDeregister(C* ptrCollision) {
		if (pDeregCmd == nullptr) {
			pDeregCmd = new CollisionDeregistrationCommand<C>(ptrCollision);
		}
		assert(curr_RegState == RegistrationState::CURRENTLY_REGISTERED && "Collision already deregistered");
		SceneManager::GetCurrentScene()->SubmitCommand(pDeregCmd);
		curr_RegState = RegistrationState::CURRENTLY_DEREGISTERED;
	}

public:
	Collidable();
	virtual ~Collidable();
	Collidable(const Collidable&) = delete;
	Collidable& operator=(const  Collidable&) = delete;

	/////////////////////////////////////////////////
	///	\brief Function that is called when collision with Terrain is triggered
	///
	///	This is a virtual function to be overriden by the user for the Collidable
	///	GameObject that is paired for Collision with Terrain.
	///
	///	The CollisionTerrain function is called every frame that the registered Collidable is colliding with Terrain.
	/// To register the current Collidable GameObject for Terrain Collision, see the Scene::SetCollisionTerrain()
	///
	/////////////////////////////////////////////////
	virtual void CollisionTerrain();

	/////////////////////////////////////////////////
	///	\brief Function to return a reference to the Collision Volume
	///
	///	This function returns a reference to this Collidable GameObject's
	///	CollisionVolume.
	///
	/// \return const reference to the class's Collision volume 
	/////////////////////////////////////////////////
	const CollisionVolume & GetCollisionVolume() const;

	/////////////////////////////////////////////////
	///	\brief Function to return a reference to the defualt Collision Volume
	///
	///	This function returns a reference to this Collidable GameObject's
	///	defualt BSphere CollisionVolume.
	///
	/// \return const reference to the class's BSphere Collision volume 
	/////////////////////////////////////////////////
	const CollisionVolumeBSphere & GetDefualtBSphere() const;

};

#endif COLLIDABLE_H