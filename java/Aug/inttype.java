public class inttype{
	public static void main(String[] args){
		int a = 1024*1024*1024*2-1; //java int ���Ա�ʾ�������� 2G-1.
		System.out.println(a);
		//char 
		char ca = '��';	//  ��
		char cb = '\u6587';	//  ��
		System.out.println((char)(int)ca);
		System.out.println(cb);
		itox ((int) ca);
	}

	public static void itox(int i){
		if(i<0xffff && i>=0){
			int x[] = new int[4];
			int j=0;
			int cx[] = new int[4];
			while(i/16 > 0){
				x[j] = i%16;
				cx[j] = fiftof(x[j]);
				j++;
				i=i/16;
			}
			x[j]=i;
			cx[j] = fiftof(x[j]);
			System.out.print("0x");
			for(int k=3;k>=0;k--){
				System.out.print((char) cx[k]);
			}
		}
		else{
			System.out.print(" ��������ݳ�������");
		}
		System.out.println();
	}

	public static int fiftof(int a){
		char x='0';
		if(a>=0 && a<=9){
			return  a+48;
		}
		else {
			switch(a){
				case 10: x='a';break;
				case 11: x='b';break;
				case 12: x='c';break;
				case 13: x='d';break;
				case 14: x='e';break;
				case 15: x='f';break;
				default: break;
			}
			return (int) x;
		}
	}

}	
