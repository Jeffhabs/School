package test;

public class LinkedListExample
{
	public static void main(String[] args)
	{
		LinkedList theList = new LinkedList();
		theList.add("The Clash");
		theList.add("The Cure");
		theList.add("Crash Test Dummies", 2);
		theList.add("Monkeys");
		theList.add("The Cars");
		System.out.println(theList.toString());
		theList.remove(2);
		System.out.print(theList.toString());
	}
}
