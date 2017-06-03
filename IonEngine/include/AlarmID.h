#ifndef ALARMID_H
#define ALARMID_H

static const int ALARM_COUNT = 3;

/////////////////////////////////////////////////
///	\enum AlarmID
///	\brief Enum used for specifiying Alarm functions
/////////////////////////////////////////////////
enum AlarmID {
	ALARM_0,	/*!< ID for alarm0() function*/
	ALARM_1,	/*!< ID for alarm1() function*/
	ALARM_2		/*!< ID for alarm2() function*/
};

#endif