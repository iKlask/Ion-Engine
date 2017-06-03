#ifndef DRAWABLEMANAGER_H
#define DRAWABLEMANAGER_H

#include <list>

class Drawable;

class DrawableManager
{
private:
	friend class Scene;

	typedef std::list<Drawable*> DrawStorageList;
	DrawStorageList Drawable_List;

	void ProcessElements();

	void Register(Drawable* input_Drawable);
	void Deregister(Drawable* input_Drawable);

public:
	DrawableManager() {}
	~DrawableManager();
	DrawableManager(const DrawableManager&) = delete;
	DrawableManager& operator=(const  DrawableManager&) = delete;

	typedef DrawStorageList::iterator DrawStorageListRef;
};

#endif
