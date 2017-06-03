#ifndef MOUSE_H
#define MOUSE_H

enum ION_MOUSE
{
	/*
	BUTTON_1 = 0,
	BUTTON_2 = 1,
	BUTTON_3 = 2,
	BUTTON_4 = 3,
	BUTTON_5 = 4,
	BUTTON_6 = 5,
	BUTTON_7 = 6,
	BUTTON_8 = 7,
	//*/
	BUTTON_LEFT = 0x01,		//VK_LBUTTON
	BUTTON_RIGHT = 0x02,	//VK_RBUTTON
	BUTTON_MIDDLE = 0x04	//VK_MBUTTON
};

class Mouse
{
	friend class WindowRenderer;
private:
	static Mouse* ptrInstance;

	Mouse();												// Private constructor
	Mouse(const Mouse&) = delete;							// Prevent copy-construction
	Mouse& operator=(const Mouse&) = delete;				// Prevent assignment
	~Mouse() = default;										// Private Destructor

	static Mouse& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new Mouse;
		return *ptrInstance;
	};

	int x_pos;
	int y_pos;
	short wheelDelta;

	static void UpdateCursor(int xPos, int yPos);
public:
	static bool GetKeyState(ION_MOUSE button);
	static void GetCursor(int &xPos, int &yPos);

	static int GetCursorX() { return Instance().x_pos; };
	static int GetCursorY() { return Instance().y_pos; };

	static void Delete();
};

#endif