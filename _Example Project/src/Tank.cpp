#include "Tank.h"
#include "BulletFactory.h"
#include "GameManager.h"

#include "Visualizer.h"

#include "ShaderAssets.h"
#include "ModelAssets.h"
#include "TextureAssets.h"

#include "TimeManager.h"
#include "SceneManager.h"
#include "Terrain.h"

#include "GraphicsObject_Texture_Light.h"
#include "GraphicsObject_Color.h"
#include "Color.h"
#include "DebugOut.h"


Tank::Tank()
{
	HitColor.set(Color::Red);

	pGObj_Tank_Body = new GraphicsObject_Texture_Light(ModelAssets::Get("modelTankBody"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), TextureAssets::Get("TexTankTreads"), TextureAssets::Get("TexTankBody"), TextureAssets::Get("TexTankBody"), Color::White);
	//pGObj_Tank_Turret = new GraphicsObject_Texture_Light(ModelAssets::Get("modelTankTurret"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), TextureAssets::Get("TexTankBody"), TextureAssets::Get("TexTankBody"), TextureAssets::Get("TexTankBody"), Color::White);
	pGObj_Tank_Turret = new GraphicsObject_Texture_Light(ModelAssets::Get("modelTankTurret"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), TextureAssets::Get("TexTankBody"), TextureAssets::Get("TexTankBody"), Color::White);
	pGObj_Tank_Barrel = new GraphicsObject_Texture_Light(ModelAssets::Get("modelTankBarrel"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), TextureAssets::Get("TexTankBody"), TextureAssets::Get("TexTankBody"), Color::White);

	/*
	pGObj_Axis = new GraphicsObject_Color(ModelAssets::Get("modelAxis"), ShaderAssets::Get("SHADER_COLOR"));
	//*/

	StartPos = Vect(0, 1, 0);
	Turret_Bullet_Offset = Vect(0, 0, 50);
	Turret_Camera_Offset = Vect(5, 5, 12);
	Turret_Barrel_Offset = Vect(-0.07f, 4.69f, 12.8f);

	//	====== Set Tank Model Data Params	======
	Tank_Body_Data.Scale.set(SCALE, 1.0f, 1.0f, 1.0f);
	Tank_Body_Data.Rot.set(IDENTITY);
	Tank_Body_Data.Pos.set(StartPos);
	Tank_Body_Data.angle = 0.0f;
	//	======
	Tank_Turret_Data.Scale = Tank_Body_Data.Scale;
	Tank_Turret_Data.Rot = Tank_Body_Data.Rot;
	Tank_Turret_Data.Pos.set(Tank_Body_Data.Pos + Vect(0, 12, 0));
	Tank_Turret_Data.angle = 0.0f;
	//	======
	Tank_Barrel_Data.Scale = Tank_Turret_Data.Scale;
	Tank_Barrel_Data.Rot = Tank_Turret_Data.Rot;
	Tank_Barrel_Data.Pos.set(Tank_Turret_Data.Pos + Turret_Barrel_Offset);
	Tank_Barrel_Data.angle = 0.0f;
	//	======

	Updatable::Register();
	Drawable::Register();
	Inputable::RegisterKey(ION_KEY::KEY_SPACE, INPUT_EVENT::KEY_PRESSED);

	CollisionRegister<Tank>(this);
	SetColliderModel(pGObj_Tank_Body->getModel(), VolumeType::OBB);
	UpdateWorldMatrices();
}

Tank::~Tank()
{
	delete pGObj_Tank_Body;
	delete pGObj_Tank_Turret;
	delete pGObj_Tank_Barrel;
	/*
	delete pGObj_Axis;
	//*/
}

void Tank::SceneEntry()
{
	/*
	Updatable::Register();
	Drawable::Register();
	Inputable::RegisterKey(ION_KEY::KEY_SPACE, INPUT_EVENT::KEY_PRESSED);


	CollisionRegister<Tank>(this);
	SetColliderModel(pGObj_Tank_Body->getModel(), VolumeType::OBB);
	this->UpdateCollisionData(pGObj_Tank_Body->GetWorld());
	//*/
}

void Tank::SceneExit()
{
	/*
	Updatable::Deregister();
	Drawable::Deregister();
	Inputable::DeregisterKey(ION_KEY::KEY_SPACE, INPUT_EVENT::KEY_PRESSED);

	Alarmable::StopAlarm(AlarmID::ALARM_0);
	Alarmable::StopAlarm(AlarmID::ALARM_1);

	CollisionDeregister<Tank>(this);
	//*/
}

void Tank::Update()
{
	UpdateTankMovement(ION_KEY::KEY_W, ION_KEY::KEY_S);

	UpdateTankRotation(ION_KEY::KEY_A, ION_KEY::KEY_D);

	UpdateTurretRotation(ION_KEY::KEY_ARROW_LEFT, ION_KEY::KEY_ARROW_RIGHT);

	UpdateBarrelHeight(ION_KEY::KEY_ARROW_UP, ION_KEY::KEY_ARROW_DOWN);

	//DebugMsg::out("Barrel Angle: %f\n", Tank_Body_Data.angle );

	//
	Vect height = SceneManager::GetCurrentTerrain()->GetSurfacePoint(Tank_Body_Data.Pos) - Vect(0,0.01f,0,0);
	Tank_Body_Data.Pos[y] = height[y];
	Visualizer::ShowPoint(height, Color::Purple);
	//

	Tank_Turret_Data.Pos[y] = Tank_Body_Data.Pos[y] + 12.0f;	//	Move Turret up from floor
	UpdateWorldMatrices();
}

void Tank::UpdateWorldMatrices() {
	Matrix worldBody = Tank_Body_Data.Scale * Tank_Body_Data.Rot * Matrix(TRANS, Tank_Body_Data.Pos);
	pGObj_Tank_Body->SetWorld(worldBody);
	this->UpdateCollisionData(worldBody);

	Matrix worldTurret = Tank_Turret_Data.Scale * Tank_Turret_Data.Rot * Matrix(TRANS, Tank_Turret_Data.Pos);
	pGObj_Tank_Turret->SetWorld(worldTurret);


	Tank_Barrel_Data.Pos.set(Turret_Barrel_Offset * worldTurret);
	Matrix worldBarrel = Tank_Barrel_Data.Scale * Tank_Barrel_Data.Rot * Matrix(TRANS, Tank_Barrel_Data.Pos);
	pGObj_Tank_Barrel->SetWorld(worldBarrel);

	Bullet_Pos.set(Turret_Bullet_Offset * worldBarrel);
	Camera_Pos.set(Turret_Camera_Offset * worldTurret);
	Camera_Rot = Tank_Barrel_Data.Rot;
	//Camera_Rot = Tank_Turret_Data.Rot;

	/*
	Matrix worldAxis = Tank_Turret_Data.Scale * Tank_Turret_Data.Rot * Matrix(TRANS, Bullet_Pos);
	pGObj_Axis->SetWorld(worldAxis);
	//*/
}

void Tank::UpdateTankMovement(ION_KEY key_1, ION_KEY key_2)
{
	if (Keyboard::GetKeyState(key_1))
	{
		Tank_Body_Data.Pos += Vect(0, 0, 1) * Tank_Body_Data.Rot * Tank_Speed * TimeManager::GetFrameTime();
		Tank_Turret_Data.Pos += Vect(0, 0, 1) * Tank_Body_Data.Rot * Tank_Speed * TimeManager::GetFrameTime();
	}
	else if (Keyboard::GetKeyState(key_2))
	{
		Tank_Body_Data.Pos += Vect(0, 0, 1) * Tank_Body_Data.Rot * -Tank_Speed * TimeManager::GetFrameTime();
		Tank_Turret_Data.Pos += Vect(0, 0, 1) * Tank_Body_Data.Rot * -Tank_Speed * TimeManager::GetFrameTime();
	}
}

void Tank::UpdateTankRotation(ION_KEY key_1, ION_KEY key_2)
{
	if (Keyboard::GetKeyState(key_1))
	{
		Tank_Body_Data.Rot *= Matrix(ROT_Y, Tank_Body_Angle * TimeManager::GetFrameTime());
		Tank_Body_Data.angle += Tank_Body_Angle* TimeManager::GetFrameTime();

	}
	else if (Keyboard::GetKeyState(key_2))
	{
		Tank_Body_Data.Rot *= Matrix(ROT_Y, -Tank_Body_Angle* TimeManager::GetFrameTime());
		Tank_Body_Data.angle -= Tank_Body_Angle* TimeManager::GetFrameTime();
	}
}

void Tank::UpdateTurretRotation(ION_KEY key_1, ION_KEY key_2)
{
	if (Keyboard::GetKeyState(key_1))
	{
		//if (Tank_Body_Data.angle > -1.5f) {

			Tank_Turret_Data.Rot *= Matrix(ROT_Y, Tank_Turret_Angle * TimeManager::GetFrameTime());
			Tank_Turret_Data.angle += Tank_Turret_Angle* TimeManager::GetFrameTime();

			Tank_Barrel_Data.Rot *= Matrix(ROT_Y, Tank_Turret_Angle * TimeManager::GetFrameTime());

			Tank_Body_Data.angle -= Tank_Turret_Angle* TimeManager::GetFrameTime();
		//}
	}
	else if (Keyboard::GetKeyState(key_2))
	{
		//if (Tank_Body_Data.angle < 1.5) {
			Tank_Turret_Data.Rot *= Matrix(ROT_Y, -Tank_Turret_Angle * TimeManager::GetFrameTime());
			Tank_Turret_Data.angle -= Tank_Turret_Angle* TimeManager::GetFrameTime();

			Tank_Barrel_Data.Rot *= Matrix(ROT_Y, -Tank_Turret_Angle * TimeManager::GetFrameTime());

			Tank_Body_Data.angle += Tank_Turret_Angle* TimeManager::GetFrameTime();
		//}
	}
}

void Tank::UpdateBarrelHeight(ION_KEY key_1, ION_KEY key_2)
{
	if (Keyboard::GetKeyState(key_1))
	{
		if (Tank_Barrel_Data.angle < 0.3f) {			
			//Matrix worldTurret = Tank_Turret_Data.Scale * Tank_Turret_Data.Rot * Matrix(TRANS, Tank_Turret_Data.Pos);
			Matrix worldTurret = pGObj_Tank_Turret->GetWorld();
			Vect x_Axis = Vect(1, 0, 0, 0)*(worldTurret);
			Tank_Barrel_Data.Rot *= Matrix(ROT_AXIS_ANGLE, x_Axis, (-Tank_Barrel_Angle * TimeManager::GetFrameTime()));

			Tank_Barrel_Data.angle += Tank_Barrel_Angle* TimeManager::GetFrameTime();
		}

	}
	else if (Keyboard::GetKeyState(key_2))
	{
		if (Tank_Barrel_Data.angle > -0.15f) {
			//Matrix worldTurret = Tank_Turret_Data.Scale * Tank_Turret_Data.Rot * Matrix(TRANS, Tank_Turret_Data.Pos);
			Matrix worldTurret = pGObj_Tank_Turret->GetWorld();
			Vect x_Axis = Vect(1, 0, 0, 0)*(worldTurret);
			Tank_Barrel_Data.Rot *= Matrix(ROT_AXIS_ANGLE, x_Axis, (Tank_Barrel_Angle * TimeManager::GetFrameTime()));

			Tank_Barrel_Data.angle -= Tank_Barrel_Angle* TimeManager::GetFrameTime();
		}
	}
}

void Tank::Draw()
{
	pGObj_Tank_Body->Render(SceneManager::GetCurSceneCam3D());
	pGObj_Tank_Turret->Render(SceneManager::GetCurSceneCam3D());
	pGObj_Tank_Barrel->Render(SceneManager::GetCurSceneCam3D());
	//pGObj_Axis->Render(SceneManager::GetCurSceneCam3D());
}

void Tank::KeyPressed(const ION_KEY & key_in)
{
	switch (key_in) {
		case ION_KEY::KEY_SPACE:
			if (bCanShoot) {
				BulletFactory::CreateBullet(Tank_Barrel_Data.Rot, Bullet_Pos);
				bCanShoot = false;
 				GameManager::SetHUDReload();
				Alarmable::SetAlarm(3.0f, AlarmID::ALARM_0);
			}
			break;
	}
}

void Tank::KeyReleased(const ION_KEY &)
{
}

void Tank::Alarm0()
{
	bCanShoot = true;
	GameManager::SetHUDReady();
}

void Tank::Alarm1()
{
	pGObj_Tank_Body->SetLightColors(Color::White);
	pGObj_Tank_Turret->SetLightColors(Color::White);
	pGObj_Tank_Barrel->SetLightColors(Color::White);
}

void Tank::CollisionTerrain()
{
	//DebugMsg::out("COLLISION:\tUSER Terrain Collision!\n");
}

void Tank::Collision(Bullet *)
{
	GameManager::PlayerHit();
	bSphereToggle = true;

	pGObj_Tank_Body->SetLightColors(HitColor);
	pGObj_Tank_Turret->SetLightColors(HitColor);
	pGObj_Tank_Barrel->SetLightColors(HitColor);

	Alarmable::SetAlarm(0.25f, AlarmID::ALARM_1);
}

void Tank::Collision(EnemyTank *)
{
	DebugMsg::out("	PLAYER COLLIDING WITH ENEMY!\n	");
}

Vect * Tank::GetTankPos()
{
	return &Tank_Turret_Data.Pos;
}

Vect * Tank::GetCamPos()
{
	return &Camera_Pos;
}

Matrix * Tank::GetCamRot()
{
	return &Camera_Rot;
}

float* Tank::getAngle()
{
	return &Tank_Body_Data.angle;
}
