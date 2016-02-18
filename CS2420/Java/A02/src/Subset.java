import edu.princeton.cs.introcs.StdIn;
import edu.princeton.cs.introcs.StdOut;

public class Subset
{  
    public static void main(String[] args)
    { 
        RandomizedQueue<String> q = new RandomizedQueue<String>();  
        StdOut.print("Enter letters with space in between each character:\n"); //prompt user to enter characters
        String s = StdIn.readLine();		
        String[] r = s.split(" ");		  //split the letters on white space and save it into an array
        StdOut.print("Enter a number to randomize:\n");		//prompt the user to enter number of randomizations
     
        for(int i = 0; i < r.length; i++)
        {
        	q.enqueue(r[i]);	//enqueue the characters from the array
        }
        
        int k = StdIn.readInt();
        System.out.println();
        for (int i = 0; i < k; i++)
        {           	
            StdOut.println(q.dequeue());  //dequeue the array
              
        }  
    }  
}  
