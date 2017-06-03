#ifndef COLLISIONVOLUMEBOXBASE_H
#define COLLISIONVOLUMEBOXBASE_H

#include "Vect.h"
#include "Matrix.h"

#include "CollisionVolume.h"

class Model;

class CollisionVolumeBoxBase : public CollisionVolume
{
protected:
	Matrix World;	//	Non-Scaled
	Vect Min_Point;
	Vect Max_Point;
	Vect Scale;
	Vect ScaleSqr;
	Vect Center;	//	Local
	Vect Diagonal;
public:
	CollisionVolumeBoxBase();
	virtual ~CollisionVolumeBoxBase() {};
	CollisionVolumeBoxBase(const CollisionVolumeBoxBase&) = delete;
	CollisionVolumeBoxBase& operator=(const CollisionVolumeBoxBase&) = delete;

	const Vect& GetCenter() const;
	const Matrix& GetWorld() const;
	const Vect& GetScale() const;
	const Vect& GetScaleSqr() const;
	const Vect& GetDiag() const;
	const Vect& GetMin() const;
	const Vect& GetMax() const;

	Vect SAxis() const;
	Vect UAxis() const;
	Vect FAxis() const;
};
#endif
