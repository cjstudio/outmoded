import java.util.Random;
import java.util.Scanner;

public class Fuck {
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int a,n,i,number;
		System.out.print("What areo would you have?\n");
		a = scan.nextInt();
		System.out.print("How many would you have?\n");
		n = scan.nextInt();
		Random numx = new Random();
		System.out.print("Random number is \n");
		for(i=0;i<n;i++)
		{
			number = numx.nextInt(a);
			if(0 == i%5 && 0 != i)
				System.out.println("");
			//number = (int) (Math.random()*a);
			System.out.print(number+"\t");
		}
	}

}
