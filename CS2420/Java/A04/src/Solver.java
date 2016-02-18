import java.util.*;

import edu.princeton.cs.algs4.MinPQ;
import edu.princeton.cs.introcs.In;
import edu.princeton.cs.introcs.StdOut;


public class Solver
{
	private MinPQ<SearchNode> pq;
    
    private MinPQ<SearchNode> pqTwin;
    
    private SearchNode goal = null;
    
    private boolean solvable = true;
    
    private final Comparator<SearchNode> byHamming = new ByHamming();
    private final Comparator<SearchNode> byManhattan = new ByManhattan();
    
    public Solver(Board initial) {
        pq = new MinPQ<SearchNode>(byManhattan);
        pqTwin = new MinPQ<SearchNode>(byHamming);
        
        SearchNode initNode = new SearchNode(initial, 0, null);
        pq.insert(initNode);
        
        Board twin = initial.twin();
        SearchNode twinNode = new SearchNode(twin, 0, null);
        pqTwin.insert(twinNode);
        
        boolean solved = false;
        while (!solved) {
            solved = solve();
        }
    }

    private class ByHamming implements Comparator<SearchNode> {
        public int compare(SearchNode n1, SearchNode n2) {
            return n1.board.hamming() 
                - n2.board.hamming();
        }
    }
    
    private class ByManhattan implements Comparator<SearchNode> {
        public int compare(SearchNode n1, SearchNode n2) {
            return n1.board.manhattan()
                    + n1.moves 
                    - n2.board.manhattan()
                    - n2.moves;
        }
    }
    
    private class SearchNode {
        private Board board;
        private int moves;
        private SearchNode prev;
        
        private int hash = 0;
        
        public SearchNode(Board b, int m, SearchNode p) {
            board = b;
            moves = m;
            prev = p;
        }
        
        public boolean equals(Object y) {
            if (y == this) return true;
            if (y == null) return false;
            if (y.getClass() != this.getClass()) return false;
            
            SearchNode that = (SearchNode) y;
            if (that.board.equals(board)) {
                return true;
            }
            return false;
        }
        
        public int hashCode() {
            if (hash != 0) {
                return hash;
            }
            hash = board.toString().hashCode();
            return hash;
        }
    }

    private boolean solve() {
        
        
        SearchNode node = pq.delMin();
        if (node.board.isGoal()) {
            goal = node;
            return true;
        }

        for (Board board : node.board.neighbors()) {
            SearchNode n = new SearchNode(board, node.moves + 1, node);
            if (n.equals(node.prev)) {
                continue;
            }

            pq.insert(n);
        }
        
        
        SearchNode twinNode = pqTwin.delMin();
        if (twinNode.board.isGoal()) {
            solvable = false;
            return true;
        }
        
        for (Board board : twinNode.board.neighbors()) {

            SearchNode n = new SearchNode(board, node.moves + 1, node);
            if (n.equals(twinNode.prev)) {
                continue;
            }

            pqTwin.insert(n);
        }
        Board twin = node.board.twin();
        twinNode = new SearchNode(twin, 0, null);
        pqTwin.insert(twinNode);
        return false;
    }
    
   
    public boolean isSolvable() {
        return solvable;
    }
    

    public int moves() {
        if (!solvable) {
            return -1;
        }
        return goal.moves;
    }
    
    
    public Iterable<Board> solution() {
        
        if (goal == null) {
            return null;
        }
        
        Stack<Board> stack = new Stack<Board>();
        SearchNode node = goal;
        stack.push(node.board);
        while (node.prev != null) {
            stack.push(node.prev.board);
            node = node.prev;
        }
        
        return stack;
    }
    
   
    public static void main(String[] args) {
        // create initial board from file
        In in = new In(args[0]);
        int N = in.readInt();
        int[][] blocks = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                blocks[i][j] = in.readInt();
        Board initial = new Board(blocks);

        // solve the puzzle
        Solver solver = new Solver(initial);

        // print solution to standard output
        if (!solver.isSolvable())
            StdOut.println("No solution possible");
        else {
            StdOut.println("Minimum number of moves = " + solver.moves());
            for (Board board : solver.solution())
                StdOut.println(board);
        }
    }
}
