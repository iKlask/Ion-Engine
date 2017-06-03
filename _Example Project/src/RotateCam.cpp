#include "RotateCam.h"
#include "IonEngine.h"
#include "TimeManager.h"

RotateCam::RotateCam(const Vect& Pos)
{
	//position = Pos;

	pCamera = new Camera(Camera::Type::PERSPECTIVE_3D);
	pCamera->setViewport(0, 0, IonEngine::GetWindowWidth(), IonEngine::GetWindowHeight());
	pCamera->setPerspective(60.0f, float(IonEngine::GetWindowWidth()) / float(IonEngine::GetWindowHeight()), 1.0f, 5000.0f);

	// Orient Camera
	up3DCam = Vect(0.0f, 1.0f, 0.0f);
	pos3DCam = Pos + Vect(50, 40, 30);
	lookAt3DCam = Pos;

	pCamera->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	pCamera->updateCamera();
}

RotateCam::~RotateCam()
{
}

void RotateCam::Update()
{
	pos3DCam *= Matrix(ROT_Y, 1.0f * TimeManager::GetFrameTime());
	pCamera->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	pCamera->updateCamera();
}
