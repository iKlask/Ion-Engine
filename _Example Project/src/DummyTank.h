#ifndef DummyTank_H
#define DummyTank_H

//#include "IonCore.h"

#include "Drawable.h"
#include "Updatable.h"
#include "Collidable.h"

#include "Align16.h"

class Tank;
class GraphicsObject_Texture_Light;

class DummyTank : public Drawable, public Collidable, public Updatable, public Align16
{
	struct Tank_Data {
		Matrix Scale;
		Matrix Rot;
		Vect Pos;
		float angle;
	};

private:
	GraphicsObject_Texture_Light *pGObj_Tank_Body;
	GraphicsObject_Texture_Light *pGObj_Tank_Turret;

	Vect StartPos;

	Tank_Data Tank_Body_Data;
	Tank_Data Tank_Turret_Data;

	float angle = 0.0f;

public:
	DummyTank();
	virtual ~DummyTank();
	DummyTank& operator=(const DummyTank&) = delete;

	virtual void SceneEntry() override;
	virtual void SceneExit() override;

	virtual void Draw() override;
	virtual void Update() override;


	virtual void Collision(Collidable*) {};
	virtual void Collision(Tank*);

	const Vect& GetDummyTankPos();
	void SetTankPos(const Vect& v, float a = 0.0f);
};
#endif
