package PTest;

public class CMain
{	
	public static int it = 11111;

	public static void main(String[] args)
	{
		ITest test = null;
		String str="���п��й��ģ��й� ʮ�ֵ�˵��";
		String s = "�й�";
		
		int n = 0, index =-1 ;
		do
		{
			n =  str.indexOf("�й�",n+1);
			System.out.println(n);
			index ++;
			
		}while(-1!=n);
		//System.out.println(index);

		switch (it)
		{
		case 0:
			test = new CTest();
			break;

		case 1:
			test = new CStringTest();
			break;

		case 2:
			test = new CRegexTest();
			break;

		case 3:
			test = new CTimeTest();
			break;

		case 4:
			test = new CExceptionTest();
			break;

		case 5:
			test = new CFileTest();
			break;

		case 6:
			test = new CDialogTest();
			break;

		default:
			return;
		}

		// test = new CRegextest();
		// test = new CStringtest();
		// test = new CTimetest();
		// test = new CCollectiontest();
		test.test();

	}
}
