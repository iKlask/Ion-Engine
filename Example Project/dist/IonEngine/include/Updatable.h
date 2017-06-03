#ifndef UPDATABLE_H
#define UPDATABLE_H

#include "GameObject.h"
//#include <list>

/////////////////////////////////////////////////
///	\ingroup UPDATE-EVENTS
/// \class Updatable
///	\brief A virtual derived class of GameObject that allows the GameObject to be updated.
///
///	A class that inherits from Updatable gains access to the Update() function. 
/// This allows the user to execute code every update frame.
/////////////////////////////////////////////////
class Updatable : public virtual GameObject
{
	friend class UpdatableManager;
	friend class UpdateRegistrationCommand;
	friend class UpdateDeregistrationCommand;
private:
	RegistrationState curr_RegState;
	UpdateRegistrationCommand* pRegCmd;
	UpdateDeregistrationCommand* pDeregCmd;

	std::list<Updatable*>::iterator pDeleteRef;

	void SceneRegistration();
	void SceneDeregistration();

	void SubmitUpdateRegistration();
	void SubmitUpdateDeregistration();
protected:
	/////////////////////////////////////////////////
	///	\brief Function which is called every update frame.
	///
	///	This is a pure virtual function to be overriden by the user.
	///	The Update() function will be called by the UpdatableManager every
	///	update frame as long as the current Updatable class is registered
	/// to be updated (See the Register() and Deregister() functions).
	/////////////////////////////////////////////////
	virtual void Update() = 0;

	/////////////////////////////////////////////////
	///	\brief Registers the class to be Updated.
	///
	///	The UpdatableManager keeps track of all Updatable GameObjects.
	/// Registering the current Updatable GameObject adds this object
	///	to the list of Updatables to be updated by the UpdatableManager.
	/////////////////////////////////////////////////
	void Register() { this->SubmitUpdateRegistration(); };

	/////////////////////////////////////////////////
	///	\brief Deregisters the class from being Updated.
	///
	///	The UpdatableManager keeps track of all Updatable GameObjects.
	/// Deregistering the current Updatable GameObject removes this object
	///	from the list of Updatables to be updated by the UpdatableManager.
	/////////////////////////////////////////////////
	void Deregister() { this->SubmitUpdateDeregistration(); };
public:
	Updatable();
	virtual ~Updatable();
	Updatable(const Updatable&) = delete;
	Updatable& operator=(const  Updatable&) = delete;
};

#endif UPDATABLE_H