package PTESTF;

public class test1
{
	public static void main(String[] args)
	{
		String str="�й����п��й��ģ��й� ʮ�ֵ��й�˵��";		
		int n = str.indexOf("�й�") ;
		int index = 0 ;
		while(-1 != n)
		{
			index ++;
			n =  str.indexOf("�й�",n+1);
		}

		System.out.println(index);
	}
}