#include "LevelOne.h"

#include "Tank.h"
#include "EnemyTank.h"

#include "BulletFactory.h"
#include "EnemyFactory.h"

#include "Hud.h"
#include "FirstPersonCam.h"
#include "GameManager.h"


void LevelOne::Initialize()
{
	SetTerrain("Terrain_Grass");
	SetSkyBox("SkyBox_ONE");

	obj_Tank = new Tank();
	obj_HUD = new Hud(obj_Tank->getAngle());
	GameManager::SetHUD(obj_HUD);

	//*
	EnemyFactory::CreateEnemyTank(Vect(-100, 1, 700), obj_Tank->GetTankPos());
	//*/

	//*
	fpCam = new FirstPersonCam(obj_Tank->GetCamPos(), obj_Tank->GetCamRot());
	this->SetCamera(fpCam);
	//*/

	SetCollisionPair<Tank, Bullet>();
	SetCollisionPair<EnemyTank, Bullet>();
	SetCollisionPair<EnemyTank, Tank>();

	SetCollisionSelf<Bullet>();

	SetCollisionTerrain<Bullet>();
	//SetCollisionTerrain<Tank>();
	//SetCollisionTerrain<EnemyTank>();
}

void LevelOne::SceneEnd()
{
	BulletFactory::Delete();
	EnemyFactory::Delete();
}

LevelOne::~LevelOne()
{
	delete obj_Tank;
	delete obj_HUD;
}
