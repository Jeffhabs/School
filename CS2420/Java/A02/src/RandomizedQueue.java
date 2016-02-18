import java.util.Iterator;

import edu.princeton.cs.introcs.StdIn;
import edu.princeton.cs.introcs.StdOut;
import edu.princeton.cs.introcs.StdRandom;


public class RandomizedQueue<Item> implements Iterable<Item>
{
	private Item[] A;
	private int N = 0;
	
	@SuppressWarnings("unchecked")
	public RandomizedQueue(){
		A = (Item[]) new Object[2];
	}
	
	public boolean isEmpty(){
		return N == 0;
	}
	
	public int size(){
		return N;
	}
	private void resize(int max) {  
        assert max >= N;  
        @SuppressWarnings("unchecked")
		Item[] temp = (Item[]) new Object[max];  
        for (int i = 0; i < N; i++) {  
            temp[i] = A[i];  
        }  
        A = temp;  
    }  
	
	public void enqueue(Item item){
		if(item == null){
			throw new java.lang.NullPointerException();
		}
		if(N == A.length) resize(2*A.length);
		A[N] = item;
		N++;	
		}
	
	public Item dequeue(){
		if(isEmpty()) throw new java.util.NoSuchElementException();
		int index = StdRandom.uniform(N);
		Item item = A[index];
		if(index != N-1){
			A[index] = A[N-1];
		}
		A[N-1] = null;
		N--;
		
		if(N > 0 && N == A.length/4) resize(A.length/2);
		return item;
	}
	
	public Item Sample(){
		if(isEmpty()) throw new java.util.NoSuchElementException();
		int index = (StdRandom.uniform(N));
		return A[index];
	}
	
	public Iterator<Item> iterator() { return new ArrayIterator(); }
	
	private class ArrayIterator implements Iterator<Item>
	{
		@SuppressWarnings("unchecked")
		private Item[] temp = (Item[]) new Object[A.length];
		
		private int tempN = N;
		public boolean hasNext() { return tempN != 0;}
		public void remove()     { throw new UnsupportedOperationException();}
		
		public ArrayIterator()
		{
			
			for(int i=0; i<A.length; i++){
				temp[i] = A[i];
			}
		}
		public Item next()
		{
			if(!hasNext()) throw new java.util.NoSuchElementException();
			int index = (StdRandom.uniform(tempN));
			Item item = temp[index];
			if(index != tempN-1)
			{
				temp[index] = temp[tempN-1];
			}
			temp[tempN-1] = null;
			tempN--;
			return item;
		}
	}
	
	public static void main(String[] args)
	{
		RandomizedQueue<String> A = new RandomizedQueue<String>();
		while(!StdIn.isEmpty())
		{
			String item = StdIn.readString();
			if(!item.equals("-")) A.enqueue(item);
			else if (!A.isEmpty()) StdOut.print(A.dequeue() + " ");
		}
		StdOut.println("(" + A.size() + " remaining on queue)");
		
	}
}
