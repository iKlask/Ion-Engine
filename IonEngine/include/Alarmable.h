#ifndef ALARMABLE_H
#define ALARMABLE_H

#include "GameObject.h"
#include "AlarmID.h"
//#include <map>


/////////////////////////////////////////////////
///	\ingroup ALARM-EVENTS
/// \class Alarmable
///
///	\brief A virtual derived class of GameObject that allows the GameObject to set alarms.
///
///	A class that inherits from Alarmable gains access to the Alarm functions. 
/// These allow the user to execute code after a set delay. Each alarmable derived class can have up to
/// three defined alarms: Alarm0(), Alarm1(), and Alarm2().
/////////////////////////////////////////////////
class Alarmable : public virtual GameObject
{
	friend class AlarmableManager;
	friend class AlarmRegistrationCommand;
	friend class AlarmDeregistrationCommand;
private:

	typedef std::pair<Alarmable*, AlarmID> AlarmValue;
	typedef std::multimap<float, AlarmValue> AlarmStorageMapRef;

	struct RegistrationData {
		AlarmStorageMapRef::iterator pDeleteRef;
		RegistrationState curr_RegState;
		AlarmRegistrationCommand* pRegCmd;
		AlarmDeregistrationCommand* pDeregCmd;
	};

	RegistrationData RegData[ALARM_COUNT];

	void AlarmRegistration(const float& tme, const AlarmID& aID);
	void AlarmDeregistration(const AlarmID& aID);

	void SubmitAlarmRegistration(const float& tme, const AlarmID& aID);
	void SubmitAlarmDeregistration(const AlarmID& aID);

	void TriggerAlarm(const AlarmID& aID);
protected:
	///@{ 
	/////////////////////////////////////////////////
	///	\brief Function which is called if set by the user.
	///
	///	This is a virtual function to be overriden by the user.
	///	If the specified alarm is set, the Alarm() function will be called
	///	by the AlarmableManager after the set time runs out. The alarm
	/// can be set by using the SetAlarm() and StopAlarm() functions.
	/////////////////////////////////////////////////
	virtual void Alarm0() {};
	virtual void Alarm1() {};
	virtual void Alarm2() {};
	///@} 

	/////////////////////////////////////////////////
	///	\brief Function to register when a specified alarm is to be triggered.
	///
	///	When the SetAlarm() function is called, a float for number of seconds and
	/// an AlarmID reference is passed. The seconds parameter determines how many seconds from
	///	the current time that the alarm function be called. The aID parameter specifies which alarm
	///	function should be called. The AlarmID enum is mapped to the alarm functions like so:
	///		- Alarm0(): AlarmID::ALARM_0
	///		- Alarm1(): AlarmID::ALARM_1
	///		- Alarm2(): AlarmID::ALARM_2
	///	
	///	\param seconds The number of seconds the alarm is to be set for (starting at the current time).
	///
	///	\param aID The ID to specify which alarm to set.
	/////////////////////////////////////////////////
	void SetAlarm(const float& seconds, const AlarmID& aID);

	/////////////////////////////////////////////////
	///	\brief Function to deregister specified alarm from being triggered.
	///
	///	The StopAlarm() function will end the countdown ofa specified function,
	///	thus stopping the alarm function from being triggered if it is currently registered.
	/// The aID parameter specifies which alarm function should be called. The AlarmID enum is mapped to the alarm functions like so:
	///		- Alarm0(): AlarmID::ALARM_0
	///		- Alarm1(): AlarmID::ALARM_1
	///		- Alarm2(): AlarmID::ALARM_2
	///	
	///	\param aID The ID to specify which alarm to stop.
	/////////////////////////////////////////////////
	void StopAlarm(const AlarmID& aID);


	bool IsActive(const AlarmID& aID);

	const RegistrationState& GetRegState(const AlarmID& aID);
public:
	Alarmable();
	virtual ~Alarmable();
	Alarmable(const Alarmable&) = delete;
	Alarmable& operator=(const  Alarmable&) = delete;
};

#endif ALARMABLE_H