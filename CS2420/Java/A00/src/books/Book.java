package books;
import java.util.*;
import java.io.*;
import java.util.regex.Pattern;
//Jeff Haberle
//5/22-5/29 2015
//Book class to compare, sort, and reverse books
//by title, author, year

//constructor uses comparable see java.util
//private fields for title, year, author
//return methods for the fields respectively
public class Book implements Comparable<Book>
{
	public static final Comparator<Book> BY_AUTHOR = new ByAuthor();
	public static final Comparator<Book> BY_DATE = new ByDate();
	private String title;
	private String author;
	private int year;
	
	public Book(String title, String author, int year)
	{
		super();
		this.title = title;
		this.author = author;
		this.year = year;
	}

	public String getTitle() {
		return title;
	}

	public String getAuthor() {
		return author;
	}

	public int getYear() {
		return year;
	}

	@Override
	//format of our string method to return
	public String toString()
	{
		return  title + " by " + author + "("+year+")";				
	}

	//creates our list of books, the number of books, the file input
	//and pattern for string to compare
	public static ArrayList<Book> getList(String file)
	{
		ArrayList<Book> MyBooks = new ArrayList<Book>();
		int numOfBooks = 0;
		File readIn = new File(file);
		//parse the data to check against the following string pattern
		String pattern = "[^,]*,[^,]*,\\d{4}";
		try
		{			
			Scanner inputStream = new Scanner(readIn);
			while(inputStream.hasNext())
			{
				String data = inputStream.nextLine();
				//check each line against our string pattern
				//if it matches, increment our book count
				//create instance of Book
				//and add it to our list of Books (MyBooks)
				if(Pattern.matches(pattern, data))
				{
					numOfBooks++;
					String[] newString = data.split(",");
					Book newBook = new Book(newString[0], newString[1], Integer.parseInt(newString[2]));
					MyBooks.add(newBook);
					
				}
				//if it does not match print error message
				else
				{
					System.err.println("Problem reading in \""+data+"\"");
				}
			}
			System.out.println("Number of books read in: " + numOfBooks);
		}
		catch (FileNotFoundException e)
		{
			e.printStackTrace();
		}
		
		return MyBooks;
	}
	@Override
	public int compareTo(Book o) {
		// TODO Auto-generated method stub
		return this.getTitle().compareTo(o.getTitle());
	}
	
	
	private static class ByAuthor implements Comparator<Book>
	{
		public int compare(Book v, Book w)
		{
			return v.author.compareTo(w.author);
		}
	}
	private static class ByDate implements Comparator<Book>
	{
		public int compare(Book v, Book w)
		{
			return v.year - w.year;
		}
	}
}
