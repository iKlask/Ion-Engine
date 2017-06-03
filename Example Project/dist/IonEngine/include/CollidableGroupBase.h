#ifndef COLLIDABLEGROUPBASE_H
#define COLLIDABLEGROUPBASE_H

#include "SceneManager.h"
//#include "CollisionGroupDeleteCommand.h"


class CollidableGroupBase
{
public:
	CollidableGroupBase() {};
	virtual ~CollidableGroupBase() {};
	CollidableGroupBase(const CollidableGroupBase&) = delete;
	CollidableGroupBase& operator=(const  CollidableGroupBase&) = delete;

	virtual void Delete() = 0;
	virtual void UpdateAABB() = 0;
protected:
	//*
	void RegisterCollidableGroup() 
	{
		//SceneManager::RegisterCollDelete(new CollisionGroupDeleteCommand(this));
		///CollidableGroupBroker->Register(new CollisionGroupDeleteCommand(this));
		SceneManager::RegisterColGroup(this);
	}
	//*/
};

#endif COLLIDABLEGROUPBASE_H
