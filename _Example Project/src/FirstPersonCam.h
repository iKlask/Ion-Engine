#ifndef FirstPersonCam_H
#define FirstPersonCam_H

#include "IonCamera.h"

class FirstPersonCam : public IonCamera
{
private:
	Vect* position;
	Matrix* rotation;

	Matrix CamRot;
	Vect CamPos;
	Vect CamUp;
	Vect CamDir;

	float mRadius;
	float mPhi;
	float mTheta;

public:
	FirstPersonCam() = default;
	FirstPersonCam(Vect* ptrPos, Matrix * ptrRot);
	FirstPersonCam(const FirstPersonCam&) = delete;
	FirstPersonCam& operator=(const FirstPersonCam&) = delete;
	~FirstPersonCam();

	virtual void Update() override;

	//Camera* getCamera();
};

#endif // !FirstPersonCam_H
