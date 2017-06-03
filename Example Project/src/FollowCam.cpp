#include "FollowCam.h"
#include "IonEngine.h"
#include "Camera.h"

FollowCam::FollowCam(Vect * ptrPos)
{
	position = ptrPos;

	pCamera = new Camera(Camera::Type::PERSPECTIVE_3D);
	pCamera->setViewport(0, 0, IonEngine::GetWindowWidth(), IonEngine::GetWindowHeight());
	pCamera->setPerspective(60.0f, float(IonEngine::GetWindowWidth()) / float(IonEngine::GetWindowHeight()), 1.0f, 5000.0f);

	mTheta = 0.025f;
	//mPhi = 0.025f;
	mRadius = 70.0f;


	// Orient Camera
	up3DCam = Vect(0.0f, 1.0f, 0.0f);
	pos3DCam = *position + Vect(50, 50, -mRadius);	//make sure it is behind object
	lookAt3DCam = *position;

	pCamera->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	pCamera->updateCamera();  // Note: if the camera moves/changes, we need to call update again
}

FollowCam::~FollowCam()
{
	//delete pCamera;
}

void FollowCam::SetLookAt(const Vect & point)
{
	lookAt3DCam = point;
}

void FollowCam::SetPos(const Vect & point)
{
	pos3DCam = point + Vect(0,0,-mRadius);	//make sure it is behind object
}

void FollowCam::Update()
{
	pos3DCam = *position + Vect(50, 50, -mRadius);	//make sure it is behind object
	lookAt3DCam = *position;
	pCamera->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	pCamera->updateCamera();  // Note: if the camera moves/changes, we need to call update again
}

Camera * FollowCam::getCamera()
{
	return pCamera;
}
