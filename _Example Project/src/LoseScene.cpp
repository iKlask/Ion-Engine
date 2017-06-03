#include "LoseScene.h"
#include "LoseScreenObject.h"

void LoseScene::Initialize()
{
	obj = new LoseScreenObject();
}

void LoseScene::SceneEnd()
{
	
}

LoseScene::~LoseScene()
{
	delete obj;
}
