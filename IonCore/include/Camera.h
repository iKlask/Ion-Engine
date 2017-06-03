#ifndef CAMERA_H
#define CAMERA_H

#include "Vect.h"
#include "Matrix.h"
#include "d3d11.h"

class Camera final : public Align16
{

public:
	enum class Type
	{
		PERSPECTIVE_3D,
		ORTHOGRAPHIC_2D
	};

	// Default constructor
	Camera( Camera::Type type);
	~Camera() = default;

	// Setup on single camera
	void setPerspective(const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist);
	void setOrthographic(const float xMin, const float xMax, const float yMin, const float yMax, const float zMin, const float zMax);
	void setViewport(const int inX, const int inY, const int width, const int height);														
	void setOrientAndPosition(const Vect &Up_vect, const Vect &inLookAt_pt, const Vect &pos_pt);

	// update camera system
	void updateCamera(void);

	// Get the matrices for rendering
	Matrix& getViewMatrix();
	Matrix& getProjMatrix();

	// accessors
	Camera::Type getType() const;

	// Why no SETS for Pos, Dir, Up, LookAt and Right?
	//   They have to be adjusted _together_ in setOrientAndPosition()
	void getPos(Vect &outPos) const;
	void getDir(Vect &outDir) const;
	void getUp(Vect &outUp) const;
	void getLookAt(Vect &outLookAt) const;
	void getRight(Vect &outRight) const;

	int getScreenWidth() const;
	int getScreenHeight() const;

	void getFieldOfView(float &ret_FieldOfView) const;
	void setFieldOfView(const float FieldOfView_Degs);
private:
	//Force custom cunstructor
	Camera() = default;

	//void privCalcPlaneHeightWidth(void);				//	TO DO?
	//void privCalcFrustumVerts(void);					//	TO DO?
	//void privCalcFrustumCollisionNormals(void);		 //	TO DO?
	void privUpdateProjectionMatrix(void);
	void privUpdateViewMatrix(void);

	// Projection Matrix
	Matrix	projMatrix;
	Matrix	viewMatrix;

	// camera unit vectors (up, dir, right)
	Vect	vUp;
	Vect	vDir;
	Vect	vRight;  // derived by up and dir
	Vect	vPos;
	Vect	vLookAt;

	Camera::Type camType;

	// Define the frustum inputs
	float	nearClip;		
	float	farClip;

	float	leftClip;
	float	rightClip;

	float	topClip;
	float	bottomClip;

	float	fovy;			
	float	aspectRatio;

	D3D11_VIEWPORT vp;
};

#endif