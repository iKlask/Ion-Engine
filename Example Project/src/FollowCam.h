#ifndef FOLLOWCAM_H
#define FOLLOWCAM_H

#include "IonCamera.h"
#include "Vect.h"
class FollowCam : public IonCamera
{
private:
	Vect* position;

	Vect up3DCam;
	Vect pos3DCam;
	Vect lookAt3DCam;

	float mRadius;
	float mPhi;
	float mTheta;

public:
	FollowCam() = default;
	FollowCam(Vect* ptrPos);
	FollowCam(const FollowCam&) = delete;
	FollowCam& operator=(const FollowCam&) = delete;
	~FollowCam();

	void SetLookAt(const Vect& point);
	void SetPos(const Vect& point);

	virtual void Update() override;

	Camera* getCamera();
};

#endif // !FollowCam_H
