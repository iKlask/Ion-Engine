#ifndef COLLISIONVOLUMEBSPHERE_H
#define COLLISIONVOLUMEBSPHERE_H

#include "Vect.h"
#include "Matrix.h"
#include "CollisionVolume.h"

class Model;
class CollisionVolumeAABB;
class CollisionVolumeOBB;

/////////////////////////////////////////////////
///	\ingroup COLLISION-EVENTS
/// \class CollisionVolumeBSphere
///	\brief CollisionVolume type for BSphere volumes
/////////////////////////////////////////////////
class CollisionVolumeBSphere : public CollisionVolume
{
private:
	Matrix world;
	Vect Center;
	float Radius;
	float Scale;

	virtual void DebugView(const Vect & color) const;
public:
	CollisionVolumeBSphere();
	virtual ~CollisionVolumeBSphere();
	CollisionVolumeBSphere(const CollisionVolumeBSphere&) = delete;
	CollisionVolumeBSphere& operator=(const CollisionVolumeBSphere&) = delete;

	/////////////////////////////////////////////////
	///	\brief Gets the center point of the BSphere in world space
	///	\return Vect of Center point
	/////////////////////////////////////////////////
	const Vect& GetCenter() const;
	/////////////////////////////////////////////////
	///	\brief Gets the world matrix of the BSphere
	///	\return World Matrix
	/////////////////////////////////////////////////
	const Matrix& GetWorld() const;
	/////////////////////////////////////////////////
	///	\brief Gets the radius of the BSphere
	///	\return float of radius
	/////////////////////////////////////////////////
	float GetRadius() const;
	/////////////////////////////////////////////////
	///	\brief Gets the scale of the BSphere matrix
	///	\return float of scale
	/////////////////////////////////////////////////
	float GetScale() const;
	/////////////////////////////////////////////////
	///	\brief Gets the min corner point of the BSphere in world space
	///
	///	This function is helpful for generating an AABB of the BSphere
	///
	///	\return Vect of min corner
	/////////////////////////////////////////////////
	Vect GetMin() const;
	/////////////////////////////////////////////////
	///	\brief Gets the min corner point of the BSphere in world space
	///
	///	This function is helpful for generating an AABB of the BSphere
	///
	///	\return Vect of min corner
	/////////////////////////////////////////////////
	Vect GetMax() const;

	virtual void ComputeData(Model& mod, Matrix& mat);

	virtual bool Intersect(const CollisionVolume& col) const;
	virtual bool Intersect(const CollisionVolumeBSphere& col) const;
	virtual bool Intersect(const CollisionVolumeAABB& col) const;
	virtual bool Intersect(const CollisionVolumeOBB& col) const;
};

#endif