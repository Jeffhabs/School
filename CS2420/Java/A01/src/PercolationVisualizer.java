import edu.princeton.cs.introcs.In;
import edu.princeton.cs.introcs.StdDraw;
import java.awt.Font;


public class PercolationVisualizer
{
	// delay in miliseconds (controls animation speed)
    private final static int DELAY = 100;

    // draw N-by-N percolation system
    public static void draw(Percolation perc, int N) {
        StdDraw.clear();
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.setXscale(-.05*N, 1.05*N);
        StdDraw.setYscale(-.05*N, 1.05*N);   // leave a border to write text
        StdDraw.filledSquare(N/2.0, N/2.0, N/2.0);

        // draw N-by-N grid
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (perc.isFull(row, col)) {
                    StdDraw.setPenColor(StdDraw.BOOK_LIGHT_BLUE);
                }
                else if (perc.isOpen(row, col)) {
                    StdDraw.setPenColor(StdDraw.WHITE);
                }
                else {
                    StdDraw.setPenColor(StdDraw.BLACK);
                }
                StdDraw.filledSquare(col + 0.5, N - row - 0.5, 0.45);
            }
        }

        // write status text
        StdDraw.setFont(new Font("SansSerif", Font.PLAIN, 12));
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.text(.25*N, -N*.025, perc.numberOfOpenSites() + " open sites");
        if (perc.percolates()) StdDraw.text(.75*N, -N*.025, "percolates");
        else                   StdDraw.text(.75*N, -N*.025, "does not percolate");

    }

    private static void simulateFromFile(String filename) {
        In in = new In(filename);
        int N = in.readInt();
        Percolation perc = new Percolation(N);

        // turn on animation mode
        StdDraw.show(0); 

        // repeatedly read in sites to open and draw resulting system
        draw(perc, N);
        StdDraw.show(DELAY);
        while (!in.isEmpty()) {
            int i = in.readInt();
            int j = in.readInt();
            perc.open(i, j);
            draw(perc, N);
            StdDraw.show(DELAY);
        }
    }

    public static void main(String[] args)
    {
        String filename = args[0];
        simulateFromFile(filename);
 
    }
}
