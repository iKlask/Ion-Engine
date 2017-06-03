// FreezeTime
// Andre Berthiaume, Jan 2016

#ifndef _FreezeTime
#define _FreezeTime

//#include "IonEngineCore.h"
#include "Keyboard.h"

class FreezeTime
{
private:
	static const ION_KEY FREEZE_KEY = ION_KEY::KEY_F10;
	static const ION_KEY SINGLE_FRAME_KEY = ION_KEY::KEY_F9;

	float totalFrozenTime;
	bool freeze_mode_active;

	float WaitAndReturnFrozenTime(float activetime);
	bool HackedKeyRelease(ION_KEY k);

public:
	FreezeTime();
	~FreezeTime(){};
	FreezeTime(const FreezeTime&) = delete;
	FreezeTime& operator=(const FreezeTime&) = delete;

	float GetTimeInSeconds(float sys_time);
};

#endif _FreezeTime