/*
	THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
				http://dev-c.com			
			(C) Alexander Blade 2015
*/

#include "..\..\inc\main.h"
#include "script.h"
#include "keyboard.h"

namespace std{
	class thread;
}

BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID lpReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		scriptRegister(hInstance, ScriptMain);
//		scriptRegisterAdditionalThread(hInstance, AlignCameraLoop);
		scriptRegisterAdditionalThread(hInstance, AgentCom);
//		presentCallbackRegister(PresentHooky);
		keyboardHandlerRegister(OnKeyboardMessage);
		break;
	case DLL_PROCESS_DETACH:
		scriptUnregister(hInstance);
//		presentCallbackUnregister(PresentHooky);
		keyboardHandlerUnregister(OnKeyboardMessage);
		break;
	}		
	return TRUE;
}