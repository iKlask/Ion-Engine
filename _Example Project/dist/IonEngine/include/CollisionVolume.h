#ifndef COLLISIONVOLUME_H
#define COLLISIONVOLUME_H

class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;
class CollisionVolumeBoxBase;
class Model;
class Matrix;
class Vect;

/////////////////////////////////////////////////
///	\ingroup COLLISION-EVENTS
/// \class CollisionVolume
///	\brief An abstract base class for collision test type volumes.
///
///	This class provides intersect methods for the Collidable GameObjects to detect Collision.
/////////////////////////////////////////////////
class CollisionVolume : public Align16
{
	friend class Visualizer;
private:
	virtual void DebugView(const Vect& color) const = 0;
public:
	CollisionVolume() = default;
	virtual ~CollisionVolume() = default;
	CollisionVolume(const CollisionVolume&) = delete;
	CollisionVolume& operator=(const CollisionVolume&) = delete;

	/////////////////////////////////////////////////
	///	\brief Function to update CollisionVolume data based off of a Model and a world Matrix
	///
	///	\param mod Model to base the CollisionVolume off of
	///	\param mat World Matrix to modify the CollisionVolume by
	/////////////////////////////////////////////////
	virtual void ComputeData(Model& mod, Matrix& mat) = 0;

	///@{ 
	/////////////////////////////////////////////////
	///	\brief Function to detect intersection with another CollisionVolume
	///
	///	\param col a CollisionVolume reference to test collision on
	///	\return True or False if the CollisionVolumes collide
	/////////////////////////////////////////////////
	virtual bool Intersect(const CollisionVolume& col) const = 0;
	virtual bool Intersect(const CollisionVolumeBSphere& col) const = 0;
	virtual bool Intersect(const CollisionVolumeAABB& col) const = 0;
	virtual bool Intersect(const CollisionVolumeOBB& col) const = 0;
	///@} 
};

#endif