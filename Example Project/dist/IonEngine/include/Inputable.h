#ifndef INPUTABLE_H
#define INPUTABLE_H

#include "GameObject.h"
#include "Keyboard.h"
#include "InputEvent.h"

//#include <map>
//#include <list>


/////////////////////////////////////////////////
///	\ingroup INPUT-EVENTS
/// \class Inputable
///	\brief A virtual derived class of GameObject that allows the GameObject to register and test input keys.
///
///	A class that inherits from Inputable gains access to the KeyPressed() and KeyReleased() functions. 
/// These allow the user to execute code every time a registered key is pressed or released.
/////////////////////////////////////////////////
class Inputable : public virtual GameObject
{
	friend class InputRegistrationCommand;
	friend class InputDeregistrationCommand;
	friend class SingleKeyEventManager;
public:
	typedef std::pair<ION_KEY, INPUT_EVENT> KeyEventPair;
private:
	struct RegistrationData {
		RegistrationState curr_RegState;
		InputRegistrationCommand* pRegCmd;
		InputDeregistrationCommand* pDeregCmd;
		std::list<Inputable*>::iterator pSingleKeyManagerListRef;
	};
	
	void SceneRegistration(const KeyEventPair& key_pair);
	void SceneDeregistration(const KeyEventPair& key_pair);

	void SubmitInputRegistration(const KeyEventPair& key_pair);
	void SubmitInputDeregistration(const KeyEventPair& key_pair);
protected:
	/////////////////////////////////////////////////
	///	\brief Function which is called every time a registered key is pressed.
	///
	///	This is a pure virtual function to be overriden by the user.
	///	The KeyPressed() function will be called by the SingleKeyEventManager every
	///	time a registered key is pressed (See the RegisterKey() and DeregisterKey() functions).
	///
	///	\param key_in The ION_KEY type that is calling the event.
	/////////////////////////////////////////////////
	virtual void KeyPressed(const ION_KEY& key_in) = 0;

	/////////////////////////////////////////////////
	///	\brief Function which is called every time a registered key is released.
	///
	///	This is a pure virtual function to be overriden by the user.
	///	The KeyReleased() function will be called by the SingleKeyEventManager every
	///	time a registered key is released (See the RegisterKey() and DeregisterKey() functions).
	///
	///	\param key_in The ION_KEY type that is calling the event.
	/////////////////////////////////////////////////
	virtual void KeyReleased(const ION_KEY& key_in) = 0;

	/////////////////////////////////////////////////
	///	\brief Function to register a specific key and it's event type (pressed or released) 
	///
	///	This function registers the specified key and it's event type to be checked every frame
	///	for this Inputable GameObject. Each key can be registered twice to the
	///	SingleKeyEventManager; once for pressed and once for released. These can be specified by the
	///	folowing INPUT_EVENT enum types:
	///		- Pressed: INPUT_EVENT::KEY_PRESSED
	///		- Released: INPUT_EVENT::KEY_RELEASED
	///
	///	\param key_in The ION_KEY to be registered.
	///
	///	\param event_type The INPUT_EVENT of the key to be registered.
	/////////////////////////////////////////////////
	void RegisterKey(const ION_KEY& key_in, const INPUT_EVENT& event_type);

	/////////////////////////////////////////////////
	///	\brief Function to deregister a specific key and it's event type (pressed or released) 
	///
	///	This function deregisters the specified key and it's event type from being checked every frame
	///	for this Inputable GameObject. Each key can be deregistered twice from the
	///	SingleKeyEventManager; once for pressed and once for released. These can be specified by the
	///	folowing INPUT_EVENT enum types:
	///		- Pressed: INPUT_EVENT::KEY_PRESSED
	///		- Released: INPUT_EVENT::KEY_RELEASED
	///
	///	\param key_in The ION_KEY to be deregistered.
	///
	///	\param event_type The INPUT_EVENT of the key to be deregistered.
	/////////////////////////////////////////////////
	void DeregisterKey(const ION_KEY& key_in, const INPUT_EVENT& event_type);

public:
	std::map<KeyEventPair, RegistrationData> RegMap;	/*!< Map of data used for registering to the scene */

	Inputable();
	virtual ~Inputable();
	Inputable(const Inputable&) = delete;
	Inputable& operator=(const  Inputable&) = delete;
};

#endif INPUTABLE_H