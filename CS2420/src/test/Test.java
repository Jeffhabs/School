package test;

public class Test
{
	public static void main(String[] args)
	{
		mystery(2468);
	}
	public static void mystery(int number)
	{
		if (number < 10)
			System.out.print(number+ " ");
		else {
			System.out.print((number % 10) + " ");
			mystery(number / 10);
		}
	}
}
