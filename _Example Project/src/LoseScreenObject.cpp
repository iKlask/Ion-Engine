#include "LoseScreenObject.h"
#include "IonSprite.h"
#include "ImageAssets.h"
#include "GameManager.h"


LoseScreenObject::LoseScreenObject()
{
	sprite_Screen = new IonSprite(ImageAssets::Get("LoseScreenImage"));
	sprite_Screen->SetAngle(0);
	sprite_Screen->SetScale(1, 1);
	sprite_Screen->SetPosition(660, 360);
	sprite_Screen->SetCenter(0, 0);

	Drawable::Register();
	Inputable::RegisterKey(ION_KEY::KEY_ENTER, INPUT_EVENT::KEY_PRESSED);
}

LoseScreenObject::~LoseScreenObject()
{
	delete sprite_Screen;
}

void LoseScreenObject::KeyPressed(const ION_KEY & key_in)
{
	switch (key_in) {
	case ION_KEY::KEY_ENTER:
		GameManager::LevelOneSceneChange();
		break;
	}
}

void LoseScreenObject::KeyReleased(const ION_KEY & key_in)
{
	key_in;
}

void LoseScreenObject::SceneEntry()
{
	//empty
}

void LoseScreenObject::SceneExit()
{
	Drawable::Deregister();
	Inputable::DeregisterKey(ION_KEY::KEY_ENTER, INPUT_EVENT::KEY_PRESSED);
}

void LoseScreenObject::Draw2D()
{
	sprite_Screen->Render();
}
