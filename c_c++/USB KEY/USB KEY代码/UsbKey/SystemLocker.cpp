// SystemLocker.cpp: implementation of the SystemLocker class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UsbKey.h"
#include "SystemLocker.h"
#include "UsbKeyDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SystemLocker::SystemLocker()
{
 bDisable=FALSE;
}

SystemLocker::~SystemLocker()
{

}

BOOL SystemLocker::Lock()
{   //MessageBox(0,"����ϵͳ��������","����������",MB_OK);
	bDisable=TRUE;
	return mouselocker.Lock()&&keyboardlocker.Lock();

}

BOOL SystemLocker::Unlock()
{
	bDisable=FALSE;
	return mouselocker.Unlock()&&keyboardlocker.Unlock();

}

BOOL SystemLocker::LoadDLL()
{
	try //�쳣��׽
	{
		mouselocker.LoadDLL();
		keyboardlocker.LoadDLL();
		return TRUE;
	}
	catch(CException E)
	{
		MessageBox(0,"���ض�̬���ӿ�ʧ�ܣ�����","���󣡣���",MB_OK);
		return FALSE;
	}

}

BOOL SystemLocker::Isdisable()
{
	return bDisable;

}

BOOL SystemLocker::UnloadDLL()
{
	try //�쳣��׽
	{
		mouselocker.UnloadDLL();
		keyboardlocker.UnloadDLL();
		return TRUE;
	}
	catch(CException E)
	{
		MessageBox(0,"ж�ض�̬���ӿ�ʧ�ܣ�����","���󣡣���",MB_OK);
		return FALSE;
	}

}