/**
 * Definition for Directed graph.
 * class DirectedGraphNode {
 *     int label;
 *     ArrayList<DirectedGraphNode> neighbors;
 *     DirectedGraphNode(int x) { label = x; neighbors = new ArrayList<DirectedGraphNode>(); }
 * };
 */
// BFS SOLUTION
public class Solution {
   /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    // BFS VERSION
    public boolean hasRoute(ArrayList<DirectedGraphNode> graph, DirectedGraphNode s, DirectedGraphNode t) {
        if (s == t) return true;

        HashSet<DirectedGraphNode> visited = new HashSet<DirectedGraphNode>();
        Queue<DirectedGraphNode> queue = new LinkedList<DirectedGraphNode>();
        
        queue.add(s);
        visited.add(s);
        while (!queue.isEmpty()) {
            DirectedGraphNode node = queue.remove();
            for (int i = 0; i < node.neighbors.size(); i++) {
                if (!visited.contains(node.neighbors.get(i))) {
                    visited.add(node.neighbors.get(i));
                    queue.add(node.neighbors.get(i));
                    if (node.neighbors.get(i) == t) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

    // DFS VERSION
    public boolean dfs(ArrayList<DirectedGraphNode> graph, DirectedGraphNode s, DirectedGraphNode t, Set<DirectedGraphNode> visited) {
        if (s == t) return true;
            visited.add(s);
            // compare unvisited neighbor nodes recursively
            if (s.neighbors.size() > 0) {
                for (DirectedGraphNode node : s.neighbors) {
                    if (!visited.contains(node)){
                        if (dfs(graph, node, t, visited)) return true;
                    }
                }
            }
        }

        return false;
    }
}

