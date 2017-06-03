#ifndef IONMATHTOOLS_H
#define IONMATHTOOLS_H

class CollisionVolumeBoxBase;

class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;
class CollisionVolume;
class Collidable;
class Vect;
//class Matrix;
#include "Matrix.h"

/////////////////////////////////////////////////
/// \class IonMathTools
///	\brief Static math function class
///
///	IonMathTools is filled with static functions for comonly used math
/// operations.
/////////////////////////////////////////////////

class IonMathTools {
private:
	static bool BoxAxisOverlap(const CollisionVolumeBoxBase& colA, const CollisionVolumeBoxBase& colB, const Vect & axis);
	static float ProjInterval(const CollisionVolumeBoxBase& colA, const Vect& v);

	static float TriangleArea(float x1, float y1, float x2, float y2, float x3, float y3);

public:
	/////////////////////////////////////////////////
	///	\brief Function for Intersection dynamic dispatch 
	///
	///	This intersect function takes in two Collidable pointers
	///	and calls the intersect function of colA on colB.
	///
	///	\param colA first Collidable pointer
	///	\param colB second Collidable pointer
	///
	///	\return bool if the CollisionVolumes intersect
	/////////////////////////////////////////////////
	static bool Intersect(const Collidable* colA, const Collidable* colB);

	/////////////////////////////////////////////////
	///	\brief Function for Intersection of BSphere on BSphere 
	///
	///	This function calculates if the two CollisionVolumeBSphere
	///	refrences colA and colB are intersecting.
	///
	///	\param colA first CollisionVolumeBSphere ref
	///	\param colB second CollisionVolumeBSphere ref
	///
	///	\return bool if the CollisionVolumes intersect
	/////////////////////////////////////////////////
	static bool Intersect(const CollisionVolumeBSphere& colA, const  CollisionVolumeBSphere& colB);
	/////////////////////////////////////////////////
	///	\brief Function for Intersection of AABB on AABB 
	///
	///	This function calculates if the two CollisionVolumeAABB
	///	refrences colA and colB are intersecting.
	///
	///	\param colA first CollisionVolumeAABB ref
	///	\param colB second CollisionVolumeAABB ref
	///
	///	\return bool if the CollisionVolumes intersect
	/////////////////////////////////////////////////
	static bool Intersect(const CollisionVolumeAABB& colA, const CollisionVolumeAABB& colB);
	/////////////////////////////////////////////////
	///	\brief Function for Intersection of OBB on OBB 
	///
	///	This function calculates if the two CollisionVolumeOBB
	///	refrences colA and colB are intersecting.
	///
	///	\param colA first CollisionVolumeOBB ref
	///	\param colB second CollisionVolumeOBB ref
	///
	///	\return bool if the CollisionVolumes intersect
	/////////////////////////////////////////////////
	static bool Intersect(const CollisionVolumeOBB& colA, const CollisionVolumeOBB& colB);

	/////////////////////////////////////////////////
	///	\brief Function for Intersection of AABB on OBB 
	///
	///	This function calculates if the CollisionVolumeAABB
	///	and CollisionVolumeOBB refrences (colA and colB) are intersecting.
	///
	///	\param colA CollisionVolumeAABB ref
	///	\param colB CollisionVolumeOBB ref
	///
	///	\return bool if the CollisionVolumes intersect
	/////////////////////////////////////////////////
	static bool Intersect(const CollisionVolumeAABB& colA, const  CollisionVolumeOBB& colB);
	/////////////////////////////////////////////////
	///	\brief Function for Intersection of BSphere on AABB 
	///
	///	This function calculates if the CollisionVolumeBSphere
	///	and CollisionVolumeAABB refrences (colA and colB) are intersecting.
	///
	///	\param colA CollisionVolumeBSphere ref
	///	\param colB CollisionVolumeAABB ref
	///
	///	\return bool if the CollisionVolumes intersect
	/////////////////////////////////////////////////
	static bool Intersect(const CollisionVolumeBSphere& colA, const  CollisionVolumeAABB& colB);
	/////////////////////////////////////////////////
	///	\brief Function for Intersection of OBB on BSphere 
	///
	///	This function calculates if the CollisionVolumeOBB
	///	and CollisionVolumeBSphere refrences (colA and colB) are intersecting.
	///
	///	\param colA CollisionVolumeOBB ref
	///	\param colB CollisionVolumeBSphere ref
	///
	///	\return bool if the CollisionVolumes intersect
	/////////////////////////////////////////////////
	static bool Intersect(const CollisionVolumeOBB& colA, const CollisionVolumeBSphere& colB);


	/////////////////////////////////////////////////
	///	\brief Function that projects one Vect onto another Vect
	///
	///	This function calculates the projection of v onto w
	///	as follows: |v dot w| / ||w||
	///
	///	\param v first Vect to project
	///	\param w second Vect to project
	///
	///	\return A float of the projected length
	/////////////////////////////////////////////////
	static float Projection(const Vect& v, const Vect& w);

	/////////////////////////////////////////////////
	///	\brief Function that returns the scalar of a Matrix as a Vect 
	///
	///	\param m Matrix to get scale from
	///
	///	\return A scalar Vect
	/////////////////////////////////////////////////
	static Vect GetMatrixScale(const Matrix& m);
	/////////////////////////////////////////////////
	///	\brief Function that returns a squared Vect 
	///
	///	\param v Vect to square
	///
	///	\return A new squared Vect
	/////////////////////////////////////////////////
	static Vect SqrVect(const Vect& v);

	/////////////////////////////////////////////////
	///	\brief Function that returns the min Vect within a Vect array
	///
	///	\param v pointer to Vect array
	///	\param length int length of Vect array
	///
	///	\return The minimum Vect from the array
	/////////////////////////////////////////////////
	static Vect GetMinVect(const Vect* v, int length);
	/////////////////////////////////////////////////
	///	\brief Function that returns the max Vect within a Vect array
	///
	///	\param v pointer to Vect array
	///	\param length int length of Vect array
	///
	///	\return The maximum Vect from the array
	/////////////////////////////////////////////////
	static Vect GetMaxVect(const Vect* v, int length);
	/////////////////////////////////////////////////
	///	\brief Function that returns the min and max Vects within a Vect array
	///
	///	This function takes in two vect references (min_vect and max_vect) for outputing
	///	the min and max Vect values within a Vect array v. The function also will optionally
	///	transform the Vects by a world matrix with param mat. If left blank, no vects will be
	///	transformed as mat defaults to the Identity matrix.
	///
	///	\param v pointer to Vect array
	///	\param length int length of Vect array
	///	\param min_vect	Output Vect reference for min
	///	\param max_vect Output Vect reference for max
	///	\param mat Optional matrix for Vect transformations
	/////////////////////////////////////////////////
	static void GetMinMaxVect(const Vect* v, int length, Vect& min_vect, Vect& max_vect, const Matrix & mat = Matrix(IDENTITY));

	/////////////////////////////////////////////////
	///	\brief Function that returns a clamped float
	///
	///	This function clamps a float f between the min
	///	and max float params
	///
	///	\param f Float to clamp
	///	\param min Min float value
	///	\param max Max float value
	///
	///	\return Float value that has been clamped
	/////////////////////////////////////////////////
	static float fClamp(float f, float min, float max);
	/////////////////////////////////////////////////
	///	\brief Function that returns a clamped Vect
	///
	///	This function clamps a Vect f between the min
	///	and max Vect params
	///
	///	\param v Vect to clamp
	///	\param min Min vect value
	///	\param max Max vect value
	///
	///	\return Vect value that has been clamped
	/////////////////////////////////////////////////
	static Vect vClamp( const Vect& v, const Vect& min, const Vect& max);
	/////////////////////////////////////////////////
	///	\brief Function that calculates the distance formula on two Vects
	///
	///	\param vA Vect position one
	///	\param vB Vect position two
	///
	///	\return Distance of the two points as a float.
	/////////////////////////////////////////////////
	static float vDistance(const Vect& vA, const Vect& vB);

	/////////////////////////////////////////////////
	///	\brief Function that calculates the area of a triangle from three given points
	///
	///	\param v1 Triangle point one
	///	\param v2 Triangle point two
	///	\param v3 Triangle point three
	///
	///	\return float area of the triangle.
	/////////////////////////////////////////////////
	static float TriangleArea(const Vect& v1, const Vect& v2, const Vect& v3);


	/////////////////////////////////////////////////
	///	\brief Function that checks if a 3D point is inside a sphere
	///
	///	\param v Vect point to test
	///	\param center Vect center of sphere
	///	\param radius float radius of sphere
	///
	///	\return True or false if the point is in the sphere.
	/////////////////////////////////////////////////
	static bool InsideSphere(const Vect& v, const Vect& center, float radius);
	/////////////////////////////////////////////////
	///	\brief Function that checks if a 3D point is inside a triangle from three given points
	///
	///	\param T_v1 Triangle point one
	///	\param T_v2 Triangle point two
	///	\param T_v3 Triangle point three
	///	\param pos Vect point to test
	///
	///	\return True or false if the point is in the triangle.
	/////////////////////////////////////////////////
	static bool InsideTriangle(const Vect& T_v1, const Vect& T_v2, const Vect& T_v3, const Vect& pos);
	/////////////////////////////////////////////////
	///	\brief Function that checks if a line is intersects with a triangle from three given points
	///
	///	This function tests for a line intersection point with a triangle.
	///	The function returns an int based on what is calculated:
	///			return -1: Triangle is degenerate
	///			return 0: Line is disjoint from triangle plane
	///			return 1: Line intersects with triangle plane
	///			return 2: Line lies in triangle triangle plane
	///	The function only ever modifies the out_pos Vect ref if it returns 1
	///
	///	\param p1 Line point 1
	///	\param p2 Line point 2
	///	\param T_v1 Triangle point one
	///	\param T_v2 Triangle point two
	///	\param T_v3 Triangle point three
	///	\param out_pos Output Vect ref for point of intersection
	///
	///	\return int based on how successful the test was
	/////////////////////////////////////////////////
	static int LineIntersectTriangle(const Vect& p1, const Vect& p2, const Vect & T_v1, const Vect & T_v2, const Vect & T_v3, Vect& out_pos);

	//returns true if overlapping, false if not
	/////////////////////////////////////////////////
	///	\brief Function that checks if two intervals overlap
	///
	///	\param f1_min first min float
	///	\param f1_max first max float
	///	\param f2_min second min float
	///	\param f2_max second max float
	///
	///	\return True or false if the intervals overlap
	/////////////////////////////////////////////////
	static bool ComputeIntervalOverlap(float f1_min, float f1_max, float f2_min, float f2_max);
};

#endif
