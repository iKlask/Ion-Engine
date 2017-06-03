#include "EnemyTank.h"
#include "BulletFactory.h"
#include "EnemyFactory.h"

#include "Visualizer.h"

#include "ShaderAssets.h"
#include "ModelAssets.h"
#include "TextureAssets.h"

#include "TimeManager.h"
#include "SceneManager.h"
#include "Terrain.h"

#include "GraphicsObject_Texture_Light.h"
#include "Color.h"
#include "DebugOut.h"

EnemyTank::EnemyTank()
{
	LOOKAT = nullptr;

	HitColor.set(Color::Red);

	tex1 = TextureAssets::Get("TexTankTreads");
	tex2 = TextureAssets::Get("TexTankBody");

	pGObj_Tank_Body = new GraphicsObject_Texture_Light(ModelAssets::Get("modelTankBody"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), tex1, tex2, tex2, Color::White);
	pGObj_Tank_Turret = new GraphicsObject_Texture_Light(ModelAssets::Get("modelTankTurret_Barrel"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), tex2, tex2, tex2, Color::White);
	//pGObj_Tank_Turret = new GraphicsObject_Texture_Light(ModelAssets::Get("modelTankTurret"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), tex2, tex2, Color::White);

	StartPos = Vect(999,999,999);
	Turret_Bullet_Offset = Vect(0, 5, 60);
}

EnemyTank::~EnemyTank()
{
	delete pGObj_Tank_Body;
	delete pGObj_Tank_Turret;
}

void EnemyTank::Initialize(const Vect & start_pos, Vect * look_at)
{
	//set how many hits it takes to destory
	Health = 3;

	LOOKAT = look_at;
	StartPos = start_pos;

	//Set Tank Model Data Params
	Tank_Body_Data.Scale.set(SCALE, 1.0f, 1.0f, 1.0f);
	Tank_Body_Data.Rot.set(IDENTITY);
	Tank_Body_Data.Pos.set(StartPos);

	Tank_Turret_Data.Scale = Tank_Body_Data.Scale;
	Tank_Turret_Data.Rot = Tank_Body_Data.Rot;
	Tank_Turret_Data.Pos.set(Tank_Body_Data.Pos + Vect(0, 12, 0));

	Bullet_Pos.set(Tank_Turret_Data.Pos + Turret_Bullet_Offset);

	//Set World Matrix
	Matrix world;
	world = Tank_Body_Data.Scale * Tank_Body_Data.Rot * Matrix(TRANS, Tank_Body_Data.Pos);
	pGObj_Tank_Body->SetWorld(world);

	world = Tank_Turret_Data.Scale * Tank_Turret_Data.Rot * Matrix(TRANS, Tank_Turret_Data.Pos);
	pGObj_Tank_Turret->SetWorld(world);
}

void EnemyTank::SceneEntry()
{
	Updatable::Register();
	Drawable::Register();
	Alarmable::SetAlarm(3.0f, AlarmID::ALARM_0);
	Alarmable::SetAlarm((float)(rand() % 5), AlarmID::ALARM_1);

	cur_rot_state = ROTATE_STATE::ROT_LEFT;
	cur_move_state = MOVE_STATE::MOVE_FORW;

	CollisionRegister<EnemyTank>(this);
	SetColliderModel(pGObj_Tank_Body->getModel(), VolumeType::AABB);
	this->UpdateCollisionData(pGObj_Tank_Body->GetWorld());
}

void EnemyTank::SceneExit()
{
	Updatable::Deregister();
	Drawable::Deregister();
	CollisionDeregister<EnemyTank>(this);

	Alarmable::StopAlarm(AlarmID::ALARM_0);
	Alarmable::StopAlarm(AlarmID::ALARM_1);
	Alarmable::StopAlarm(AlarmID::ALARM_2);

	EnemyFactory::RecycleEnemyTank(this);
}

void EnemyTank::Update()
{
	UpdateTankMovement();

	//	==========================
		Vect height = SceneManager::GetCurrentTerrain()->GetSurfacePoint(Tank_Body_Data.Pos) - Vect(0, 0.01f, 0, 0);
		Tank_Body_Data.Pos[y] = height[y];
		Tank_Turret_Data.Pos[y] = Tank_Body_Data.Pos[y] + 12.0f;

		float dist = IonMathTools::vDistance(Tank_Turret_Data.Pos, *LOOKAT);
		//DebugMsg::out("Distance: %f\n", dist);
		Vect look = (*LOOKAT) - Tank_Turret_Data.Pos;

		//*
		if (dist > 1070.0f) {
			look = (*LOOKAT + Vect(0, dist * 0.06f, 0)) - Tank_Turret_Data.Pos;
		}
		else if (dist > 800.0f) {
			look = (*LOOKAT + Vect(0, dist * 0.04f, 0)) - Tank_Turret_Data.Pos;
		}
		else if (dist > 300.0f){
			look = (*LOOKAT + Vect(0, dist * 0.02f, 0)) - Tank_Turret_Data.Pos;
		}
		//*/
		look.norm();
		Tank_Turret_Data.Rot.set(ROT_ORIENT, look, Vect(0,1,0));
	//	==========================
	UpdateWorldMatrices();
}

void EnemyTank::UpdateWorldMatrices()
{
	Matrix worldBody = Tank_Body_Data.Scale * Tank_Body_Data.Rot * Matrix(TRANS, Tank_Body_Data.Pos);
	pGObj_Tank_Body->SetWorld(worldBody);
	this->UpdateCollisionData(worldBody);

	Matrix worldTurret = Tank_Turret_Data.Scale * Tank_Turret_Data.Rot * Matrix(TRANS, Tank_Turret_Data.Pos);
	pGObj_Tank_Turret->SetWorld(worldTurret);

	Bullet_Pos.set(Turret_Bullet_Offset * worldTurret);
}

void EnemyTank::UpdateTankMovement() 
{
	switch (cur_rot_state) {
	case ROTATE_STATE::ROT_LEFT:
		Tank_Body_Data.Rot *= Matrix(ROT_Y, Tank_Body_Angle * TimeManager::GetFrameTime());
		//Tank_Turret_Data.Rot *= Matrix(ROT_Y, Tank_Body_Angle * TimeManager::GetFrameTime());
		break;
	case ROTATE_STATE::ROT_RIGHT:
		Tank_Body_Data.Rot *= Matrix(ROT_Y, -Tank_Body_Angle* TimeManager::GetFrameTime());
		//Tank_Turret_Data.Rot *= Matrix(ROT_Y, -Tank_Body_Angle* TimeManager::GetFrameTime());
		break;
	}

	switch (cur_move_state) {
	case MOVE_STATE::MOVE_FORW:
		Tank_Body_Data.Pos += Vect(0, 0, 1) * Tank_Body_Data.Rot * Tank_Speed * TimeManager::GetFrameTime();
		Tank_Turret_Data.Pos += Vect(0, 0, 1) * Tank_Body_Data.Rot * Tank_Speed * TimeManager::GetFrameTime();
		break;
	case MOVE_STATE::MOVE_BACK:
		Tank_Body_Data.Pos += Vect(0, 0, 1) * Tank_Body_Data.Rot * -Tank_Speed * TimeManager::GetFrameTime();
		Tank_Turret_Data.Pos += Vect(0, 0, 1) * Tank_Body_Data.Rot * -Tank_Speed * TimeManager::GetFrameTime();
		break;
	}
}


void EnemyTank::Draw()
{
	pGObj_Tank_Body->Render(SceneManager::GetCurSceneCam3D());
	pGObj_Tank_Turret->Render(SceneManager::GetCurSceneCam3D());

	if (bSphereToggle) {
		//Visualizer::ShowBSphere(BSphere, Color::Red);
	}
	else {
		//Visualizer::ShowBSphere(BSphere, Color::DarkGray);
	}
	bSphereToggle = false;
}

void EnemyTank::Alarm0()
{
	BulletFactory::CreateBullet(Tank_Turret_Data.Rot, Bullet_Pos);
	Alarmable::SetAlarm(3.0f, AlarmID::ALARM_0);
}

void EnemyTank::Alarm1()
{
	cur_rot_state = ROTATE_STATE(rand() % 3);
	cur_move_state = MOVE_STATE(rand() % 3);
	Alarmable::SetAlarm((float)(rand() % 5), AlarmID::ALARM_1);
}

void EnemyTank::Alarm2()
{
	pGObj_Tank_Body->SetLightColors(Color::White);
	pGObj_Tank_Turret->SetLightColors(Color::White);
}


void EnemyTank::Collision(Bullet *)
{
	bSphereToggle = true;
	--Health;
	if (Health <= 0) {
		SubmitExit();
	}
	pGObj_Tank_Body->SetLightColors(HitColor);
	pGObj_Tank_Turret->SetLightColors(HitColor);

	Alarmable::SetAlarm(0.25f, AlarmID::ALARM_2);
}

void EnemyTank::Collision(Tank *)
{
	DebugMsg::out("ENEMY COLLIDING WITH PLAYER!\n");
}

Vect * EnemyTank::GetTankPos()
{
	return &Tank_Body_Data.Pos;
}
