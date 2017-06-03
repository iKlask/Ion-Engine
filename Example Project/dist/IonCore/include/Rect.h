#ifndef RECT_H
#define RECT_H

struct Rect
{
public:
	float x;
	float y;
	float width;
	float height;

	Rect()
		: x(0.0f), y(0.0f), width(0.0f), height(0.0f) {}

	Rect(float _x, float _y, float _w, float _h) 
		: x(_x), y(_y), width(_w), height(_h) {}

	void clear()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->width = 0.0f;
		this->height = 0.0f;
	}
};

#endif // !RECT_H
