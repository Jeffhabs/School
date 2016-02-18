package test;

public class Node 
{
	
	Node next;
	Object data;
	
	public Node(Object _data)
	{
		next = null;
		data = _data;
	}
	
	// another Node constructor if we want to
	// specify the node to point to.
	public Node(Object _data, Node _next)
	{
		next = _next;
		data = _data;
	}
	
	//these methods should be self-explanatory
	public Object getData()
	{
		return data;		
	}
	
	public void setData(Object _data)
	{
		data = _data;
	}
	
	public Node getNext()
	{
		return next;
	}
	
	public void setNext(Node _next)
	{
		next = _next;
	}

}
