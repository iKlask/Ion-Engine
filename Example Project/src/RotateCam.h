#ifndef RotateCam_H
#define RotateCam_H

#include "Vect.h"
#include "IonCamera.h"

class RotateCam : public IonCamera
{
private:
	//Vect position;

	Vect up3DCam;
	Vect pos3DCam;
	Vect lookAt3DCam;

	//float mRadius;
	//float mPhi;
	//float mTheta;

public:
	RotateCam() = default;
	RotateCam(const Vect& Pos);
	RotateCam(const RotateCam&) = delete;
	RotateCam& operator=(const RotateCam&) = delete;
	~RotateCam();

	virtual void Update() override;
};

#endif // !RotateCam_H
