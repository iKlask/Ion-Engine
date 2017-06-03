#ifndef Hud_H
#define Hud_H

//#include "IonCore.h"

#include "Drawable.h"
#include "Updatable.h"

#include <vector>
class IonSprite;

class Hud : public Drawable, public Updatable
{
	struct HealthBar {
		IonSprite* sprite_Health;
		bool active;

		HealthBar(IonSprite* sp)
			: sprite_Health(sp), active(true)
		{}
	};

private:
	IonSprite* sprite_HUD;
	IonSprite* sprite_Rot_BODY;
	IonSprite* sprite_Rot_TURRET;
	IonSprite* sprite_Loading;
	IonSprite* sprite_Ready;
	IonSprite* sprite_Wait;

	IonSprite* sprite_Health_Text;

	std::vector<HealthBar> sprite_Healthbar;
	std::vector<HealthBar>::iterator itr_hBar_POS;
	float next_hBar_PosX;
	float next_hBar_PosY;

	IonSprite* sprite_Shell;

	bool bShowWait;

	float* pRot;
public:
	Hud(float * angle);
	virtual ~Hud();
	Hud(const Hud&) = delete;
	Hud& operator=(const Hud&) = delete;

	virtual void Update() override;

	virtual void SceneEntry() override;
	virtual void SceneExit() override;

	virtual void Draw2D() override;

	void SetReload();
	void SetReady();

	void AddHealthBar();
	void SubtractHealth();
	void RemoveHealthBar();
};

#endif Hud_H

