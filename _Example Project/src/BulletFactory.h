#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include <stack>
#include <list>
#include "Bullet.h"

class BulletFactory
{
private:
	static BulletFactory* ptrInstance;
	std::stack<Bullet*> recycledItems;
	std::list<Bullet*> activeItems;

	BulletFactory() = default;									// Private constructor
	BulletFactory(const BulletFactory&) = delete;				// Prevent copy-construction
	BulletFactory& operator=(const BulletFactory&) = delete;	// Prevent assignment
	~BulletFactory();											// Only this class can delete

	void privCreateBullet(const Matrix& rot, const Vect& pos);
	void privCreateBullet(const Matrix& rot, const Vect& pos, const float& speed);

	void privRecycleBullet(Bullet* bul);

	static BulletFactory& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new BulletFactory;
		return *ptrInstance;
	};

public:
	static void CreateBullet(const Matrix& rot, const Vect& pos) { Instance().privCreateBullet(rot, pos); };
	static void CreateBullet(const Matrix& rot, const Vect& pos, const float& speed) { Instance().privCreateBullet(rot, pos, speed); };

	static void RecycleBullet(Bullet* bul) { Instance().privRecycleBullet(bul); };

	static void Delete();
};


#endif