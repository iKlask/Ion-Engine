#ifndef RenderType_H
#define RenderType_H

class Camera;

class RenderType
{
public:
	RenderType() {};
	~RenderType() {};
	RenderType(const RenderType&) = delete;
	RenderType& operator=(const RenderType&) = delete;

	virtual void Render(Camera* pCam) = 0;
};

#endif
