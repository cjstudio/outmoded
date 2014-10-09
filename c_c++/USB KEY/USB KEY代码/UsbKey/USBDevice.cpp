// USBDevice.cpp: implementation of the USBDevice class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UsbKey.h"
#include "USBDevice.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

USBDevice::USBDevice()
{

}

USBDevice::~USBDevice()
{

}

BOOL USBDevice::SearchDevice()
{
	
	char        HCName[16];   //USB��������
    int         HCNum;        //��� 
    PCHAR       rootHubName;  //USB Hub��
	ULONG       index;        //�˿�
    BOOL        success;      //�Ƿ�ɹ�
    HANDLE hHCDev;            //USB�������豸���
	HANDLE hHubDevice;        //USB Hub�豸���
    PUSB_NODE_CONNECTION_INFORMATION    connectionInfo;//Ҫ��ȡ�ù���USB�˿ں������豸��Ϣ
	

	for (HCNum = 0; HCNum < NUM_HCS_TO_CHECK; HCNum++)//�豸��ѯ
    {   
		//AfxMessageBox("hehe������",0,0);
        wsprintf(HCName, "\\\\.\\HCD%d", HCNum);//�ַ�����ʽ������wsprintf(������,��ʽ,Ҫ��ʽ����ֵ); 
        hHCDev = CreateFile(HCName,
                            GENERIC_WRITE,
                            FILE_SHARE_WRITE,
                            NULL,
                            OPEN_EXISTING,
                            0,
                            NULL);  //ͬ������������
		if (hHCDev == INVALID_HANDLE_VALUE)
        {    
			//AfxMessageBox("û���ҵ�USB������������",0,0);
		    continue;
		}

		ULONG           nBytes;

        rootHubName =(char*) GetRootHubName(hHCDev);//���Hub��
		//AfxMessageBox("rootHub������",0,0);
		if(rootHubName==NULL)
		{    
			//AfxMessageBox("rootHub��������",0,0);
			continue;
		}

		 PUSB_NODE_INFORMATION HubInfo;//The USB_NODE_INFORMATION structure is used with the IOCTL_USB_GET_NODE_INFORMATION I/O control request to retrieve information about a parent device.USB�ն���Ϣ
         HubInfo = (PUSB_NODE_INFORMATION)malloc(sizeof(USB_NODE_INFORMATION));//�������ݿռ�
		 PCHAR deviceName;
		 deviceName = (PCHAR)malloc(strlen(rootHubName) + sizeof("\\\\.\\"));//�����豸���ռ�
         if (rootHubName != NULL)
         {
			strcpy(deviceName, "\\\\.\\");
			strcpy(deviceName + sizeof("\\\\.\\") - 1, rootHubName);
			hHubDevice = CreateFile(deviceName,
                            GENERIC_WRITE,
                            FILE_SHARE_WRITE,
                            NULL,
                            OPEN_EXISTING,
                            0,
                            NULL);//ͬ���豸����Hub���������Ϣ
			free(deviceName);
			if (hHubDevice == INVALID_HANDLE_VALUE)
			{
				//AfxMessageBox("����豸���ʧ�ܣ�����",0,0);	
				continue;
			}
			success = DeviceIoControl(hHubDevice,
                              IOCTL_USB_GET_NODE_INFORMATION,
                              HubInfo,
                              sizeof(USB_NODE_INFORMATION),
                              HubInfo,
                              sizeof(USB_NODE_INFORMATION),
                              &nBytes,
                              NULL);//���Hub�ϵĶ˿ں����ӵ��豸��Ϣ
			if (!success)
			{
				//AfxMessageBox("���USB�豸����ʧ��!!!",0,0);
				continue;
			}

		 }
		 	
		 int port;//�˿���
		 port=HubInfo->u.HubInformation.HubDescriptor.bNumberOfPorts;
		 for (index=1; index <= port; index++)
		 {
			 ULONG nBytes;
			 nBytes = sizeof(USB_NODE_CONNECTION_INFORMATION) +
                sizeof(USB_PIPE_INFO) * 30;//���������Ϣ
			 connectionInfo = (PUSB_NODE_CONNECTION_INFORMATION)malloc(nBytes);
			 if (connectionInfo == NULL)
			 {
				 //AfxMessageBox("����ռ����!!!",0,0);
				 continue;
			 }
			 connectionInfo->ConnectionIndex = index;
			 success = DeviceIoControl(hHubDevice,
                                  IOCTL_USB_GET_NODE_CONNECTION_INFORMATION,
                                  connectionInfo,
                                  nBytes,
                                  connectionInfo,
                                  nBytes,
                                  &nBytes,
                                  NULL);//���port[index]����Ϣ
			 if (!success)
			 {
				 free(connectionInfo);
				 //AfxMessageBox("��ö˿���Ϣ����!!!",0,0);
				 continue;
			 }
			 if(connectionInfo)
	         if (connectionInfo->ConnectionStatus == DeviceConnected)
			 {
			      if(UsbKeyCheck(connectionInfo))
				  {
				       CloseHandle(hHubDevice);
				       CloseHandle(hHCDev);
				       return TRUE;
				  }
			      else
				       continue;
			 }
		 }

      }
	 			
//////////////////////////////////////////////////////////////////////////////
///////�����HID�豸��USB�ӿ���KEY�������´��룡��              //////////////
//////////////////////////////////////////////////////////////////////////////



	/*SP_DEVICE_INTERFACE_DATA devInfoData;  //�豸��Ϣ
	PSP_DEVICE_INTERFACE_DETAIL_DATA pDetail;
	_HIDD_ATTRIBUTES hidAttributes;//�豸����ʶ����ṹ��
	HANDLE hidHandle;
	int nCount;
	BOOL bResult;
	HDEVINFO hDevInfo;
	GUID guid;

	//���HID�豸���GUID
	HidD_GetHidGuid(&guid);

	//����豸��Ϣ�����
	hDevInfo=::SetupDiGetClassDevs(&guid,NULL,NULL,DIGCF_PRESENT|DIGCF_DEVICEINTERFACE);//�����豸��Ϣ��Ŀ���ѡ��DIGCF_PRESENTֻ�г���ǰ���ڵ��豸��Ϣ
	if(hDevInfo==INVALID_HANDLE_VALUE)//��ʧ���򷵻�INVALID_HANDLE_VALUE
	{
		AfxMessageBox("û���ҵ��豸�࣡��",0,0);
		return FALSE;
	}

	//�����豸�ӿ����ݿռ�
	devInfoData.cbSize=sizeof(SP_DEVICE_INTERFACE_DATA);

	nCount=0;

	::SetLastError(NO_ERROR);// ��ֹ�����ͻ
	bResult=TRUE;

	//�豸���=0��1��2��3......��һ����豸�ӿڵ�ʧ��Ϊֹ��
	while(::GetLastError()!=ERROR_NO_MORE_ITEMS)
	{

		//ö�ٷ��ϸ�GUID���豸�ӿ�
		bResult=::SetupDiEnumDeviceInterfaces(
			hDevInfo,     //�豸��Ϣ���
			NULL,         //����Ҫ������豸����
			&guid,         //GUID
			(ULONG)nCount, //�豸��Ϣ������豸���
			&devInfoData);  //�豸�ӿ���Ϣ

		if(bResult)
		{

			ULONG requiredLength=0;
			 //���������Ϣ���� requireLength
			SetupDiGetInterfaceDeviceDetail(
				hDevInfo,    //�豸��Ϣ�����
				&devInfoData, //�豸�ӿ���Ϣ
				NULL,        //ΪNULL��ʾ����������豸��Ϣ��
				             //���������Ϣ����
				0,           //�����������С
				&requiredLength,    //���������������С
				NULL);        //����Ҫ������豸����
			pDetail=(PSP_DEVICE_INTERFACE_DETAIL_DATA)::GlobalAlloc(LMEM_ZEROINIT,INTERFACE_DETAIL_SIZE);//�ú������ڴ�ȫ�ֶ��з�����ڴ湩����ʹ�á�LMEM_ZEROINIT�ڴ��ʼ��Ϊ�㣬����INTERFACE_DETAIL_DATA���ֽڡ�
			pDetail->cbSize=sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);


			if(!SetupDiGetInterfaceDeviceDetail(
				hDevInfo,    //�豸��Ϣ�����
				&devInfoData, //�豸�ӿ���Ϣ
				pDetail,       //�豸�ӿ�ϸ��
				requiredLength, //���������������С
				NULL,       //���û���豸��Ϣ
				NULL      //���ö�����豸����
				))
			{
				AfxMessageBox("����豸ϸ����Ϣʧ�ܣ�����",0,0);
				free(pDetail);
				nCount++;
				continue;
			}
			AfxMessageBox(pDetail->DevicePath,0,0);
			hidHandle=CreateFile(pDetail->DevicePath,
				                GENERIC_READ|GENERIC_WRITE,
								FILE_SHARE_READ|FILE_SHARE_WRITE,
			                    NULL,OPEN_EXISTING,               //�½��ļ����ļ�������ʱ����ΪOPEN_EXISTING
								FILE_FLAG_OVERLAPPED,NULL);//ʧ�ܷ���INVALID_HANDLE_VALUE
			if(hidHandle==INVALID_HANDLE_VALUE)
			{
				AfxMessageBox("����豸���ʧ�ܣ�����",0,0);
				//return FALSE;
				nCount++;
				continue;
			}
			if(!HidD_GetAttributes(hidHandle,&hidAttributes))//���USB�豸����
			{
				AfxMessageBox("���USB�豸����ʧ��!!!",0,0);
				CloseHandle(hidHandle);
				//return FALSE;
				nCount++;
				continue;
			}
			if(hidAttributes.VendorID==0x1241&&
			   hidAttributes.ProductID==0x1503&&
			   hidAttributes.VersionNumber==0x290)//�жϸ�USB�豸����Ϣ�Ƿ������Key���
			{	AfxMessageBox("xxx",0,0);
				return TRUE;
			}
			CloseHandle(hidHandle);
			nCount++;

		}
	}*/
	CloseHandle(hHubDevice);
	CloseHandle(hHCDev);
	//AfxMessageBox("û���ҵ���ȷ��USB KEY!!!",0,0);
	return FALSE;

}

PCHAR USBDevice::GetRootHubName(HANDLE HostController)
{  // AfxMessageBox("����GETHub������",0,0);
	BOOL                success;
    ULONG               nBytes;
    USB_ROOT_HUB_NAME   rootHubName;
    PUSB_ROOT_HUB_NAME  rootHubNameW;
    PCHAR               rootHubNameA;

    rootHubNameW = NULL;
    rootHubNameA = NULL;

   success = DeviceIoControl(HostController,
                              IOCTL_USB_GET_ROOT_HUB_NAME,
                              0,
                              0,
                              &rootHubName,
                              sizeof(rootHubName),
                              &nBytes,
                              NULL);

    if (!success)
    {   //AfxMessageBox("���ɹ�������",0,0);
        goto GetRootHubNameError;
    }

    nBytes = rootHubName.ActualLength;

    rootHubNameW =(PUSB_ROOT_HUB_NAME) malloc(nBytes);

    if (rootHubNameW == NULL)
    {

        goto GetRootHubNameError;
    }

    success = DeviceIoControl(HostController,
                              IOCTL_USB_GET_ROOT_HUB_NAME,
                              NULL,
                              0,
                              rootHubNameW,
                              nBytes,
                              &nBytes,
                              NULL);

    if (!success)
    {
       goto GetRootHubNameError;
    }

    rootHubNameA = WideStrToMultiStr(rootHubNameW->RootHubName);
    free(rootHubNameW);

    return rootHubNameA;


GetRootHubNameError:
    if (rootHubNameW != NULL)
    {
        free(rootHubNameW);
        rootHubNameW = NULL;
		//AfxMessageBox("��������",0,0);
    }

    return NULL;

}

PCHAR USBDevice::WideStrToMultiStr(PWCHAR WideStr)
{
	ULONG nBytes;
    PCHAR MultiStr;
    nBytes = WideCharToMultiByte(
                 CP_ACP, // code page
                 0,      // performance and mapping flags
                 WideStr,// address of wide-character string
                 -1,     // number of characters in string
                 NULL,   // address of buffer for new string

                 0,      // size of buffer

                 NULL,   // address of default for unmappable 
                         // characters

                 NULL    // address of flag set when default 
                             // char. used

				 );  

    if (nBytes == 0)
    {
        return NULL;
    }
    MultiStr =(PCHAR) malloc(nBytes);

    if (MultiStr == NULL)
    {
        return NULL;
    }
    nBytes = WideCharToMultiByte(
                 CP_ACP,
                 0,
                 WideStr,
                 -1,
                 MultiStr,
                 nBytes,
                 NULL,
                 NULL);

    if (nBytes == 0)
    {
        free(MultiStr);
        return NULL;
    }

    return MultiStr;

}

BOOL USBDevice::UsbKeyCheck(PUSB_NODE_CONNECTION_INFORMATION connectionInfo)//USBKEY������֤
{
	 if(connectionInfo->DeviceDescriptor.idVendor==0x781&&
	 connectionInfo->DeviceDescriptor.idProduct==0x5530&&
	 connectionInfo->DeviceDescriptor.iManufacturer==0x1&&
	 connectionInfo->DeviceDescriptor.iSerialNumber==0x3)////�жϸ�USB�豸����Ϣ�Ƿ������Key���
	 {
	     //AfxMessageBox("��������ȷ��USB KEY!!!",0,0);
	     return TRUE;
	 }
     else
         return FALSE;
}
