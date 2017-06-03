#include "IonEngine.h"
#include "SceneManager.h"
#include "GameManager.h"

#include "Vect.h"
#include "Enum.h"
#include "Color.h"

void IonEngine::InitializeEngine()
{
	//Creates and Sets first scene
	//SceneManager::SceneChange(new LevelOne());
	GameManager::Initialize();

	// IonEngine Window Device setup
	IonEngine::SetWindowName("Ion Engine");
	IonEngine::SetWidthHeight(1280, 720);
	IonEngine::SetBackgroundColor(Color::AliceBlue);
	IonEngine::setVsync(false);
	IonEngine::EnableDebugTitle(true);
	IonEngine::setDXReport(true);
}

void IonEngine::EngineEnd()
{
	GameManager::Delete();
}


