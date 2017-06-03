#include "DummyTank.h"

#include "ShaderAssets.h"
#include "ModelAssets.h"
#include "TextureAssets.h"

#include "TimeManager.h"
#include "SceneManager.h"
#include "Terrain.h"

#include "GraphicsObject_Texture_Light.h"
#include "Color.h"
#include "DebugOut.h"

DummyTank::DummyTank()
{
	pGObj_Tank_Body = new GraphicsObject_Texture_Light(ModelAssets::Get("modelTankBody"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), TextureAssets::Get("TexTankTreads"), TextureAssets::Get("TexTankBody"), TextureAssets::Get("TexTankBody"), Color::White);
	pGObj_Tank_Turret = new GraphicsObject_Texture_Light(ModelAssets::Get("modelTankTurret_Barrel"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), TextureAssets::Get("TexTankBody"), TextureAssets::Get("TexTankBody"), TextureAssets::Get("TexTankBody"), Color::White);
	//pGObj_Tank_Turret = new GraphicsObject_Texture_Light(ModelAssets::Get("modelTankTurret"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), TextureAssets::Get("TexTankBody"), TextureAssets::Get("TexTankBody"), Color::White);


	StartPos = Vect(0, 1, 0);

	//Set Tank Model Data Params
	Tank_Body_Data.Scale.set(SCALE, 1.0f, 1.0f, 1.0f);
	Tank_Body_Data.Rot.set(IDENTITY);
	Tank_Body_Data.Pos.set(StartPos);
	Tank_Body_Data.angle = 0.0f;

	Tank_Turret_Data.Scale = Tank_Body_Data.Scale;
	Tank_Turret_Data.Rot = Tank_Body_Data.Rot;
	Tank_Turret_Data.Pos.set(Tank_Body_Data.Pos + Vect(0, 12, 0));
	Tank_Turret_Data.angle = 0.0f;

	//Set World Matrix
	Matrix world;
	world = Tank_Body_Data.Scale * Tank_Body_Data.Rot * Matrix(TRANS, Tank_Body_Data.Pos);
	pGObj_Tank_Body->SetWorld(world);

	world = Tank_Turret_Data.Scale * Tank_Turret_Data.Rot * Matrix(TRANS, Tank_Turret_Data.Pos);
	pGObj_Tank_Turret->SetWorld(world);
}

DummyTank::~DummyTank()
{
	delete pGObj_Tank_Body;
	delete pGObj_Tank_Turret;
}

void DummyTank::SceneEntry()
{
	Updatable::Register();
	Drawable::Register();


	Vect height = SceneManager::GetCurrentTerrain()->GetSurfacePoint(Tank_Body_Data.Pos) - Vect(0, 0.01f, 0, 0);
	Tank_Body_Data.Pos[y] = height[y];

	//Tank_Body_Data.Pos[y] = SceneManager::GetCurrentTerrain()->GetHeight(Tank_Body_Data.Pos);
	Tank_Turret_Data.Pos[y] = Tank_Body_Data.Pos[y] + 12.0f;

	Matrix worldBody = Tank_Body_Data.Scale * Tank_Body_Data.Rot * Matrix(TRANS, Tank_Body_Data.Pos);
	pGObj_Tank_Body->SetWorld(worldBody);

	Matrix worldTurret = Tank_Turret_Data.Scale * Tank_Turret_Data.Rot * Matrix(TRANS, Tank_Turret_Data.Pos);
	pGObj_Tank_Turret->SetWorld(worldTurret);

	CollisionRegister<DummyTank>(this);
	SetColliderModel(pGObj_Tank_Body->getModel(), VolumeType::OBB);
	this->UpdateCollisionData(pGObj_Tank_Body->GetWorld());
}

void DummyTank::SceneExit()
{
	Updatable::Deregister();
	Drawable::Deregister();

	CollisionDeregister<DummyTank>(this);
}

void DummyTank::Draw()
{
	pGObj_Tank_Body->Render(SceneManager::GetCurSceneCam3D());
	pGObj_Tank_Turret->Render(SceneManager::GetCurSceneCam3D());
}

void DummyTank::Update()
{
	/*
	Tank_Body_Data.Rot *= Matrix(ROT_Y, angle* TimeManager::GetFrameTime());
	Tank_Body_Data.angle = angle;

	Matrix worldBody = Tank_Body_Data.Scale * Tank_Body_Data.Rot * Matrix(TRANS, Tank_Body_Data.Pos);
	pGObj_Tank_Body->SetWorld(worldBody);
	this->UpdateCollisionData(worldBody);

	Matrix worldTurret = Tank_Turret_Data.Scale * Tank_Turret_Data.Rot * Matrix(TRANS, Tank_Turret_Data.Pos);
	pGObj_Tank_Turret->SetWorld(worldTurret);
	//*/
}

void DummyTank::Collision(Tank *)
{
	DebugMsg::out("COLLIDING WITH TANK\n");
}

const Vect & DummyTank::GetDummyTankPos()
{
	return Tank_Body_Data.Pos;
}

void DummyTank::SetTankPos(const Vect & v, float a)
{
	Tank_Body_Data.Pos.set(v);
	Tank_Turret_Data.Pos.set(Tank_Body_Data.Pos + Vect(0, 12, 0));

	Tank_Body_Data.Rot *= Matrix(ROT_Y, a* TimeManager::GetFrameTime());
	Tank_Body_Data.angle = a;

	Matrix worldBody = Tank_Body_Data.Scale * Tank_Body_Data.Rot * Matrix(TRANS, Tank_Body_Data.Pos);
	pGObj_Tank_Body->SetWorld(worldBody);
	//this->UpdateCollisionData(worldBody);

	Matrix worldTurret = Tank_Turret_Data.Scale * Tank_Turret_Data.Rot * Matrix(TRANS, Tank_Turret_Data.Pos);
	pGObj_Tank_Turret->SetWorld(worldTurret);
}
