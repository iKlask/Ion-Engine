#ifndef ALARMABLEMANAGER_H
#define ALARMABLEMANAGER_H

#include <map>
#include "AlarmID.h"
class Alarmable;

class AlarmableManager {
private:
	typedef std::pair<Alarmable*, AlarmID> AlarmValue;
	typedef std::multimap<float, AlarmValue> AlarmStorageMap;
	//typedef std::multimap<float, Alarmable*> AlarmStorageMap;

	AlarmStorageMap Alarmable_Map;
public:
	AlarmableManager() {}
	~AlarmableManager();
	AlarmableManager(const AlarmableManager&) = delete;
	AlarmableManager& operator=(const AlarmableManager&) = delete;

	typedef AlarmStorageMap::iterator AlarmStorageMapRef;

	void Deregister(Alarmable * pAlarm, const AlarmID& aID);
	void ProcessAlarms();
	void Register(const float& tme, Alarmable* pAlarm, const AlarmID& aID);
};

#endif

