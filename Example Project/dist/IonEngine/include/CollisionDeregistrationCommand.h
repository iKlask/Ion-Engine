#ifndef COLLISIONDEREGISTRATIONCOMMAND_H
#define COLLISIONDEREGISTRATIONCOMMAND_H

#include "CollisionCommandBase.h"
#include "CollidableGroup.h"

template<typename C>
class CollisionDeregistrationCommand : public CollisionCommandBase {
private:
	C* ptrCol;
public:
	CollisionDeregistrationCommand(C* ptrCollision)
		: ptrCol(ptrCollision)
	{};

	virtual void execute() override
	{
		CollidableGroup<C>::Deregister(ptrCol);
	}
};
#endif