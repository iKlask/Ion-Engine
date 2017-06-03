#include "IonEngine.h"

#include "ShaderAssets.h"
#include "TextureAssets.h"
#include "ModelAssets.h"
#include "ImageAssets.h"
#include "TerrainAssets.h"
#include "SkyBoxAssets.h"

#include "Rect.h"
#include "Color.h"

#include "ShaderTexture.h"
#include "ShaderTextureLight.h"
#include "ShaderColor.h"
#include "ShaderColorLight.h"
#include "ShaderColorVary.h"

void IonEngine::LoadResources() 
{
	//---------------------------------------------------------------------------------------------------------
	// Load the Models
	//---------------------------------------------------------------------------------------------------------
	// Model from file ( .azul format)
	ModelAssets::Load("modelSphere", "Models/Sphere.azul");
	ModelAssets::Load("modelTankBody", "Models/Tank/Tank_Body.azul");
	ModelAssets::Load("modelTankTurret_Barrel", "Models/Tank/Tank_Turret.azul");
	ModelAssets::Load("modelTankTurret", "Models/Tank/Tank_Turret_noBarrel.azul");
	ModelAssets::Load("modelTankBarrel", "Models/Tank/Tank_Barrel.azul");

	ModelAssets::Load("modelAxis", "Models/Axis.azul");

	//---------------------------------------------------------------------------------------------------------
	// Load the Textures
	//---------------------------------------------------------------------------------------------------------
	// Direct loads
	TextureAssets::Load("TexTankBody", "Textures/Tank/Tank_Body_Desert.tga");
	TextureAssets::Load("TexTankTreads", "Textures/Tank/Tank_Track.tga");

	//*HUD
	TextureAssets::Load("TexTankHud", "Textures/HUD/Tank_HUD.tga");
	TextureAssets::Load("TexTankHudRotBODY", "Textures/HUD/Tank_HUD_Rot_BODY.tga");
	TextureAssets::Load("TexTankHudRotTURRET", "Textures/HUD/Tank_HUD_Rot_TURRET.tga");
	TextureAssets::Load("TexShellLoading", "Textures/HUD/APShell_Loading.tga");
	TextureAssets::Load("TexShellReady", "Textures/HUD/APShell_Ready.tga");
	TextureAssets::Load("TexShellWait", "Textures/HUD/Tank_HUD_Wait.tga");
	TextureAssets::Load("TexHealthText", "Textures/HUD/Tank_HUD_Health.tga");
	TextureAssets::Load("TexHealthTextBarFULL", "Textures/HUD/Tank_HUD_hBar_FULL.tga");
	TextureAssets::Load("TexHealthTextBarEMPTY", "Textures/HUD/Tank_HUD_hBar_EMPTY.tga");
	//*/

	TextureAssets::Load("TexWinScreen", "Textures/ScreenOverlay/WinScreen.tga");
	TextureAssets::Load("TexLoseScreen", "Textures/ScreenOverlay/LoseScreen.tga");
	TextureAssets::Load("TexMainScreen", "Textures/ScreenOverlay/MenuLogo.tga");

	TextureAssets::Load("Tex_SkyBox_ONE", "Textures/SkyBox.tga");

	TextureAssets::Load("TexSandGrass", "Textures/sandgrass.tga");
	TextureAssets::Load("TexGrass", "Textures/grass.tga");
	TextureAssets::Load("TexSand", "Textures/sand.tga");
	TextureAssets::Load("TexHardGround", "Textures/hardground.tga");

	TextureAssets::Load("TexPink", "Textures/HotPink.tga");

	//TextureAssets::Load("TexFlatColor", 255, 0, 128);	//?

	//---------------------------------------------------------------------------------------------------------
	// Load Images
	//---------------------------------------------------------------------------------------------------------
	ImageAssets::Load("TankHudImage", TextureAssets::Get("TexTankHud"));
	ImageAssets::Load("TankHudRotBODYImage", TextureAssets::Get("TexTankHudRotBODY"));
	ImageAssets::Load("TankHudRotTURRETImage", TextureAssets::Get("TexTankHudRotTURRET"));
	ImageAssets::Load("ShellLoadingImage", TextureAssets::Get("TexShellLoading"));
	ImageAssets::Load("ShellReadyImage", TextureAssets::Get("TexShellReady"));
	ImageAssets::Load("ShellWaitImage", TextureAssets::Get("TexShellWait"));

	ImageAssets::Load("HealthTextImage", TextureAssets::Get("TexHealthText"));
	ImageAssets::Load("HealthBarFULLImage", TextureAssets::Get("TexHealthTextBarFULL"));
	ImageAssets::Load("HealthBarEMPTYImage", TextureAssets::Get("TexHealthTextBarEMPTY"));

	ImageAssets::Load("WinScreenImage", TextureAssets::Get("TexWinScreen"));
	ImageAssets::Load("LoseScreenImage", TextureAssets::Get("TexLoseScreen"));
	ImageAssets::Load("MainScreenImage", TextureAssets::Get("TexMainScreen"));

	//---------------------------------------------------------------------------------------------------------
	// Load the Shaders
	//---------------------------------------------------------------------------------------------------------
	ShaderAssets::Load("SHADER_TEXTURE", new ShaderTexture());
	ShaderAssets::Load("SHADER_TEXTURE_LIGHT", new ShaderTextureLight());
	ShaderAssets::Load("SHADER_COLOR", new ShaderColor());
	ShaderAssets::Load("SHADER_COLOR_LIGHT", new ShaderColorLight() );
	ShaderAssets::Load("SHADER_COLOR_VARY", new ShaderColorVary());

	//---------------------------------------------------------------------------------------------------------
	// Load the SkyBoxes
	//---------------------------------------------------------------------------------------------------------
	SkyBoxAssets::Load("SkyBox_ONE", 5000, ShaderAssets::Get("SHADER_TEXTURE"), TextureAssets::Get("Tex_SkyBox_ONE"));

	//---------------------------------------------------------------------------------------------------------
	// Load the Terrains
	//---------------------------------------------------------------------------------------------------------
	TerrainAssets::Load("Terrain_Grass", L"Textures/HeightMaps/LevelOne.tga", ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), Color::White, 5000, 150, 10, TextureAssets::Get("TexGrass"));
	TerrainAssets::Load("Terrain_Sand", L"Textures/HeightMaps/LevelTwo.tga", ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), Color::White, 5000, 100, 10, TextureAssets::Get("TexSand"));
	TerrainAssets::Load("Terrain_Rock", L"Textures/HeightMaps/LevelThree.tga", ShaderAssets::Get("SHADER_TEXTURE_LIGHT"), Color::White, 5000, 200, 10, TextureAssets::Get("TexHardGround"));
}
