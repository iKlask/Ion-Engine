#include "LevelThree.h"

#include "Tank.h"
#include "EnemyTank.h"

#include "BulletFactory.h"
#include "EnemyFactory.h"

#include "Hud.h"
#include "FirstPersonCam.h"
#include "GameManager.h"

void LevelThree::Initialize()
{
	SetTerrain("Terrain_Rock");
	SetSkyBox("SkyBox_ONE");

	obj_Tank = new Tank();
	obj_HUD = new Hud(obj_Tank->getAngle());
	GameManager::SetHUD(obj_HUD);

	//*
	EnemyFactory::CreateEnemyTank(Vect(550, 1, 500), obj_Tank->GetTankPos());
	EnemyFactory::CreateEnemyTank(Vect(-400, 1, 500), obj_Tank->GetTankPos());
	EnemyFactory::CreateEnemyTank(Vect(300, 1, -620), obj_Tank->GetTankPos());
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

void LevelThree::SceneEnd()
{
	BulletFactory::Delete();
	EnemyFactory::Delete();
}

LevelThree::~LevelThree()
{
	delete obj_Tank;
	delete obj_HUD;
}