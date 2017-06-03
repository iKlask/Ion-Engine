#include "SphereTest.h"

#include "GraphicsObject_Texture_Light.h"
#include "GraphicsObject_WireframeColor.h"

#include "ModelAssets.h"
#include "ShaderAssets.h"
#include "TextureAssets.h"
#include "Color.h"

#include "TimeManager.h"

#include "SceneManager.h"

SphereTest::SphereTest(const Vect& pos)
{
	gObj = new GraphicsObject_Texture_Light(ModelAssets::Get("SYSTEM_BoundingSphereModel_Tex"), ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), TextureAssets::Get("TexGrass"), Color::White);
	//gObj = new GraphicsObject_WireframeColor(ModelAssets::Get("SYSTEM_BoundingSphereModel"), ShaderAssets::Get("SYSTEM_WireframeColor"), Color::Red);
	world = Matrix(SCALE, 1.0f, 1.0f, 1.0f) * Matrix(IDENTITY) * Matrix(TRANS, pos);
	gObj->SetWorld(world);

	Updatable::Register();
	Drawable::Register();
}

SphereTest::~SphereTest()
{
	delete gObj;
}

void SphereTest::Draw()
{
	gObj->Render(SceneManager::GetCurSceneCam3D());

	//gObj->RenderCmd(SceneManager::GetCurSceneCam3D());
}

void SphereTest::Update()
{
	world = Matrix(ROT_Y, 0.5f*TimeManager::GetFrameTime()) * world;
	gObj->SetWorld(world);
}

void SphereTest::SceneEntry()
{

}

void SphereTest::SceneExit()
{
}
