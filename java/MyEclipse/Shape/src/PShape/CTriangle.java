package PShape;

// ��������

public class CTriangle extends CShape 
{
	CPoint A,B,C;	// ������λ��
	double a,b,c;	// ���߱߳�
	
	public CTriangle(){}
	
	public CTriangle(CPoint a ,CPoint b, CPoint c)
	{
		this.A = a;
		this.B = b;
		this.C = c;
	}
	
	public void initialization()
	{
		this.a = this.A.Distance(this.B);
		this.b = this.B.Distance(this.C);
		this.c = this.C.Distance(this.A);
		
	}

	public double Area() 
	{
		return a+b+c;
	}

	public double Perimeter() 
	{
		return a+b+c;
	}

}
