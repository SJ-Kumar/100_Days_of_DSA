// TC - O(V+E)
// SC- O(V)
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
        void BFS(int s) {
                boolean visited[] = new boolean[V];
                Queue<Integer> queue = new LinkedList<>();
                visited[s] = true;
                queue.add(s);
                while (!queue.isEmpty()) {
                    s = queue.poll();
                    System.out.print(s + " ");
                    for (int n : adj[s]) {
                        if (!visited[n]) {
                            visited[n] = true;
                            queue.add(n);
                        }
                    }
                }
        }
        // DFS algorithm
        void DFSUtil(int v, boolean visited[]) {
            visited[v] = true;
            System.out.print(v + " ");
            for (int n : adj[v]) {
                if (!visited[n]) {
                    DFSUtil(n, visited);
                }
            }
        }

        void DFS(int v) {
            boolean visited[] = new boolean[V];
            DFSUtil(v, visited);
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

        System.out.print("Enter the starting vertex for DFS traversal: ");
        int startVertex = scanner.nextInt();

        System.out.println("Following is Depth First Traversal starting from vertex " + startVertex + ":");
        g.BFS(startVertex);
        g.DFS(startVertex);

        scanner.close();
    }
}
