#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "GameObject.h"
//#include <list>

/////////////////////////////////////////////////
///	\ingroup DRAW-EVENTS
/// \class Drawable
///	\brief A virtual derived class of GameObject that allows the GameObject to be drawn.
///
///	A class that inherits from Drawable gains access to the Draw() function. 
/// This allows the user to execute code every draw frame.
/////////////////////////////////////////////////
class Drawable : public virtual GameObject
{
	friend class DrawableManager;
	friend class DrawRegistrationCommand;
	friend class DrawDeregistrationCommand;
private:
	RegistrationState curr_RegState;
	DrawRegistrationCommand* pRegCmd;
	DrawDeregistrationCommand* pDeregCmd;

	std::list<Drawable*>::iterator pDeleteRef;

	void SceneRegistration();
	void SceneDeregistration();

	void SubmitDrawRegistration();
	void SubmitDrawDeregistration();
protected:
	/////////////////////////////////////////////////
	///	\brief Function which is called every draw frame.
	///
	///	This is a virtual function to be overriden by the user.
	///	The Draw() function will be called by the DrawableManager every
	///	draw frame as long as the current Drawable class is registered
	/// to be drawn (See the Register() and Deregister() functions).
	/////////////////////////////////////////////////
	virtual void Draw() {};

	/////////////////////////////////////////////////
	///	\brief Function which is called every draw frame for 2D elements.
	///
	///	This is a virtual function to be overriden by the user.
	///	The Draw2D() function will be called by the DrawableManager every
	///	draw frame as long as the current Drawable class is registered
	/// to be drawn (See the Register() and Deregister() functions). 2D
	/// elements are split from 3D elements to insure that the draw order
	/// is correct. Make SURE to use Draw2D when rendering 2D elements to the screen.
	/////////////////////////////////////////////////
	virtual void Draw2D() {};

	/////////////////////////////////////////////////
	///	\brief Registers the class to be Drawn.
	///
	///	The DrawableManager keeps track of all Drawable GameObjects.
	/// Registering the current Drawable GameObject adds this object
	///	to the list of Drawables to be drawn by the DrawableManager.
	/////////////////////////////////////////////////
	void Register() { this->SubmitDrawRegistration(); };

	/////////////////////////////////////////////////
	///	\brief Deregisters the class from being Drawn.
	///
	///	The DrawableManager keeps track of all Drawable GameObjects.
	/// Deregistering the current Drawable GameObject removes this object
	///	from the list of Drawables to be drawn by the DrawableManager.
	/////////////////////////////////////////////////
	void Deregister() { this->SubmitDrawDeregistration(); };
public:
	Drawable();
	virtual ~Drawable();
	Drawable(const Drawable&) = delete;
	Drawable& operator=(const  Drawable&) = delete;
};

#endif DRAWABLE_H