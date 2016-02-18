import java.util.*;


import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.DirectedCycle;
import edu.princeton.cs.introcs.In;


public class WordNet 
{
	private Digraph G; // Graph
	private SAP sap; // SAP 

	private int graphLength = 0;
	
	private Map<String, ArrayList<Integer>> nouns = new HashMap<String, ArrayList<Integer>>();
	private Map<Integer, String> synsets = new HashMap<Integer, String>(); 
	private Map<Integer, ArrayList<Integer>> edges = new HashMap<Integer, ArrayList<Integer>>(); 
	public WordNet(String synsets, String hypernyms) {

		// Process data files
		processSynsets(synsets);
		processHypernyms(hypernyms);
		
		// Construct the graph
		this.G = new Digraph(this.graphLength);

		for (Map.Entry<Integer, ArrayList<Integer>> entry : edges.entrySet()) {
			for (Integer w : entry.getValue()) {
				this.G.addEdge(entry.getKey(), w);
			}
		}

		// Check for cycles
		DirectedCycle cycle = new DirectedCycle(this.G);
		if (cycle.hasCycle()) {
			throw new IllegalArgumentException("Not a valid DAG");
		}

		// Check if not rooted
		int rooted = 0;
		for (int i = 0; i < G.V(); i++) {
			if (!this.G.adj(i).iterator().hasNext())
				rooted++;
		}

		if (rooted != 1) {
			throw new IllegalArgumentException("Not a rooted DAG");
		}

		this.sap = new SAP(this.G);
	}

	public Iterable<String> nouns() {
		return this.nouns.keySet();
	}

	public boolean isNoun(String word) {
		return this.nouns.containsKey(word);
	}

	public int distance(String nounA, String nounB) {
		
		if(!this.nouns.containsKey(nounA) || !this.nouns.containsKey(nounB))
			throw new IllegalArgumentException("Not a valid pair of nouns");
		
		return this.sap.length(this.nouns.get(nounA), this.nouns.get(nounB));
	}

	public String sap(String nounA, String nounB) {
		
		if(!this.nouns.containsKey(nounA) || !this.nouns.containsKey(nounB))
			throw new IllegalArgumentException("Not a valid pair of nouns");
			
		int ancestor = this.sap.ancestor(this.nouns.get(nounA),	this.nouns.get(nounB));

		return this.synsets.get(ancestor);
	}


	private void processSynsets(String synsets) {
		In in = new In(synsets);
		String line = null;

		ArrayList<Integer> currentNounsList = null;
		String currentSynsetNouns = null;
		
		while ((line = in.readLine()) != null) {

			if (line.equals("")) {	continue;	}

			
			String[] lineElements = line.split(","); // split line
			String[] nouns = lineElements[1].split(" "); // get the second field
			int synsetId = Integer.parseInt(lineElements[0]);

			for (String noun : nouns) {
				if (this.nouns.containsKey(noun)) { 
					currentNounsList = this.nouns.get(noun);
				} else {
					currentNounsList = new ArrayList<Integer>(); 
				}
				
				if (this.synsets.containsKey(synsetId)) { 
					currentSynsetNouns = this.synsets.get(synsetId);
				} else {
					currentSynsetNouns = new String(); 
				}
				
				
				currentNounsList.add(synsetId); 
				currentSynsetNouns = lineElements[1];

				this.nouns.put(noun, currentNounsList);
				this.synsets.put(synsetId, currentSynsetNouns);
			}
			
			this.graphLength++;
		}
	}

	private void processHypernyms(String hypernym) {
		In in = new In(hypernym);
		String line = null;
		ArrayList<Integer> edgeList;
		
		while ((line = in.readLine()) != null) {

			if (line.equals("")) {	continue;	}

			// split line
			String[] lineElements = line.split(",");

			if (edges.get(Integer.parseInt(lineElements[0])) != null) {
				edgeList = edges.get(Integer.parseInt(lineElements[0]));
			} else {
				edgeList = new ArrayList<Integer>();
			}

			for (int i = 1; i < lineElements.length; i++) {
				edgeList.add(Integer.parseInt(lineElements[i]));
			}

			edges.put(Integer.parseInt(lineElements[0]), edgeList);

		}
	}

	public static void main(String[] args) {
		WordNet w = new WordNet("synsets.txt", "hypernyms.txt");
		System.out.println(w.sap("Rameses_the_Great", "Henry_Valentine_Miller")); 
		System.out.println(w.distance("Rameses_the_Great", "Henry_Valentine_Miller")); 
	}
}
