#ifndef KEYBOARD_H
#define KEYBOARD_H

enum ION_KEY
{
	KEY_SPACE = 0x20,	//VK_SPACE

	KEY_0 = 0x30,
	KEY_1 = 0x31,
	KEY_2 = 0x32,
	KEY_3 = 0x33,
	KEY_4 = 0x34,
	KEY_5 = 0x35,
	KEY_6 = 0x36,
	KEY_7 = 0x37,
	KEY_8 = 0x38,
	KEY_9 = 0x39,

	KEY_A = 0x41,
	KEY_B = 0x42,
	KEY_C = 0x43,
	KEY_D = 0x44,
	KEY_E = 0x45,
	KEY_F = 0x46,
	KEY_G = 0x47,
	KEY_H = 0x48,
	KEY_I = 0x49,
	KEY_J = 0x4A,
	KEY_K = 0x4B,
	KEY_L = 0x4C,
	KEY_M = 0x4D,
	KEY_N = 0x4E,
	KEY_O = 0x4F,
	KEY_P = 0x50,
	KEY_Q = 0x51,
	KEY_R = 0x52,
	KEY_S = 0x53,
	KEY_T = 0x54,
	KEY_U = 0x55,
	KEY_V = 0x56,
	KEY_W = 0x57,
	KEY_X = 0x58,
	KEY_Y = 0x59,
	KEY_Z = 0X5A,

	KEY_SEMICOLON = 0xBA,	//VK_OEM_1 ; and :
	KEY_EQUAL = 0xBB,		//VK_OEM_PLUS + and =
	KEY_COMMA = 0xBC,		//VK_OEM_COMMA , and <
	KEY_MINUS = 0xBD,		//VK_OEM_MINUS - and _
	KEY_PERIOD = 0xBE,		//VK_OEM_PERIOD . and >
	KEY_SLASH = 0xBF,		//VK_OEM_2 / and ?

	KEY_GRAVE_ACCENT = 0xC0,	//VK_OEM_3 ` and ~

	KEY_LEFT_BRACKET = 0xDB,	//VK_OEM_4 [ and {
	KEY_BACKSLASH = 0xDC,		//VK_OEM_5 \ and |
	KEY_RIGHT_BRACKET = 0xDD,	//VK_OEM_6 ] and }
	KEY_APOSTROPHE = 0xDE,		//VK_OEM_7 ' and "
	
	//KEY_WORLD_1 = VK_OEM_8,	//	?
	//KEY_WORLD_2 = 162,		//	?

	KEY_BACKSPACE = 0x08,		//VK_BACK
	KEY_TAB = 0x09,				//VK_TAB
	KEY_ENTER = 0x0D,			//VK_RETURN

	KEY_MENU = 0x12,			//VK_MENU
	KEY_PAUSE = 0x13,			//VK_PAUSE
	KEY_CAPS_LOCK = 0x14,		//VK_CAPITAL
	KEY_ESCAPE = 0x1B,			//VK_ESCAPE

	KEY_PAGE_UP = 0x21,			//VK_PRIOR
	KEY_PAGE_DOWN = 0x22,		//VK_NEXT
	KEY_END = 0x23,				//VK_END
	KEY_HOME = 0x24,			//VK_HOME
	KEY_ARROW_LEFT = 0x25,		//VK_LEFT
	KEY_ARROW_UP = 0x26,		//VK_UP
	KEY_ARROW_RIGHT = 0x27,		//VK_RIGHT
	KEY_ARROW_DOWN = 0x28,		//VK_DOWN
	KEY_PRINT_SCREEN = 0x2C,	//VK_SNAPSHOT
	KEY_INSERT = 0x2D,			//VK_INSERT
	KEY_DELETE = 0x2E,			//VK_DELETE

	KEY_KP_0 = 0x60,			//VK_NUMPAD0
	KEY_KP_1 = 0x61,			//VK_NUMPAD1
	KEY_KP_2 = 0x62,			//VK_NUMPAD2
	KEY_KP_3 = 0x63,			//VK_NUMPAD3
	KEY_KP_4 = 0x64,			//VK_NUMPAD4
	KEY_KP_5 = 0x65,			//VK_NUMPAD5
	KEY_KP_6 = 0x66,			//VK_NUMPAD6
	KEY_KP_7 = 0x67,			//VK_NUMPAD7
	KEY_KP_8 = 0x68,			//VK_NUMPAD8
	KEY_KP_9 = 0x69,			//VK_NUMPAD9
	KEY_KP_MULTIPLY = 0x6A,		//VK_MULTIPLY
	KEY_KP_ADD = 0x6B,			//VK_ADD
	KEY_KP_ENTER = 0x6C,		//VK_SEPARATOR		//	?
	KEY_KP_SUBTRACT = 0x6D,		//VK_SUBTRACT
	KEY_KP_DECIMAL = 0x6E,		//VK_DECIMAL
	KEY_KP_DIVIDE = 0x6F,		//VK_DIVIDE
	//KEY_KP_EQUAL = GLFW_KEY_KP_EQUAL,	//	?

	KEY_F1	= 0x70,		//VK_F1
	KEY_F2	= 0x71,		//VK_F2
	KEY_F3	= 0x72,		//VK_F3
	KEY_F4	= 0x73,		//VK_F4
	KEY_F5	= 0x74,		//VK_F5
	KEY_F6	= 0x75,		//VK_F6
	KEY_F7	= 0x76,		//VK_F7
	KEY_F8	= 0x77,		//VK_F8
	KEY_F9	= 0x78,		//VK_F9
	KEY_F10 = 0x79,		//VK_F10
	KEY_F11 = 0x7A,		//VK_F11
	KEY_F12 = 0x7B,		//VK_F12
	KEY_F13 = 0x7C,		//VK_F13
	KEY_F14 = 0x7D,		//VK_F14
	KEY_F15 = 0x7E,		//VK_F15
	KEY_F16 = 0x7F,		//VK_F16
	KEY_F17 = 0x80,		//VK_F17
	KEY_F18 = 0x81,		//VK_F18
	KEY_F19 = 0x82,		//VK_F19
	KEY_F20 = 0x83,		//VK_F20
	KEY_F21 = 0x84,		//VK_F21
	KEY_F22 = 0x85,		//VK_F22
	KEY_F23 = 0x86,		//VK_F23
	KEY_F24 = 0x87,		//VK_F24

	KEY_NUM_LOCK = 0x90,		//VK_NUMLOCK
	KEY_SCROLL_LOCK = 0x91,		//VK_SCROLL

	KEY_LEFT_SHIFT = 0xA0,		//VK_LSHIFT
	KEY_LEFT_CONTROL = 0xA2,	//VK_LCONTROL
	KEY_LEFT_ALT = 0xA4,		//VK_LMENU
	KEY_LEFT_SUPER = 0x5B,		//VK_LWIN

	KEY_RIGHT_SHIFT = 0xA1,		//VK_RSHIFT,
	KEY_RIGHT_CONTROL = 0xA3,	//VK_RCONTROL,
	KEY_RIGHT_ALT = 0xA5,		//VK_RMENU,
	KEY_RIGHT_SUPER = 0x5C,		//VK_RWIN
};

class Keyboard
{
private:
	static Keyboard* ptrInstance;

	Keyboard() = default;										// Private constructor
	Keyboard(const Keyboard&) = delete;							// Prevent copy-construction
	Keyboard& operator=(const Keyboard&) = delete;				// Prevent assignment
	~Keyboard() = default;										// Private Destructor

	static Keyboard& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Keyboard;
		return *ptrInstance;
	};

public:
	// Use this to read keyboard
	static bool GetKeyState(ION_KEY key);
	static void Delete();
};


#endif