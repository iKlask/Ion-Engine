#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

//#include "IonEngine.h"
#include "FreezeTime.h"


/////////////////////////////////////////////////
/// \class TimeManager
///	\brief System manager for keeping track of time
///
///	The TimeManager is a singleton that keeps track of game time and
///	allows access to the current game time and frame time.
/////////////////////////////////////////////////
class TimeManager {
friend class IonEngine;
private:
	TimeManager();											// Private constructor
	TimeManager(const TimeManager&) = delete;				// Prevent copy-construction
	TimeManager& operator=(const TimeManager&) = delete;	// Prevent assignment
	~TimeManager();											// Only this class can delete

	static TimeManager* ptrInstance;
	static TimeManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new TimeManager;
		return *ptrInstance;
	};

	FreezeTime frzTime;

	float frameTime;
	float frameTimeAverage;
	float prevTime;
	float curTime;
	//static const int AVG_FRAMES = 60;
	//float frameBuffer[AVG_FRAMES];
	int AVG_FRAMES;
	float *frameBuffer;
	unsigned int fbIndex;

	float privGetFrameTime() const;
	float privGetTime() const;
	void privProcessTime(const float& sys_time);
	static float GetFPSAverage();
	static float GetFPS();

	static float GetFrameTimeAverage();


	static void ProcessTime(const float& sys_time) { Instance().privProcessTime(sys_time); };

public:
	/////////////////////////////////////////////////
	///	\brief Function to get current Frame Time
	///
	///	\return Float of current Frame Time.
	/////////////////////////////////////////////////
	static float GetFrameTime() { return Instance().privGetFrameTime(); };

	/////////////////////////////////////////////////
	///	\brief Function to get current Game Time
	///
	///	\return Float of current Game Time.
	/////////////////////////////////////////////////
	static float GetTime() { return Instance().privGetTime(); };

	static void Delete();
};

#endif TIMEMANAGER_H
