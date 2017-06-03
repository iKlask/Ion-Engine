#include "Hud.h"
#include "IonSprite.h"
#include "ImageAssets.h"
//#include "Ion Engine\TimeManager.h"

Hud::Hud(float * angle)
{
	bShowWait = false;

	pRot = angle;
	//*
	sprite_HUD = new IonSprite(ImageAssets::Get("TankHudImage"));
	sprite_HUD->SetAngle(0);
	sprite_HUD->SetScale(1, 1);
	sprite_HUD->SetPosition(660, 360);
	sprite_HUD->SetCenter(0, 0);
	//*/

	sprite_Rot_BODY = new IonSprite(ImageAssets::Get("TankHudRotBODYImage"));
	sprite_Rot_BODY->SetAngle(0);
	sprite_Rot_BODY->SetScale(1, 1);
	sprite_Rot_BODY->SetPosition(805, 175);
	sprite_Rot_BODY->SetCenter(0, 0);

	sprite_Rot_TURRET = new IonSprite(ImageAssets::Get("TankHudRotTURRETImage"));
	sprite_Rot_TURRET->SetAngle(0);
	sprite_Rot_TURRET->SetScale(1, 1);
	sprite_Rot_TURRET->SetPosition(805, 175);
	sprite_Rot_TURRET->SetCenter(0, 0);

	sprite_Loading = new IonSprite(ImageAssets::Get("ShellLoadingImage"));
	sprite_Loading->SetAngle(0);
	sprite_Loading->SetScale(1, 1);
	sprite_Loading->SetPosition(610, 185);
	sprite_Loading->SetCenter(0, 0);

	sprite_Ready = new IonSprite(ImageAssets::Get("ShellReadyImage"));
	sprite_Ready->SetAngle(0);
	sprite_Ready->SetScale(1, 1);
	sprite_Ready->SetPosition(610, 185);
	sprite_Ready->SetCenter(0, 0);

	sprite_Wait = new IonSprite(ImageAssets::Get("ShellWaitImage"));
	sprite_Wait->SetAngle(0);
	sprite_Wait->SetScale(1, 1);
	sprite_Wait->SetPosition(725, 191);
	sprite_Wait->SetCenter(0, 0);

	sprite_Health_Text = new IonSprite(ImageAssets::Get("HealthTextImage"));
	sprite_Health_Text->SetAngle(0);
	sprite_Health_Text->SetScale(1, 1);
	sprite_Health_Text->SetPosition(100, 100);
	sprite_Health_Text->SetCenter(0, 0);

	next_hBar_PosX = 75;
	next_hBar_PosY = 65;
	itr_hBar_POS = sprite_Healthbar.begin();

	sprite_Shell = sprite_Ready;

	Drawable::Register();
	Updatable::Register();
}

Hud::~Hud()
{
	delete sprite_HUD;
	delete sprite_Rot_BODY;
	delete sprite_Rot_TURRET;
	delete sprite_Loading;
	delete sprite_Ready;
	delete sprite_Health_Text;
}

void Hud::Update()
{
	sprite_Rot_BODY->SetAngle(((*pRot)));
}

void Hud::SceneEntry()
{
	//empty
}

void Hud::SceneExit()
{
	Drawable::Deregister();
	Updatable::Deregister();
}

void Hud::Draw2D()
{
	sprite_Rot_TURRET->Render();
	sprite_Rot_BODY->Render();
	sprite_Shell->Render();
	sprite_Health_Text->Render();
	if (bShowWait) {
		sprite_Wait->Render();
	}

	for (HealthBar it : sprite_Healthbar) {
		it.sprite_Health->Render();
	}
	sprite_HUD->Render();
}

void Hud::SetReload()
{
	bShowWait = true;
	sprite_Shell = sprite_Loading;
	//
}

void Hud::SetReady()
{
	sprite_Shell = sprite_Ready;
	bShowWait = false;
	//
}

void Hud::AddHealthBar()
{
	sprite_Healthbar.emplace_back(HealthBar(new IonSprite(ImageAssets::Get("HealthBarFULLImage"))));
	sprite_Healthbar.back().sprite_Health->SetAngle(0);
	sprite_Healthbar.back().sprite_Health->SetScale(1, 1);
	sprite_Healthbar.back().sprite_Health->SetPosition(next_hBar_PosX, next_hBar_PosY);
	sprite_Healthbar.back().sprite_Health->SetCenter(0, 0);

	sprite_Healthbar.back().active = true;
	next_hBar_PosX += 17;
}

void Hud::SubtractHealth()
{
}

void Hud::RemoveHealthBar()
{
	HealthBar* temp = &sprite_Healthbar.back();
	sprite_Healthbar.pop_back();
	delete temp->sprite_Health;

	next_hBar_PosX -= 17;
}
