// MouseLocker.cpp: implementation of the MouseLocker class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UsbKey.h"
#include "MouseLocker.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MouseLocker::MouseLocker()
{

}

MouseLocker::~MouseLocker()
{

}
BOOL MouseLocker::Lock()//�������
{   //MessageBox(0,"������꣡����","����������",MB_OK);
	if(loadhook!=NULL)
	{   //MessageBox(0,"�������1������","����������",MB_OK);
		loadhook();//����MouseDLL.dll���������
		return TRUE;
	}
	return TRUE;

}

BOOL MouseLocker::Unlock()//����
{
	if(unloadhook!=NULL)
	{
        unloadhook();//����MouseDLL.dll���������
	    return TRUE;
	}
	return FALSE;
}

BOOL MouseLocker::LoadDLL()
{
    hMouseLockerDLL=::LoadLibrary("MouseDLL.dll"); //����DLL
	//hMouseLockerDLL = ::LoadLibrary("../MouseDLL/Debug/MouseDLL.dll");
	if(hMouseLockerDLL!=NULL)
	{
		loadhook=(LOADMOUSEHOOK)GetProcAddress(hMouseLockerDLL,"EnableMouseLock");
		//loadhookָ��MouseDLL.dll�������������

		unloadhook=(UNLOADMOUSEHOOK)GetProcAddress(hMouseLockerDLL,"DisableMouseLock");
		//unloadhookָ��MouseDLL.dll�Ľ�������

		if(loadhook==NULL||unloadhook==NULL)
		{
			MessageBox(0,"��������ʧ�ܣ�����","���غ������󣡣���",MB_OK);
			return FALSE;
		}
		return TRUE;
	}
	MessageBox(0,"��̬���ӿ����ʧ�ܣ�����","�������п���󣡣���",MB_OK);
	return FALSE;
}


void MouseLocker::UnloadDLL() //�ͷ����ӿ���Դ
{
    ::FreeLibrary(hMouseLockerDLL);
}