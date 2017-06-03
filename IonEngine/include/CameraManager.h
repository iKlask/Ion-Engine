#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

class Camera;
class IonCamera;
class Vect;
class CameraManager
{
public:
	IonCamera * pCam3D;
	IonCamera * pCam2D;

	CameraManager() {};// = default;							// Private constructor
	CameraManager(const CameraManager&) = delete;				// Prevent copy-construction
	CameraManager& operator=(const CameraManager&) = delete;	// Prevent assignment
	~CameraManager();											// Only this class can delete

	void Update();

	Camera * Get3DCamera();
	Camera * Get2DCamera();
	void InitialzeDefaultCamera();

	//void InitialzeFollowCamera(const Vect* ptrVect);
	//void InitialzeGodCamera();

	void SetCamera(IonCamera* const cam);

	//static void Delete();
};

#endif
