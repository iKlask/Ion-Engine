#ifndef COLLIDABLEMANAGER_H
#define COLLIDABLEMANAGER_H

#include <list>

#include "CollisionTestPairCommand.h"
#include "CollisionTestSelfCommand.h"
#include "CollisionTestTerrainCommand.h"

#include "CommandBase.h"
#include "CollisionCommandBase.h"

//
#include "DebugOut.h"
//


//class CommandBase;
//class CollisionGroupDeleteCommand;

class CollidableManager {
private:
	typedef std::list<CollidableGroupBase*> CollidableGroups;
	CollidableGroups Group_List;

	typedef std::list<CollisionCommandBase*> CollisionTestCommands;
	CollisionTestCommands Command_List;

	typedef std::list<CollisionCommandBase*> CollisionGroupCommands;
	CollisionGroupCommands Delete_Command_List;

public:
	CollidableManager() = default;
	virtual ~CollidableManager() {
		DebugMsg::out("COLLIDABLE MANAGER deleteing CollidableGroups...\n");
		for (CollidableGroups::iterator itr = Group_List.begin(), end = Group_List.end(); itr != end; itr++) {
			(*itr)->Delete();
		}
		DebugMsg::out("COLLIDABLE MANAGER deleteing CollisionTest Commands...\n");
		for (CollisionTestCommands::iterator itr = Command_List.begin(); itr != Command_List.end(); itr++) 
		{
			delete *itr;
		}
		Command_List.clear();
	};
	CollidableManager(const CollidableManager&) = delete;
	CollidableManager& operator=(const  CollidableManager&) = delete;

	void ProcessCollisions() {

		//	Update AABB for each CollidableGroup
		for (CollidableGroups::iterator itr = Group_List.begin(), end = Group_List.end(); itr != end; itr++) {
			(*itr)->UpdateAABB();
		}

		//	Execute Collision Test for all TestCommands
		for (CollisionTestCommands::iterator itr = Command_List.begin(), end = Command_List.end(); itr != end; itr++) {
			(*itr)->execute();
		}
	}

	template <typename C1, typename C2>
	void SetCollisionPair();

	template <typename C>
	void SetCollisionSelf();

	template <typename C>
	void SetCollisionTerrain();

	void InsertDelete(CollisionCommandBase* cmd) {
		//cmd;
		Delete_Command_List.insert(Delete_Command_List.begin(), cmd);
	}

	void InsertGroup(CollidableGroupBase* col) {
		Group_List.insert(Group_List.begin(), col);
	}

};

template<typename C1, typename C2>
inline void CollidableManager::SetCollisionPair()
{
	Command_List.insert(Command_List.begin(), new CollisionTestPairCommand<C1, C2>());
}

template<typename C>
inline void CollidableManager::SetCollisionSelf()
{
	Command_List.insert(Command_List.begin(), new CollisionTestSelfCommand<C>());
}

template<typename C>
inline void CollidableManager::SetCollisionTerrain()
{
	Command_List.insert(Command_List.begin(), new CollisionTestTerrainCommand<C>());
}

#endif

