package PBook;


public class CBookMain 
{
	public static void main(String[] args)
	{
		CBook book = new CBook();
		book.name = "ɽ���֮��";
		System.out.println(book.name);
		CUser person1 = new CUser();
		CStudent person2 = new CStudent();
		System.out.println(person1.id);
		System.out.println(person2.id + " " + person2.GetProf());
	}
}
