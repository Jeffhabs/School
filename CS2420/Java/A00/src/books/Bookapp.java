package books;
import java.util.*;
public class Bookapp
{
	public static void main(String[] args)
	{
		
		ArrayList<Book> MyBooks =  Book.getList("books.csv");
		Collections.sort(MyBooks);
		//Collections.sort(MyBooks, Book.BY_AUTHOR);
		Collections.sort(MyBooks, Book.BY_DATE);
		System.out.println("\nSorted book list:");
		for(Book i: MyBooks)
		{
			System.out.println(i);
		}
		Collections.reverse(MyBooks);
		System.out.println("\nReverse order:");
		for(Book i: MyBooks)
		{
			System.out.println(i);
		}
	}

}
