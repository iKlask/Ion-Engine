#ifndef INPUTEVENT_H
#define INPUTEVENT_H

/////////////////////////////////////////////////
///	\enum INPUT_EVENT
///	\brief Enum used for specifiying Input event types (Pressed or Released).
/////////////////////////////////////////////////
enum INPUT_EVENT { 
	NO_EVENT,		/*!< Defualt event type that does nothing */
	KEY_PRESSED,	/*!< Event type for key being pressed */
	KEY_RELEASED	/*!< Event type for key being released */
};

#endif