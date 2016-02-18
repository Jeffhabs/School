import java.util.Iterator;

import edu.princeton.cs.introcs.StdOut;


public class Deque<Item> implements Iterable<Item>
{
	private int N;      	//Number of elements in queue
	private Node first; 	//start of queue
	private Node last;		//end of queue
	
	private class Node
	{
		private Item item;
		private Node next;
		private Node last;
	}
	
	public Deque()
	{
		first = null;
		last = null;
		N = 0;
	}	
	
	public boolean isEmpty()
	{
		return N == 0;
	}
	
	public int size()
	{
		return N;
	}
	
	public void addFirst(Item item)
	{
		if(item == null)
		{
			throw new java.lang.NullPointerException();
		}
		Node oldFirst = first;
		first = new Node();
		first.item = item;
		first.last = null;
		if(isEmpty())
		{
			last = first;
			first.next = null;
		}
		else
		{
			oldFirst.last = first;
			first.next = oldFirst;
		}
		N++;		
	}
	
	public void addLast(Item item)
	{
		if(item == null)
		{
			throw new java.lang.NullPointerException();
		}
		Node oldLast = last;
		last = new Node();
		last.item = item;
		last.next = null;
		if(isEmpty())
		{
			first = last;
			last.last = null;			
		}
		else {
			oldLast.next = last;
			last.last = oldLast;
		}
		N++;
	}
	
	public Item removeFirst()
	{
		if(isEmpty())
		{
			throw new java.util.NoSuchElementException();
		}
		Item item = first.item;
		first = first.next;
		N--;
		if(isEmpty())
		{
			last = null;
			first = null;
		}
		else {
			first.last = null;
		}
		return item;
	}
	
	public Item removeLast()
	{
		if(isEmpty())
		{
			throw new java.util.NoSuchElementException();			
		}
		Item item = last.item;
		last = last.last;
		N--;
		if(isEmpty())
		{
			last = null;
			first = null;
		}
		else {
			last.next = null;
		}	
		return item;
	}
	
	public Iterator<Item> iterator()
	{
		return new ListIterator();
	}
	
	public class ListIterator implements Iterator<Item>
	{
		private Node current = first;
		
		public boolean hasNext() { return current != null; }
		public void remove()     { throw new java.lang.UnsupportedOperationException(); }
		
		public Item next()
		{
			if (!hasNext()) throw new java.util.NoSuchElementException();
			Item item = current.item;
			current = current.next;
			return item;
		}
		
	}
	public static void main(String[] args)
	{
		Deque<String> s = new Deque<String>();
		s.addFirst("l");
		s.addLast("o");
		s.addFirst("l");
		s.addFirst("e");
		s.addFirst("h");
		s.addFirst("M");
		s.removeFirst();
		s.addLast("!");
		s.removeLast();	
		
		for(String i: s){
			StdOut.print(i);
		}
		
	}
}
