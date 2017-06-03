#include "FirstPersonCam.h"
#include "IonEngine.h"
//#include "Camera.h"

FirstPersonCam::FirstPersonCam(Vect * ptrPos, Matrix * ptrRot)
{
	position = ptrPos;
	rotation = ptrRot;

	CamPos = *position;
	CamRot = *rotation;
	CamUp = Vect(0, 1, 0);			// Using local Y axis as 'Up'
	CamDir = Vect(0, 0, 1);			// Using the local Z axis as 'forward'

	pCamera = new Camera(Camera::Type::PERSPECTIVE_3D);
	pCamera->setViewport(0, 0, IonEngine::GetWindowWidth(), IonEngine::GetWindowHeight());
	pCamera->setPerspective(50.0f, float(IonEngine::GetWindowWidth()) / float(IonEngine::GetWindowHeight()), 1.0f, 10000.0f);


	Vect Target(0, 0, 0);
	CamRot.set(ROT_ORIENT, Target - CamPos, CamUp);

	pCamera->setOrientAndPosition(CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	pCamera->updateCamera();
}

FirstPersonCam::~FirstPersonCam()
{
}

void FirstPersonCam::Update()
{
	CamPos = *position;
	CamRot = *rotation;

	pCamera->setOrientAndPosition(CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	pCamera->updateCamera();
}

/*
Camera * FirstPersonCam::getCamera()
{
	return pCamera;
}
*/
