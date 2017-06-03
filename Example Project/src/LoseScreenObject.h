#ifndef LoseScreenObject_H
#define LoseScreenObject_H

#include "Drawable.h"
#include "Inputable.h"

class IonSprite;

class LoseScreenObject : public Drawable, public Inputable
{
private:
	IonSprite* sprite_Screen;

public:
	LoseScreenObject();
	virtual ~LoseScreenObject();
	LoseScreenObject(const LoseScreenObject&) = delete;
	LoseScreenObject& operator=(const LoseScreenObject&) = delete;

	virtual void KeyPressed(const ION_KEY& key_in) override;
	virtual void KeyReleased(const ION_KEY& key_in);


	virtual void SceneEntry() override;
	virtual void SceneExit() override;

	virtual void Draw2D() override;
};

#endif LoseScreenObject_H

