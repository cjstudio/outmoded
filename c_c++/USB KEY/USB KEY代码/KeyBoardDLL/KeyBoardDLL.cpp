// KeyBoardDLL.cpp : ���� DLL Ӧ�ó������ڵ㡣
//

// ������뽫λ������ָ��ƽ̨֮ǰ��ƽ̨��ΪĿ�꣬���޸����ж��塣
// �йز�ͬƽ̨��Ӧֵ��������Ϣ����ο� MSDN��
#ifndef WINVER				// ����ʹ���ض��� Windows XP ����߰汾�Ĺ��ܡ�
#define WINVER 0x0501		// ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
#endif

#ifndef _WIN32_WINNT		// ����ʹ���ض��� Windows XP ����߰汾�Ĺ��ܡ�
#define _WIN32_WINNT 0x0501	// ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
#endif						

#ifndef _WIN32_WINDOWS		// ����ʹ���ض��� Windows 98 ����߰汾�Ĺ��ܡ�
#define _WIN32_WINDOWS 0x0410 // ����ֵ����Ϊ�ʵ���ֵ����ָ���� Windows Me ����߰汾��ΪĿ�ꡣ
#endif

#ifndef _WIN32_IE			// ����ʹ���ض��� IE 6.0 ����߰汾�Ĺ��ܡ�
#define _WIN32_IE 0x0600	// ����ֵ����Ϊ��Ӧ��ֵ���������� IE �������汾��
#endif

#define WIN32_LEAN_AND_MEAN		// �� Windows ͷ���ų�����ʹ�õ���

#include "windows.h"
#include "KeyBoardDLL.h"

#pragma data_seg(".mydata")
HHOOK g_hHookKbdLL=NULL;
BOOL g_bBeep=FALSE;
#pragma data_seg()
#pragma comment(linker,"/SECTION:.mydata,RWS")

HMODULE g_hInstance = NULL;

BOOL APIENTRY DllMain( HMODULE hModule,
					  DWORD  ul_reason_for_call,
					  LPVOID lpReserved
					  )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		g_hInstance = hModule;
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

KEYBOARDDLL_API LRESULT CALLBACK MyTaskKeyHookLL(int nCode,WPARAM wp,LPARAM lp)//wp��ֵ
{
	KBDLLHOOKSTRUCT *pkh=(KBDLLHOOKSTRUCT*)lp;

	if(nCode==HC_ACTION)//��Ϣ���͸�����
	{
		if(g_bBeep&&(wp==WM_SYSKEYDOWN||wp==WM_KEYDOWN))
			MessageBeep(0);
		return 1;
	}
	return CallNextHookEx(g_hHookKbdLL,nCode,wp,lp);
}

KEYBOARDDLL_API BOOL DisableTaskKeys(BOOL bDisable, BOOL bBeep)
{ 
	if(bDisable)
	{
		if(!g_hHookKbdLL)
		{
			g_hHookKbdLL = SetWindowsHookEx(WH_KEYBOARD_LL, MyTaskKeyHookLL, g_hInstance, 0);
		}
	}//WH_KEYBOARD_LL
	else if(g_hHookKbdLL!=NULL)
	{
		UnhookWindowsHookEx(g_hHookKbdLL);
		g_hHookKbdLL=NULL;
	}
	g_bBeep=bBeep;
	return AreTaskKeysDisabled();
}

KEYBOARDDLL_API BOOL AreTaskKeysDisabled()
{
	return g_hHookKbdLL!=NULL;
}