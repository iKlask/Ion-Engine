#include "WinScene.h"
#include "WinScreenObject.h"

void WinScene::Initialize()
{
	obj = new WinScreenObject();
}

void WinScene::SceneEnd()
{
}

WinScene::~WinScene()
{
	delete obj;
}
