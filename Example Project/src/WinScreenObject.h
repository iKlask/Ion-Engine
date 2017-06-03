#ifndef WinScreenObject_H
#define WinScreenObject_H

//#include "IonCore.h"
#include "Drawable.h"
#include "Inputable.h"


class IonSprite;

class WinScreenObject : public Drawable, public Inputable
{
private:
	IonSprite* sprite_Screen;

public:
	WinScreenObject();
	virtual ~WinScreenObject();
	WinScreenObject(const WinScreenObject&) = delete;
	WinScreenObject& operator=(const WinScreenObject&) = delete;

	virtual void KeyPressed(const ION_KEY& key_in) override;
	virtual void KeyReleased(const ION_KEY& key_in);


	virtual void SceneEntry() override;
	virtual void SceneExit() override;

	virtual void Draw2D() override;
};

#endif WinScreenObject_H

