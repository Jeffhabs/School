package test;

public class Linear
{
	
	public static int linear (int[] a, int key)
	{
		int index = -1;
		for(int i = 0; i < a.length; i++)
		{
			if(a[i] == key)
			{
				index = i;
				break;
			}
				
		}
		return index;
	}
	
	public static void main (String[] args)
	{
		
	}

}
