#ifndef COLLISIONCOMMANDBASE_H
#define COLLISIONCOMMANDBASE_H

#include "CommandBase.h"

class CollisionCommandBase : public CommandBase
{
public:
	CollisionCommandBase() {};
	~CollisionCommandBase() {};
	CollisionCommandBase(const CollisionCommandBase&) = delete;
	CollisionCommandBase& operator=(const  CollisionCommandBase&) = delete;

	virtual void execute() {};
};

#endif
