#ifndef IONSPRITE_H
#define IONSPRITE_H

#include "Matrix.h"

class ShaderBase;
class Model;
class Image;
class GraphicsObject_Sprite;


/////////////////////////////////////////////////
/// \class IonSprite
///	\brief Sprite class for making and rendering 2D sprites
///
///	The IonSprite Object allows users to implement 2D sprites.
///	When IonSprite's are created they are given an Image to render
/// (which can be loaded in LoadResources.cpp).
///
/// NOTE: The IonSprite Render() function will need to be called in
/// the Draw2D() function of a Drawable class.
/////////////////////////////////////////////////
class IonSprite : public Align16
{
private:
	GraphicsObject_Sprite* pGObject_Sprite;
	ShaderBase* pShader_Sprite;
	Model* pModel_Sprite;

	Matrix world;
	Matrix RotZ;
	Matrix RotCenter;
	Matrix Scale;
	Matrix Trans;

	float SpritePosX;
	float SpritePosY;

	float SpriteCenterX;
	float SpriteCenterY;

	float SpriteWidth;
	float SpriteHeight;

	float SpriteAngle;

public:

	IonSprite() = delete;

	/////////////////////////////////////////////////
	///	\brief The IonSprite constructor takes in an Image pointer for it's sprite.
	///
	///	For creating Images, see the ImageManager::Load() and ImageManager::Get() 
	///	functions. Images can be loaded into the LoadResources.cpp for access later when constructing
	/// an IonSprite.
	///
	/// \param input_image An Image pointer to reference for this sprite.
	/////////////////////////////////////////////////
	IonSprite(Image* input_image);

	~IonSprite();
	IonSprite(const IonSprite&) = delete;
	IonSprite& operator=(const IonSprite&) = delete;

	/////////////////////////////////////////////////
	///	\brief Function that sets the rotation angle of the sprite
	///
	/// \param angle A float in RADIANS for setting the angle.
	/////////////////////////////////////////////////
	void SetAngle(const float& angle);

	/////////////////////////////////////////////////
	///	\brief Function that sets the scale of the sprite's width and height
	///
	/// \param scale_width A float for scaling the width.
	///
	/// \param scale_height A float for scaling the height
	/////////////////////////////////////////////////
	void SetScale(const float& scale_width, const float& scale_height);

	/////////////////////////////////////////////////
	///	\brief Function that sets the position of the sprite on the screen.
	///
	/// \param x_cord A float for the X coordinate position on the screen.
	///
	/// \param y_cord A float for the Y coordinate position on the screen.
	/////////////////////////////////////////////////
	void SetPosition(const float& x_cord, const float& y_cord);

	/////////////////////////////////////////////////
	///	\brief Function that sets the center position of the sprite.
	///
	///	The center of the sprite is locally defined as 0,0. This function will offset
	/// the X coord and Y coord of the center by a desired amount. This allows for rotation
	/// around a different coordinate.
	///
	/// \param x_cord_offset A float offset for the X coordinate center position.
	///
	/// \param y_cord_offset A float offset for the Y coordinate center position.
	/////////////////////////////////////////////////
	void SetCenter(const float& x_cord_offset, const float& y_cord_offset);

	/////////////////////////////////////////////////
	///	\brief Function that renders the Sprite to the 2D camera
	/////////////////////////////////////////////////
	void Render();

	/////////////////////////////////////////////////
	///	\brief Function that get's the sprite's angle of rotation.
	///
	/// \return Float of the sprite's current angle in RADIANS.
	/////////////////////////////////////////////////
	float getAngle();
};

#endif IONSPRITE_H