#ifndef Tank_H
#define Tank_H

//#include "IonCore.h"
#include "Updatable.h"
#include "Drawable.h"
#include "Alarmable.h"
#include "Inputable.h"
#include "Collidable.h"
//#include "Align16.h"
#include "MathEngine.h"	//<- lazy

//#include "TextureAssets.h"
//#include "ModelManager.h"
//#include "ShaderAssets.h"
//#include "TimeManager.h"

class Bullet;
class EnemyTank;
class GraphicsObject_Color;
class GraphicsObject_Texture_Light;

class Tank : public Updatable, public Drawable, public Inputable, public Collidable, public Alarmable, public Align16
{
	struct Tank_Data {
		Matrix Scale;
		Matrix Rot;
		Vect Pos;
		float angle;
	};

private:
	Tank_Data Tank_Body_Data;
	Tank_Data Tank_Turret_Data;
	Tank_Data Tank_Barrel_Data;

	Matrix Camera_Rot;
	Vect Camera_Pos;
	Vect Turret_Camera_Offset;

	Vect Bullet_Pos;
	Vect Turret_Bullet_Offset;

	Vect Turret_Barrel_Offset;


	Vect HitColor;
	Vect StartPos;

	GraphicsObject_Texture_Light *pGObj_Tank_Body;
	GraphicsObject_Texture_Light *pGObj_Tank_Turret;
	GraphicsObject_Texture_Light *pGObj_Tank_Barrel;


	//*
	GraphicsObject_Color* pGObj_Axis;
	//*/

	const float Tank_Speed = 75.0f;
	const float Tank_Body_Angle = 0.5f;
	const float Tank_Turret_Angle = 0.75f;
	const float Tank_Barrel_Angle = 0.75f;

	bool bSphereToggle = false;
	bool bCanShoot = true;

	void UpdateWorldMatrices();
	void UpdateTankMovement(ION_KEY key_1, ION_KEY key_2);
	void UpdateTankRotation(ION_KEY key_1, ION_KEY key_2);
	void UpdateTurretRotation(ION_KEY key_1, ION_KEY key_2);
	void UpdateBarrelHeight(ION_KEY key_1, ION_KEY key_2);
public:
	Tank();
	virtual ~Tank();
	Tank& operator=(const Tank&) = delete;

	virtual void SceneEntry() override;
	virtual void SceneExit() override;

	virtual void Update() override;
	virtual void Draw() override;

	virtual void KeyPressed(const ION_KEY& key_in) override;
	virtual void KeyReleased(const ION_KEY& key_in) override;

	virtual void Alarm0() override;
	virtual void Alarm1() override;


	virtual void Collision(Collidable*) {};
	virtual void CollisionTerrain() override;

	virtual void Collision(Bullet*);
	virtual void Collision(EnemyTank*);


	Vect* GetTankPos();
	Vect* GetCamPos();
	Matrix* GetCamRot();

	float* getAngle();
};
#endif
