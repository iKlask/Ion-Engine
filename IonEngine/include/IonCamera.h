#ifndef IONCAMERA_H
#define IONCAMERA_H

#include "Align16.h"
#include "Camera.h"

class Vect;
class Matrix;
/////////////////////////////////////////////////
/// \ingroup CAMERA
/// \class IonCamera
///	\brief Camera wrapper base class for making custom cameras
///
///	The IonCamera is a base class that allows user access to Camera functions
/// and the ability to Update the camera every frame. This class is used to
///	implement custom cameras.
/////////////////////////////////////////////////
class IonCamera : public Align16
{
protected:
	Camera* pCamera;	/*!< Pointer to the Camera object for this class */
public:
	IonCamera() {};
	IonCamera(Camera::Type type);
	virtual ~IonCamera();
	IonCamera(const IonCamera&) = delete;
	IonCamera& operator=(const  IonCamera&) = delete;

	/////////////////////////////////////////////////
	///	\brief Function which is called every update frame.
	///
	///	This is a pure virtual function to be overriden by the user.
	///	The Update() function will be called by the SceneManager every
	///	update frame via its CameraManager. This allows for updating the camera's
	/// position, rotation, etc every frame.
	/////////////////////////////////////////////////
	virtual void Update() = 0;

	/////////////////////////////////////////////////
	///	\brief Function which gives access to the Camera pointer.
	///
	///	This function returns the pointer to the Camera object within this class.
	/////////////////////////////////////////////////
	Camera* GetCamera();


	///@{ 
	/////////////////////////////////////////////////
	///	\brief Wrapped Camera class function.
	///
	///	This function is a simple passthrough to be called on pCamera.
	/// All the wrapped functions allow access to the Camera class functions
	/// of the same name.
	/////////////////////////////////////////////////
		void setPerspective(const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist);
		void setOrthographic(const float xMin, const float xMax, const float yMin, const float yMax, const float zMin, const float zMax);
		void setViewport(const int inX, const int inY, const int width, const int height);
		void setOrientAndPosition(const Vect &Up_vect, const Vect &inLookAt_pt, const Vect &pos_pt);

		// update camera system
		void updateCamera(void);

		// Get the matrices for rendering
		Matrix &getViewMatrix();
		Matrix &getProjMatrix();

		// accessors
		Camera::Type getType() const;

		void getPos(Vect &outPos) const;
		void getDir(Vect &outDir) const;
		void getUp(Vect &outUp) const;
		void getLookAt(Vect &outLookAt) const;
		void getRight(Vect &outRight) const;

		int getScreenWidth() const;
		int getScreenHeight() const;

		// Why no SETS?  Pos,Dir,Up,LookAt, Right
		//   They have to be adjust together in setOrientAndPosition()

		void getFieldOfView(float &Value) const;
		void setFieldOfView(const float Value);
	///@} 

};

#endif // !IONCAMERA_H

