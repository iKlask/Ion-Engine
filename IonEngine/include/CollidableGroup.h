#ifndef COLLIDABLEGROUP_H
#define COLLIDABLEGROUP_H

#include <set>
#include "CollidableGroupBase.h"

#include "CollisionVolumeAABB.h"
#include "CollisionVolumeBSphere.h"

//#include "Scene.h"
//class CollisionVolumeAABB;

template<typename C>
class CollidableGroup : CollidableGroupBase
{
public:
	typedef std::set<C*> CollidableCollection;
private:
	CollidableCollection Collide_List;

	static CollidableGroup* ptrInstance;

	CollidableGroup() {
		AABB = new CollisionVolumeAABB();

		this->RegisterCollidableGroup();
	}
	virtual ~CollidableGroup() 
	{
		DebugMsg::out("\tDeleting CollidableGroup...\n");
		delete AABB;
	};
	CollidableGroup(const CollidableGroup&) = delete;
	CollidableGroup& operator=(const  CollidableGroup&) = delete;

	static CollidableGroup& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new CollidableGroup;
		return *ptrInstance;
	};

	CollisionVolumeAABB* AABB;
	void privUpdateAABB();
	const CollisionVolumeAABB& privGetAABB() 
	{
		return *AABB;
	}

	const CollidableCollection& privGetColliderCollection()
	{
		return Collide_List;
	};

	void privRegister(C* ptrCollision);
	void privDeregister(C* ptrCollision);
	void privDelete();

public:
	static void Register(C* ptrCollision) { Instance().privRegister(ptrCollision); };
	static void Deregister(C* ptrCollision) { Instance().privDeregister(ptrCollision); };
	static const CollidableCollection& GetColliderCollection() { return Instance().privGetColliderCollection(); };
	static const CollisionVolumeAABB& GetAABB() { return Instance().privGetAABB(); }

	//	Overloaded Functions
	virtual void UpdateAABB() { Instance().privUpdateAABB(); };
	virtual void Delete() { Instance().privDelete(); }
};

template<typename C>
CollidableGroup<C>* CollidableGroup<C>::ptrInstance = nullptr;

template<typename C>
inline void CollidableGroup<C>::privUpdateAABB()
{
	auto it = Collide_List.begin();

	if (it != Collide_List.end()) {
		Vect min = (*it)->GetDefualtBSphere().GetMin();
		Vect max = (*it)->GetDefualtBSphere().GetMax();

		for (it; it != Collide_List.end(); it++)
		{
			//*
			Vect temp_min = (*it)->GetDefualtBSphere().GetMin();
			Vect temp_max = (*it)->GetDefualtBSphere().GetMax();

			if (temp_max[X] > max[X]) { max[X] = temp_max[X]; }
			if (temp_max[Y] > max[Y]) { max[Y] = temp_max[Y]; }
			if (temp_max[Z] > max[Z]) { max[Z] = temp_max[Z]; }

			if (temp_min[X] < min[X]) { min[X] = temp_min[X]; }
			if (temp_min[Y] < min[Y]) { min[Y] = temp_min[Y]; }
			if (temp_min[Z] < min[Z]) { min[Z] = temp_min[Z]; }
			//*/
		}
		AABB->ComputeData(min, max);
	}
}

template<typename C>
inline void CollidableGroup<C>::privRegister(C * ptrCollision)
{
	Collide_List.insert(ptrCollision);
}

template<typename C>
inline void CollidableGroup<C>::privDeregister(C * ptrCollision)
{
	//Non Constant Removal
	CollidableCollection::iterator itr = Collide_List.find(ptrCollision);
	assert(itr != Collide_List.end() && "Cannot Deregister, Collide_List does not contain this collidable");
	if (itr != Collide_List.end()) {
		Collide_List.erase(itr);
	}
}

template<typename C>
inline void CollidableGroup<C>::privDelete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

#endif
