#ifndef COLLISIONVOLUMEOBB_H
#define COLLISIONVOLUMEOBB_H

#include "Vect.h"
#include "Matrix.h"

#include "CollisionVolumeBoxBase.h"

class Model;
class CollisionVolumeBSphere;
class CollisionVolumeAABB;

/////////////////////////////////////////////////
///	\ingroup COLLISION-EVENTS
/// \class CollisionVolumeOBB
///	\brief CollisionVolume type for OBB volumes
///
///	Like CollisionVolumeAABB, this class inherits from CollisionVolumeBoxBase to share similar
///	functions and parameters that 'box based' CollisionVolumes have.
/////////////////////////////////////////////////
class CollisionVolumeOBB : public CollisionVolumeBoxBase
{
private:
	virtual void DebugView(const Vect & color) const;
public:
	CollisionVolumeOBB(const Model & mod);
	virtual ~CollisionVolumeOBB();
	CollisionVolumeOBB(const CollisionVolumeOBB&) = delete;
	CollisionVolumeOBB& operator=(const CollisionVolumeOBB&) = delete;

	/////////////////////////////////////////////////
	///	\brief Function to update CollisionVolume data based off of a Model and a world Matrix
	///
	///	\param mod Model to base the CollisionVolume off of
	///	\param mat World Matrix to modify the CollisionVolume by
	/////////////////////////////////////////////////
	virtual void ComputeData(Model& mod, Matrix& mat);

	virtual bool Intersect(const CollisionVolume& col) const;
	virtual bool Intersect(const CollisionVolumeBSphere& col) const;
	virtual bool Intersect(const CollisionVolumeAABB& col) const;
	virtual bool Intersect(const CollisionVolumeOBB& col) const;
};

#endif