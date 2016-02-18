import java.util.*;

public class Term implements Comparable<Term>
{

	public Term(String query, double weight)
	{
		
	}
	
	public static Comparator<Term> byReverseWeightOrder()
	{
		return null;
		
	}
	
	public static Comparator<Term> byPrefixOrder(int r)
	{
		return null;
		
	}
	
	// Return a string representation of the term in the following format:
    // the weight, followed by a tab, followed by the query.
    public String toString()
    {
		return null;
    	
    }

	@Override
	public int compareTo(Term o) {
		// TODO Auto-generated method stub
		return 0;
	}
}
