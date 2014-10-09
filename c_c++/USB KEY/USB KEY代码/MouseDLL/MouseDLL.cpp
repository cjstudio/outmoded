// MouseDLL.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "MouseDLL.h"
HHOOK hhkHook=NULL;//���平�Ӿ��
HINSTANCE hInstance=NULL;

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    hInstance=(HINSTANCE)hModule;
    return TRUE;
}


// This is an example of an exported variable
MOUSEDLL_API int nMouseDLL=0;

// This is an example of an exported function.
MOUSEDLL_API int fnMouseDLL(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see MouseDLL.h for the class definition
//CMouseDLL::CMouseDLL()
//{ 
//	return; 
//}
LRESULT CALLBACK HookProc(int nCode,WPARAM wParam,LPARAM lParam)//��Ϣ������ �ص�����
{

	if(nCode<0)
	{
		return CallNextHookEx(hhkHook,nCode,wParam,lParam);//ѭ�����ù��ӱ�֤��������Ϣ���Ķ���
	}
	if(nCode!=HC_ACTION)
	{
		return CallNextHookEx(hhkHook,nCode,wParam,lParam);
	}
	return 1;//ʹ��겻�����ã�������
}
//��������������������� 
MOUSEDLL_API BOOL EnableMouseLock()
{
	if(!(hhkHook=SetWindowsHookEx(WH_MOUSE,(HOOKPROC)HookProc,hInstance,0)))//��װ����
		return FALSE;
	return TRUE;
}
//��������������������
MOUSEDLL_API BOOL DisableMouseLock()
{
	return UnhookWindowsHookEx(hhkHook);//ж�ع���
}
