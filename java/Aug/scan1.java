//���ڼ�������Ļ�ȡ
// 
import java.util.Scanner;
public class scan1
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		System.out.print("Enter your name:");
		String name=in.next();
		System.out.print("Enter your age:");
		int age=in.nextInt();
		System.out.print("name:"+name+"\n");
		System.out.print("age:"+age);
	}
}
