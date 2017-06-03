#include "LevelTwo.h"

#include "Tank.h"
#include "EnemyTank.h"

#include "BulletFactory.h"
#include "EnemyFactory.h"

#include "Hud.h"
#include "FirstPersonCam.h"
#include "GameManager.h"

void LevelTwo::Initialize()
{
	SetTerrain("Terrain_Sand");
	SetSkyBox("SkyBox_ONE");

	obj_Tank = new Tank();
	obj_HUD = new Hud(obj_Tank->getAngle());
	GameManager::SetHUD(obj_HUD);

	//*
	EnemyFactory::CreateEnemyTank(Vect(100, 1, 500), obj_Tank->GetTankPos());
	EnemyFactory::CreateEnemyTank(Vect(-300, 1, 250), obj_Tank->GetTankPos());
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

void LevelTwo::SceneEnd()
{
	BulletFactory::Delete();
	EnemyFactory::Delete();
}

LevelTwo::~LevelTwo()
{
	delete obj_Tank;
	delete obj_HUD;
}