#include "Bullet.h"
#include "BulletFactory.h"

#include "SceneManager.h"
#include "Scene.h"

#include "Visualizer.h"

#include "ModelAssets.h"
#include "ShaderAssets.h"
#include "TextureAssets.h"
#include "TimeManager.h"


#include "GraphicsObject_Texture_Light.h"
#include "Color.h"

Bullet::Bullet()
{
	BulletTransSpeed = 500.f;
	bulletLifeTime = 10.0f;
	height = 0.0f;

	pGObj_WireFrame_Ball = new GraphicsObject_Texture_Light(ModelAssets::Get("modelSphere"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), TextureAssets::Get("TexPink"), Color::White);

	BulletScale.set(SCALE, 1.5f, 1.5f, 1.5f);
	WorldRot.set(IDENTITY);
	BulletPos.set(1000, 1000, 1000);

	Matrix world = BulletScale * WorldRot * Matrix(TRANS, BulletPos);
	pGObj_WireFrame_Ball->SetWorld(world);

	SetColliderModel(pGObj_WireFrame_Ball->getModel(), VolumeType::OBB);
	this->UpdateCollisionData(world);
}

void Bullet::Initialize(const Matrix& rot, const Vect& pos)
{
	WorldRot = rot;
	BulletPos = pos;
	height = 0.0f;

	Matrix world = BulletScale * WorldRot * Matrix(TRANS, BulletPos);
	pGObj_WireFrame_Ball->SetWorld(world);
	this->UpdateCollisionData(world);
}

void Bullet::Initialize(const Matrix & rot, const Vect & pos, const float & speed)
{
	WorldRot = rot;
	BulletPos = pos;
	BulletTransSpeed = speed;
	height = 0.0f;

	Matrix world = BulletScale * WorldRot * Matrix(TRANS, BulletPos);
	pGObj_WireFrame_Ball->SetWorld(world);
	this->UpdateCollisionData(world);
}

void Bullet::SceneEntry()
{
	Updatable::Register();
	Drawable::Register();
	Alarmable::SetAlarm(bulletLifeTime, AlarmID::ALARM_0);

	//Register for Collision
	CollisionRegister<Bullet>(this);
	SetColliderModel(pGObj_WireFrame_Ball->getModel());
}

void Bullet::SceneExit()
{
	Updatable::Deregister();
	Drawable::Deregister();
	Alarmable::StopAlarm(AlarmID::ALARM_0);
	BulletPos.set(100, 100, 100);

	//Deregister for Collision
	CollisionDeregister<Bullet>(this);


	BulletFactory::RecycleBullet(this);
}

void Bullet::Update()
{
	//move forward
	BulletPos += Vect(0, height, 1) * WorldRot * BulletTransSpeed * TimeManager::GetFrameTime();
	height -= 0.0005f;

	Matrix world = BulletScale * WorldRot * Matrix(TRANS, BulletPos);
	pGObj_WireFrame_Ball->SetWorld(world);
	this->UpdateCollisionData(world);
	//Matrix world = BulletScale * WorldRot * Matrix(TRANS, BulletPos);
	//pGObj_WireFrame_Ball->SetWorld(world);
}

void Bullet::Draw()
{
	//Matrix world = BulletScale * WorldRot * Matrix(TRANS, BulletPos);
	//pGObj_WireFrame_Ball->SetWorld(world);
	pGObj_WireFrame_Ball->Render(SceneManager::GetCurSceneCam3D());

	if (bSphereToggle) {
		//Visualizer::ShowBSphere(BSphere, Color::Red);
	}
	else {
		//Visualizer::ShowBSphere(BSphere, Color::DarkGray);
	}
	bSphereToggle = false;
}

void Bullet::Alarm0()
{
	//DebugMsg::out("Alarm Triggered at:\t%f\n", TimeManager::GetTime());
	//destroy itself
	SubmitExit();
}

void Bullet::CollisionTerrain()
{
	bSphereToggle = true;
	SubmitExit();
}

void Bullet::Collision(Collidable *)
{
	bSphereToggle = true;
	//DebugMsg::out("COLLISION:\tBullet with Collidable!\n");
}

void Bullet::Collision(Tank *)
{
	bSphereToggle = true;
	SubmitExit();
	////DebugMsg::out("COLLISION:\tBullet with Tank!\n");
}

void Bullet::Collision(EnemyTank *)
{
	bSphereToggle = true;
	SubmitExit();
	////DebugMsg::out("COLLISION:\tBullet with EnemyTank!\n");
}

void Bullet::Collision(Bullet *)
{
	bSphereToggle = true;
	SubmitExit();
	////DebugMsg::out("COLLISION:\tBullet with Bullet!\n");
}

Bullet::~Bullet()
{
	//DebugMsg::out("USER DESTRUCTOR Bullet\n");
	delete pGObj_WireFrame_Ball;
}
