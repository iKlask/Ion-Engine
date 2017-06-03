#include "BulletFactory.h"
#include "DebugOut.h"

BulletFactory* BulletFactory::ptrInstance = nullptr;

void BulletFactory::privCreateBullet(const Matrix& rot, const Vect& pos)
{
	Bullet* b;

	if (recycledItems.empty())
	{
		b = new Bullet();
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();
	}
	activeItems.push_front(b);
	b->Initialize(rot,pos);
	b->SubmitEntry();
}

void BulletFactory::privCreateBullet(const Matrix & rot, const Vect & pos, const float & speed)
{
	Bullet* b;

	if (recycledItems.empty())
	{
		b = new Bullet();
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();
	}
	activeItems.push_front(b);
	b->Initialize(rot, pos, speed);
	b->SubmitEntry();
}

void BulletFactory::privRecycleBullet(Bullet* bul)
{
	activeItems.remove(bul);
	recycledItems.push(bul);
	DebugMsg::out("Bullet RETURNED: %i active, %i inactive\n", activeItems.size(), recycledItems.size());
}



BulletFactory::~BulletFactory()
{
	DebugMsg::out("USER DESTRUCTOR Bullet Factory\n");
	DebugMsg::out("\tBullets Destroying: %i active, %i inactive\n", activeItems.size(), recycledItems.size());
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}

	while (!activeItems.empty())
	{
		delete activeItems.front();
		activeItems.pop_front();
	}
	DebugMsg::out("\tBullets Destroyed: %i active, %i inactive\n", activeItems.size(), recycledItems.size());
}

void BulletFactory::Delete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

