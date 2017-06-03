#ifndef EnemyTank_H
#define EnemyTank_H

//#include "IonCore.h"
#include "Drawable.h"
#include "Updatable.h"
#include "Collidable.h"
#include "Alarmable.h"
//#include "Align16.h"
//#include "MathEngine.h"	//<-Lazy


class Bullet;
class Tank;
class GraphicsObject_Texture_Light;
class Texture;

class EnemyTank : public Updatable, public Drawable, public Collidable, public Alarmable, public Align16
{
	struct Tank_Data {
		Matrix Scale;
		Matrix Rot;
		Vect Pos;
	};

	enum ROTATE_STATE {
		ROT_LEFT,
		ROT_RIGHT,
		NO_ROT
	};

	enum MOVE_STATE {
		MOVE_FORW,
		MOVE_BACK,
		NO_MOVE
	};

private:
	GraphicsObject_Texture_Light *pGObj_Tank_Body;
	GraphicsObject_Texture_Light *pGObj_Tank_Turret;

	Texture* tex1;
	Texture* tex2;

	Vect* LOOKAT;

	Vect StartPos;
	Vect Bullet_Pos;
	Vect Turret_Bullet_Offset;

	Vect HitColor;

	Tank_Data Tank_Body_Data;
	Tank_Data Tank_Turret_Data;

	const float Tank_Speed = 50.0f;
	const float Tank_Body_Angle = 0.5f;
	const float Tank_Turret_Angle = 1.25f;

	bool bSphereToggle = false;

	int Health;

	ROTATE_STATE cur_rot_state = ROTATE_STATE::NO_ROT;
	MOVE_STATE cur_move_state = MOVE_STATE::NO_MOVE;
	void UpdateWorldMatrices();
	void UpdateTankMovement();

public:
	EnemyTank();
	//EnemyTank(const Vect& start_pos, Vect* look_at);
	virtual ~EnemyTank();
	EnemyTank& operator=(const EnemyTank&) = delete;

	void Initialize(const Vect& start_pos, Vect* look_at);

	virtual void SceneEntry() override;
	virtual void SceneExit() override;

	virtual void Update() override;
	virtual void Draw() override;

	virtual void Alarm0() override;
	virtual void Alarm1() override;
	virtual void Alarm2() override;

	virtual void Collision(Collidable*) {};
	virtual void Collision(Bullet*);
	virtual void Collision(Tank*);


	Vect* GetTankPos();
};
#endif
