package PTest;

import java.util.Scanner;

public class CTestMain
{
	
//	public static void main(String[] args)
//	{
//		double r,h;
//		Scanner scan = new Scanner(System.in);
//		System.out.print("����Բ����ĵ���뾶��");
//		r = scan.nextDouble();
//		System.out.print("����Բ����ĸߣ�");
//		h = scan.nextDouble();
//		System.out.println("��Բ��������Ϊ��" + Math.PI *r *r *h);
//		
//	}
	
	public static void main(String argv[])
	{
		for(int i=0;i<34;i++)//�������33ƥ 
			for(int j=0;j<51;j++)//С�����50ƥ 
				for(int k=0;k<101;k++)//������100ƥ,��Ϊ�������� 
				{ 
					if ((i*3+j*2+k/2)==100 && (i+j+k)==100 )//�����ж�,�Ƿ����� 
							System.out.println("���ǣ�����"+i+"ƥ,����"+j+"ƥ,���"+k+"ƥ��" ); 
				} 
	}
}
