// KeyBoardLocker.cpp: implementation of the KeyBoardLocker class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UsbKey.h"
#include "KeyBoardLocker.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

KeyBoardLocker::KeyBoardLocker()
{

}

KeyBoardLocker::~KeyBoardLocker()
{

}
BOOL KeyBoardLocker::LoadDLL()
{
	hKeyBoardLockerDLL=::LoadLibrary("KeyBoardDLL.dll");//����DLL
	//hKeyBoardLockerDLL=::LoadLibrary("../KeyBoardDLL/Debug/KeyBoardDLL.dll");//����DLL
	if(hKeyBoardLockerDLL!=NULL)
	{
		lockKeyBoard=(KEYBOARDLOCKER)GetProcAddress(hKeyBoardLockerDLL,"DisableTaskKeys");
		if(lockKeyBoard==NULL)
		{
			MessageBox(0,"��������ʧ�ܣ�����","���غ������󣡣���",MB_OK);
			return FALSE;
		}
		//MessageBox(0,"��������3","����",MB_OK);
		return TRUE;
	}
	MessageBox(0,"��̬���ӿ����ʧ�ܣ�����","�������п���󣡣���",MB_OK);
	return FALSE;

}

BOOL KeyBoardLocker::Lock()//��������
{   //MessageBox(0,"��������1","����",MB_OK);
	if(lockKeyBoard!=NULL)
	{   //MessageBox(0,"��������2","����",MB_OK);
		lockKeyBoard(TRUE,FALSE);
		return TRUE;
	}
	return FALSE;
 
}

BOOL KeyBoardLocker::Unlock()//����
{
	if(lockKeyBoard!=NULL)
	{
		lockKeyBoard(FALSE,FALSE);
		return TRUE;
	}
	return FALSE;

}

void KeyBoardLocker::UnloadDLL()
{
	::FreeLibrary(hKeyBoardLockerDLL);

}
