package test;
import java.util.*;
import edu.princeton.cs.introcs.StdOut;

public class Queue
{
	private static void mystery1(Queue<Float> q)
	{
		int size = q.size();
		for(int i = 0; i < size; i++)
		{
			Float n = q.remove();
			if(n>0)
			{
				q.add(n);
			}
		}
		System.out.println(q);
	}
	public static void main(String[] Args)
	{
		Queue<Integer>
	}
}