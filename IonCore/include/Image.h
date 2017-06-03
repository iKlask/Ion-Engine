#ifndef IMAGE_H
#define IMAGE_H

#include "Rect.h"
class Texture;

class Image
{
public:
	Image();
	Image(Texture *pTexture, const Rect& pRect);
	void Set(Texture *pTexture, const Rect& pRect);
	~Image();

public:
	Texture		*pText;
	Rect		pImageRect;


	float getWidth();
	float getHeight();
	float getU();
	float getV();

	Texture* getTexture();
};


#endif