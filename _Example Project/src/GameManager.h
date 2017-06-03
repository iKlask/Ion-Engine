#ifndef GameManager_H
#define GameManager_H

//#include "IonCore.h"

class Hud;

class GameManager
{
	enum SCENE_ID {
		MAIN_MENU,
		LEVEL_ONE,
		LEVEL_TWO,
		LEVEL_THREE,
		WIN_SCENE,
		LOSE_SCENE,
		TEST_SCENE
	};
private:
	static GameManager* ptrInstance;

	GameManager() = default;								// Private constructor
	GameManager(const GameManager&) = delete;				// Prevent copy-construction
	GameManager& operator=(const GameManager&) = delete;	// Prevent assignment
	~GameManager();											// Only this class can delete

	int num_Enemies;
	int playerHealth;
	Hud* pHud;

	static GameManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new GameManager;
		return *ptrInstance;
	};
	SCENE_ID curScene;
	void privInitialize();
	void privDelete();
	void privAddEnemy();
	void privEnemyKilled();

	void privSceneChange(SCENE_ID id);
	void privResetGameManager();
	void privNextScene();
public:
	static void Initialize() { Instance().privInitialize(); };
	static void Delete() { Instance().privDelete(); };

	static void AddEnemy() { Instance().privAddEnemy(); };
	static void EnemyKilled() { Instance().privEnemyKilled(); };

	static void SetHUDReload();
	static void SetHUDReady();
	static void SetHUD(Hud* h);
	static void PlayerHit();

	//static void WinSceneChange() { Instance().privSceneChange(SCENE_ID::WIN_SCENE); };
	//static void LoseSceneChange() { Instance().privSceneChange(SCENE_ID::LOSE_SCENE); };
	static void LevelOneSceneChange() { Instance().privSceneChange(SCENE_ID::LEVEL_ONE); };
};


#endif