import java.util.*;

public class Main {
    static class Graph {
        private int V;
        private ArrayList<Integer>[] adj;

        // Create a graph
        Graph(int v) {
            V = v;
            adj = new ArrayList[v];
            for (int i = 0; i < v; ++i)
                adj[i] = new ArrayList<>();
        }

        // Add edges to the graph
        void addEdge(int v, int w) {
            adj[v].add(w);
        }

        // DFS algorithm
        void DFSUtil(int v, boolean visited[], Stack<Integer> stack) {
            visited[v] = true;
            for (int n : adj[v]) {
                if (!visited[n]) {
                    DFSUtil(n, visited, stack);
                }
            }
            // After visiting all adjacent vertices, push the current vertex onto the stack
            stack.push(v);
        }

        Stack<Integer> topologicalSort() {
            boolean visited[] = new boolean[V];
            Stack<Integer> stack = new Stack<>();

            // Run DFS on all vertices
            for (int i = 0; i < V; i++) {
                if (!visited[i]) {
                    DFSUtil(i, visited, stack);
                }
            }

            return stack;
        }
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();

        Graph g = new Graph(V);

        System.out.print("Enter the number of edges: ");
        int E = scanner.nextInt();

        System.out.println("Enter edges (source destination): ");
        for (int i = 0; i < E; i++) {
            int source = scanner.nextInt();
            int destination = scanner.nextInt();
            g.addEdge(source, destination);
        }

        Stack<Integer> result = g.topologicalSort();
        
        // Print the result
        System.out.println("Topological ordering:");
        while (!result.isEmpty()) {
            System.out.print(result.pop() + " ");
        }

        scanner.close();
    }
}
