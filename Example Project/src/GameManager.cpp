#include "GameManager.h"

#include "Tank.h"
#include "EnemyTank.h"

#include "BulletFactory.h"
#include "Hud.h"

#include "FollowCam.h"
#include "FirstPersonCam.h"
#include "EnemyFactory.h"

#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"


#include "MainMenuScene.h"
#include "WinScene.h"
#include "LoseScene.h"

#include "RenderTestScene.h"



GameManager* GameManager::ptrInstance = nullptr;

void GameManager::privInitialize()
{
	num_Enemies = 0;
	playerHealth = 5;
	pHud = nullptr;
	//privSceneChange(SCENE_ID::TEST_SCENE);
	privSceneChange(SCENE_ID::MAIN_MENU);

}

void GameManager::privDelete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

void GameManager::privAddEnemy()
{
	Instance().num_Enemies++;
}

void GameManager::privEnemyKilled()
{
	num_Enemies--;
	if (num_Enemies <= 0) {
		privNextScene();
	}
}

void GameManager::privSceneChange(SCENE_ID id)
{
	privResetGameManager();

	switch (id)
	{
	case SCENE_ID::LEVEL_ONE:
		//privTankSceneChange();
		curScene = LEVEL_ONE;
		SceneManager::SceneChange(new LevelOne());
		break;
	case SCENE_ID::LEVEL_TWO:
		curScene = LEVEL_TWO;
		SceneManager::SceneChange(new LevelTwo());
		break;
	case SCENE_ID::LEVEL_THREE:
		curScene = LEVEL_THREE;
		SceneManager::SceneChange(new LevelThree());
		break;
	case SCENE_ID::WIN_SCENE:
		//privWinSceneChange();
		curScene = WIN_SCENE;
		SceneManager::SceneChange(new WinScene());
		break;
	case SCENE_ID::LOSE_SCENE:
		//privLoseSceneChange();
		curScene = LOSE_SCENE;
		SceneManager::SceneChange(new LoseScene());
		break;
	case SCENE_ID::MAIN_MENU:
		//privMainMenuChange();
		curScene = MAIN_MENU;
		SceneManager::SceneChange(new MainMenuScene());
		break;
	case SCENE_ID::TEST_SCENE:
		curScene = TEST_SCENE;
		SceneManager::SceneChange(new RenderTestScene());
		break;
	default:
		break;
	}
}

void GameManager::privResetGameManager()
{
	num_Enemies = 0;
	playerHealth = 5;
	pHud = nullptr;
}

void GameManager::privNextScene()
{
	switch (curScene)
	{
	case SCENE_ID::LEVEL_ONE:
		privSceneChange(SCENE_ID::LEVEL_TWO);
		break;
	case SCENE_ID::LEVEL_TWO:
		privSceneChange(SCENE_ID::LEVEL_THREE);
		break;
	case SCENE_ID::LEVEL_THREE:
		privSceneChange(SCENE_ID::WIN_SCENE);
		break;
	}
}

void GameManager::SetHUDReload()
{
	if (Instance().pHud != nullptr) {
		Instance().pHud->SetReload();
	}
}

void GameManager::SetHUDReady()
{
	if (Instance().pHud != nullptr) {
		Instance().pHud->SetReady();
	}
}

void GameManager::SetHUD(Hud * h)
{
	Instance().pHud = h;
	for (int i = 0; i < Instance().playerHealth; i++) {
		Instance().pHud->AddHealthBar();
	}
}

void GameManager::PlayerHit()
{
	//*
	Instance().playerHealth--;
	if (Instance().pHud != nullptr) {
		Instance().pHud->RemoveHealthBar();
	}
	//*/
	if (Instance().playerHealth <= 0) {
		Instance().privSceneChange(SCENE_ID::LOSE_SCENE);
	}
}

GameManager::~GameManager()
{
}
