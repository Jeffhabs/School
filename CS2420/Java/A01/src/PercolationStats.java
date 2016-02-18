import edu.princeton.cs.introcs.StdRandom;
import edu.princeton.cs.introcs.StdStats;


public class PercolationStats
{
	 private double[] floatList;
	 public int numberOfRuns;
	    
	    public PercolationStats(int N, int T) {
	        if (N <= 0 || T <= 0) {
	            throw new IllegalArgumentException();
	        }
	        
	        numberOfRuns = T;
	        Percolation percolation;
	        
	        floatList = new double[T];
	        
	        for (int t = 0; t < T; t++) {
	            
	            int n = 0;
	            percolation = new Percolation(N);
	            
	            while(n < N * N) {
	                
	                int i = StdRandom.uniform(N);
	                int j = StdRandom.uniform(N);
	                
	                if (percolation.isOpen(i, j))
	                    continue;
	                
	                n++;
	                percolation.open(i, j);
	                
	                if (percolation.percolates()) {
	                    floatList[t] = n / (double) (N * N);
	                    break;
	                }
	            }
	        }
	    }
	    
	    public double mean() {
	        return StdStats.mean(floatList);
	    }
	    
	    public double stddev() {
	        return StdStats.stddev(floatList);
	    }
	    
	    public static void main(String[] args) {
	        int N = 200;
	        int T = 100;
	        PercolationStats stats = new PercolationStats(N, T);
	        
	        double mean = stats.mean();
	        double stddev = stats.stddev();	        
	        
	        System.out.println("PercolationStats"+"("+N+","+ T+")");
	        System.out.println("mean()                    = " + mean);
	        System.out.println("stddev()                  = " + stddev);
	        System.out.println("confidenceLow()           = " + stats.confidenceLow());
	        System.out.println("confidenceHigh()          = " + stats.confidenceHigh());
	        
	    }
	    
	    //calculates confidencelow
	    public double confidenceLow()
	    {
	    	return mean() - ((1.96 * stddev()) / Math.sqrt(numberOfRuns));
	    }
	    //calculates conficendHigh
	    public double confidenceHigh()
	    {
	    	return mean() + ((1.96 * stddev()) / Math.sqrt(numberOfRuns));
	    }
}
