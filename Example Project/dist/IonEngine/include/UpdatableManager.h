#ifndef UPDATEABLEMANAGER_H
#define UPDATEABLEMANAGER_H

#include <list>

class Updatable;

class UpdatableManager
{
private:
	friend class Scene;

	typedef std::list<Updatable*> UpdateStorageList;
	UpdateStorageList Updatable_List;

	void ProcessElements();

	void Register(Updatable* input_Updatable);
	void Deregister(Updatable* input_Updatable);

public:
	UpdatableManager() {}
	~UpdatableManager();
	UpdatableManager(const UpdatableManager&) = delete;
	UpdatableManager& operator=(const  UpdatableManager&) = delete;

	typedef UpdateStorageList::iterator UpdateStorageListRef;
};

#endif