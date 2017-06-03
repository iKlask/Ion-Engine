#ifndef KEYBOARDEVENTMANAGER_H
#define KEYBOARDEVENTMANAGER_H

#include "Keyboard.h"
#include <map>

enum INPUT_EVENT;

class SingleKeyEventManager;
class Inputable;

class KeyboardEventManager {
	friend class Scene;
	//friend class Inputable;
private:
	typedef std::map<ION_KEY, SingleKeyEventManager*> SingleKeyEventMap;
	typedef std::pair<ION_KEY, INPUT_EVENT> KeyEventPair;

	//typedef std::pair<ION_KEY, INPUT_EVENT> KeyEventPair;

	SingleKeyEventMap SingleKeyEvent_Map;

	void ProcessKeyEvents();
	void Register(Inputable* inputable_in, const KeyEventPair& key_pair);
	void Deregister(Inputable* inputable_in, const KeyEventPair& key_pair);
public:
	KeyboardEventManager();
	~KeyboardEventManager();
	KeyboardEventManager(const KeyboardEventManager&) = delete;
	KeyboardEventManager& operator=(const KeyboardEventManager&) = delete;

	typedef SingleKeyEventMap::iterator SingleKeyEventMapRef;
};

#endif
