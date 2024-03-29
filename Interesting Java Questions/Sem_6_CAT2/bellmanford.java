//Time Complexity: O(VE) where V is the number of vertices and E is the number of edges.
//Space Complexity: O(V) for the `dist` array.

import java.util.Scanner;

public class BellmanFord {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int numVertices = scanner.nextInt();

        int[][] graph = new int[numVertices][numVertices];

        System.out.println("Enter the adjacency matrix (0 for no edge):");
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }

        System.out.print("Enter the source vertex index (0-based): ");
        int sourceVertex = scanner.nextInt();

        scanner.close();

        int[] distances = bellmanFord(graph, sourceVertex);

        // Print shortest distances from source vertex
        System.out.println("Shortest distances from source vertex " + sourceVertex + ":");
        for (int i = 0; i < distances.length; i++) {
            System.out.println(i + ": " + distances[i]);
        }
    }

    // Bellman-Ford algorithm implementation
    public static int[] bellmanFord(int[][] graph, int source) {
        int numVertices = graph.length;
        int[] distances = new int[numVertices];
        for (int i = 0; i < numVertices; i++) {
            distances[i] = Integer.MAX_VALUE;
        }
        distances[source] = 0;

        // Relax all edges repeatedly
        for (int i = 0; i < numVertices - 1; i++) {
            for (int u = 0; u < numVertices; u++) {
                for (int v = 0; v < numVertices; v++) {
                    if (graph[u][v] != 0 && distances[u] != Integer.MAX_VALUE && distances[u] + graph[u][v] < distances[v]) {
                        distances[v] = distances[u] + graph[u][v];
                    }
                }
            }
        }

        // Check for negative weight cycles
        for (int u = 0; u < numVertices; u++) {
            for (int v = 0; v < numVertices; v++) {
                if (graph[u][v] != 0 && distances[u] != Integer.MAX_VALUE && distances[u] + graph[u][v] < distances[v]) {
                    System.out.println("Graph contains negative weight cycle");
                    return null;
                }
            }
        }

        return distances;
    }
}
