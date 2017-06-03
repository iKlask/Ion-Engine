
#include "IonEngine.h"
#include "WindowRenderer.h"

int WINAPI wWinMain(_In_ HINSTANCE , _In_opt_ HINSTANCE, _In_ LPWSTR, _In_ int )
{
	IonEngine::Run();	//	Game Loop
	return 0;
}