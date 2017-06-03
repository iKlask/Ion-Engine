#ifndef EnemyFactory_H
#define EnemyFactory_H

#include <stack>
#include <list>
class Vect;
//#include "EnemyTank.h"
class EnemyTank;

class EnemyFactory
{
private:
	static EnemyFactory* ptrInstance;

	std::stack<EnemyTank*> recycledItems;
	std::list<EnemyTank*> activeItems;

	EnemyFactory() = default;									// Private constructor
	EnemyFactory(const EnemyFactory&) = delete;				// Prevent copy-construction
	EnemyFactory& operator=(const EnemyFactory&) = delete;	// Prevent assignment
	~EnemyFactory();											// Only this class can delete

	void privCreateEnemyTank(const Vect& start_pos, Vect* look_at);

	void privRecycleEnemyTank(EnemyTank* enemy);

	static EnemyFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new EnemyFactory;
		return *ptrInstance;
	};

public:
	static void CreateEnemyTank(const Vect& start_pos, Vect* look_at) { Instance().privCreateEnemyTank(start_pos, look_at); };

	static void RecycleEnemyTank(EnemyTank* enemy) { Instance().privRecycleEnemyTank(enemy); };

	static void Delete();
};


#endif