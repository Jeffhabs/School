package test;

public class Binary 
{
	public static int binary(int[] a, int key)
	{
		int min = 0, max = a.length -1;
		while(min <= max)
		{
			int middle = (min+max) /2;
			if (a[middle] == key)
			{
				return middle;
			}
			if (a[middle] < key)
			{
				min = middle + 1;
			}
			if (a[middle] > key)
			{
				min = middle -1;
			}	
		}
		return -1;
		
	}
}
