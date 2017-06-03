#ifndef MainMenuScreen_H
#define MainMenuScreen_H

//#include "IonCore.h"
#include "Drawable.h"
#include "Inputable.h"

class IonSprite;

class MainMenuScreen : public Drawable, public Inputable
{
private:
	IonSprite* sprite_Screen;

public:
	MainMenuScreen();
	virtual ~MainMenuScreen();
	MainMenuScreen(const MainMenuScreen&) = delete;
	MainMenuScreen& operator=(const MainMenuScreen&) = delete;

	virtual void KeyPressed(const ION_KEY& key_in) override;
	virtual void KeyReleased(const ION_KEY& key_in);


	virtual void SceneEntry() override;
	virtual void SceneExit() override;

	virtual void Draw2D() override;
};

#endif MainMenuScreen_H

