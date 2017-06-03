#ifndef COLLISIONREGISTRATIONCOMMAND_H
#define COLLISIONREGISTRATIONCOMMAND_H

#include "CollisionCommandBase.h"
#include "CollidableGroup.h"

template<typename C>
class CollisionRegistrationCommand : public CollisionCommandBase {
private:
	C* ptrCol;
public:
	CollisionRegistrationCommand(C* ptrCollision)
		: ptrCol(ptrCollision)
	{};

	virtual void execute() override
	{
		CollidableGroup<C>::Register(ptrCol);
	}
};
#endif