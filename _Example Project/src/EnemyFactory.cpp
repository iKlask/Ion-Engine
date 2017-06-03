#include "EnemyFactory.h"
#include "GameManager.h"
#include "EnemyTank.h"

EnemyFactory* EnemyFactory::ptrInstance = nullptr;

void EnemyFactory::privCreateEnemyTank(const Vect& start_pos, Vect* look_at)
{
	EnemyTank* e;

	if (recycledItems.empty())
	{
		e = new EnemyTank();
	}
	else
	{
		e = recycledItems.top();
		recycledItems.pop();
	}
	activeItems.push_front(e);
	e->Initialize(start_pos, look_at);
	e->SubmitEntry();
	GameManager::AddEnemy();
}

void EnemyFactory::privRecycleEnemyTank(EnemyTank* enemy)
{
	activeItems.remove(enemy);
	recycledItems.push(enemy);
	GameManager::EnemyKilled();
	//DebugMsg::out("Enemy RETURNED: %i active, %i inactive\n", activeItems.size(), recycledItems.size());
}



EnemyFactory::~EnemyFactory()
{
	//DebugMsg::out("\tEnemies Destroying: %i active, %i inactive\n", activeItems.size(), recycledItems.size());
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
	//DebugMsg::out("\tEnemies Destroyed: %i active, %i inactive\n", activeItems.size(), recycledItems.size());
}

void EnemyFactory::Delete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

