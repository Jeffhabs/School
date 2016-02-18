
import edu.princeton.cs.algs4.WeightedQuickUnionUF;


public class Percolation
{
	public Boolean [][] my2DArray;
	public WeightedQuickUnionUF myQUF;
	public int size;
	public int bottomIndexKey;
	public int topIndexKey = 0;
	public int counter = 0;
	public Percolation(int N)           //create N-by-N grid, with all sites blocked
	{
		size = N;
		bottomIndexKey = size * size + 2;
		my2DArray = new Boolean[N][N];
		myQUF = new WeightedQuickUnionUF(bottomIndexKey);
		for(int i=0; i< N; i++){
			for(int j=0; j< N; j++){
				my2DArray[i][j] = false;
			}
				
		}
	}
	public void open(int i, int j)      // open site (row i, column j) if it is not open already
	{
		if(i < 0 || i > size - 1 || j < 0 || j > size - 1) {
			throw new IndexOutOfBoundsException("row index" + i + " must be between 0 and " + (size-1));
		}
		int qufIndex = singleArray(i, j);
		my2DArray[i][j] = true;
		counter++;
		
		if(i!=0 && isOpen(i-1, j))
		{
			myQUF.union(qufIndex, singleArray(i-1, j)); 
		}
		if(i != size-1 && isOpen(i+1, j))
		{
			myQUF.union(qufIndex, singleArray(i+1, j));
		}
		if(j !=0 && isOpen(i, j-1))
		{
			myQUF.union(qufIndex, singleArray(i, j-1));
		}
		if(j != size-1 && isOpen(i, j+1))
		{
			myQUF.union(qufIndex, singleArray(i, j+1));			
		}
		if(i == 0)
		{
			myQUF.union(singleArray(i, j), topIndexKey);
		}
		if(i == size-1)
		{
			myQUF.union(singleArray(i, j), bottomIndexKey-1);
		}
	}
	public boolean isOpen(int i, int j) // is site (row i, column j) open?
	{
		return my2DArray[i][j];
	}
	public boolean isFull(int i, int j) // is site (row i, column j) full?
	{
		if(isOpen(i, j) && myQUF.connected(singleArray(i, j), topIndexKey))
		{
			return true;
		}
		return false;
	}
	public boolean percolates() 	    // does the system percolate?
	{
		return (myQUF.connected(bottomIndexKey-1, topIndexKey));		
	}
	public int numberOfOpenSites()
	{
		return counter;
	}
	private int singleArray(int i, int j)
	{		//convert 2Darray to 1Darray
		int my1DArray = (i * size) + j+1;
		return my1DArray;		
	}
	
}
