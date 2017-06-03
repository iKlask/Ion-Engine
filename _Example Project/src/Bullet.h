#ifndef BULLET_H
#define BULLET_H

//#include "IonCore.h"

#include "Updatable.h"
#include "Drawable.h"
#include "Alarmable.h"
#include "Collidable.h"

//#include "IonEngineCore.h"

//#include "MathEngine.h"



class Tank;
class EnemyTank;
class GraphicsObject_Texture_Light;

class Bullet : public Updatable, public Drawable, public Alarmable, public Collidable , public Align16
{
private:
	//GraphicsObject_WireframeColor *pGObj_WireFrame_Ball;
	GraphicsObject_Texture_Light *pGObj_WireFrame_Ball;
	Matrix BulletScale;
	Matrix WorldRot;
	Matrix WorldPos;

	Vect BulletPos;

	float height;
	float BulletTransSpeed;
	float bulletLifeTime;

	bool bSphereToggle = false;
public:
	Bullet();
	virtual ~Bullet();
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = delete;

	void Initialize(const Matrix& rot, const Vect& pos);
	void Initialize(const Matrix& rot, const Vect& pos, const float& speed);


	virtual void SceneEntry() override;
	virtual void SceneExit() override;

	virtual void Update() override;

	virtual void Draw() override;

	virtual void Alarm0() override;

	virtual void CollisionTerrain() override;

	virtual void Collision(Collidable*);
	virtual void Collision(Tank*);
	virtual void Collision(EnemyTank*);
	virtual void Collision(Bullet*);


};

#endif