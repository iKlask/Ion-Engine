#ifndef COLLISIONVOLUMEAABB_H
#define COLLISIONVOLUMEAABB_H

#include "Vect.h"
#include "Matrix.h"

#include "CollisionVolumeBoxBase.h"

class Model;
class CollisionVolumeBSphere;

/////////////////////////////////////////////////
///	\ingroup COLLISION-EVENTS
/// \class CollisionVolumeAABB
///	\brief CollisionVolume type for AABB volumes
///
///	Like CollisionVolumeOBB, this class inherits from CollisionVolumeBoxBase to share similar
///	functions and parameters that 'box based' CollisionVolumes have.
/////////////////////////////////////////////////
class CollisionVolumeAABB : public CollisionVolumeBoxBase
{
private:
	virtual void DebugView(const Vect & color) const;
public:
	CollisionVolumeAABB();
	virtual ~CollisionVolumeAABB();
	CollisionVolumeAABB(const CollisionVolumeAABB&) = delete;
	CollisionVolumeAABB& operator=(const CollisionVolumeAABB&) = delete;

	virtual void ComputeData(Model& mod, Matrix& mat);
	/////////////////////////////////////////////////
	///	\brief Function to update CollisionVolume data based off of a box generated from two Vect points
	///
	///	\param min Min corner of the AABB box
	///	\param max Max corner of the AABB box
	/////////////////////////////////////////////////
	virtual void ComputeData(const Vect & min, const Vect & max);

	virtual bool Intersect(const CollisionVolume& col) const;
	virtual bool Intersect(const CollisionVolumeBSphere& col) const;
	virtual bool Intersect(const CollisionVolumeAABB& col) const;
	virtual bool Intersect(const CollisionVolumeOBB& col) const;
};

#endif