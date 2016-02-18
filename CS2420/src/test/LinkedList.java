package test;

public class LinkedList
{
	private Node head;
	private int listCount;
	public LinkedList()
	{
		head = new Node(null);
		listCount = 0;
	}
	
	public void add(Object j)
	{
		Node temp = new Node(j);
		Node current = head;
		
		while(current.getNext() != null)
		{
			current = current.getNext();
		}
		current.setNext(temp);
		listCount++;
	}
	public void add(Object j, int index)
	{
		if(index > 0 && index <= listCount)
		{	
			Node temp = new Node(j);
			Node current = head;
			for (int i = 1; i < index && current.getNext() != null; i++) {
				current = current.getNext();
			}

			temp.setNext(current.getNext());
			current.setNext(temp);
			listCount++;
		}
		else
		{
			System.out.println("Not inside the list");

		}
	}
	
	public boolean remove(int index)
	{
		if(index < 1 || index > listCount)
			return false;
		
		Node current = head;
		for(int i = 1; i < index; i++)
		{
			if(current.getNext() == null)
				return false;
			current = current.getNext();		
		}
		current.setNext(current.getNext().getNext());
		listCount--;
		return true;
		
	}
	
	public int size()
    {
        return listCount;
    }
 
    public String toString() 
    {
        Node current = head.getNext();
        String output = "";
        while (current != null) {
            output += "[" + current.getData().toString() + "]";
            current = current.getNext();
        }
        return output;
    }
}
