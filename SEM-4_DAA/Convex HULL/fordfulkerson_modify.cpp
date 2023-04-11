/*
Ford-Fulkerson algorithm uses Max-flow min-cut theorem for computing the maximum flow value in G.
Max-flow min-cut theorem:
If f is a flow in a flow network G = (V, E) with source s and sink t, then the following conditions are equivalent:
1. f is a maximum flow in G.
2. The residual network Gf contains no augme nting paths.
3. f = c(S, T ) for some cut (S, T ) of G.
Ford-Fulkerson relies on the augumenting path of the residual flow netwrok
for the computation of the maximum flow value. Instead, modify the given below Ford Fulkerson c++ code(remove comments) to compute the maximum flow value based on the cut of the graph G. 

*/


#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
#include<vector>
using namespace std;
void print_graph(vector<vector<int> >);

/* Returns true if there is a path from source 's' to sink
't' in residual graph. Also fills path to store the
path */
bool find_Path_From_Source_BFS(vector<vector<int> > residual_graph, int s, int t, int parents[])
{
    // Create a visited array and mark all vertices as not
    // visited
    int num_vertices = residual_graph.size();
    vector<bool> visited(false,num_vertices);
    

    // Create a queue, enqueue source vertex and mark source
    // vertex as visited
    queue<int> q;
    cout<<"BFS called"<<endl;
    cout<<s<<" ";
    q.push(s);
    visited[s] = true;
    parents[s] = -1;

    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < num_vertices; v++) {
            if (visited[v] == false && residual_graph[u][v] > 0) {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return
                // true
                if (v == t) {
                    parents[v] = u;
                    cout<<endl;
                    return true;
                }
                cout<<v<<" ";
                q.push(v);
                parents[v] = u;
                visited[v] = true;
            }
        }
    }

    // We didn't reach sink in BFS starting from source, so
    // return false
    cout<<endl;
    return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(vector<vector<int> > graph)
{
    int s, t,i,j,u,v,num_vertices;
    s = 0;
    t = graph.size()-1;
    // Create a residual graph and invoke copy constructor
    // to fill the residual graph
    // with given capacities in the original graph as
    // residual capacities in residual graph
    vector<vector<int> > residual_graph(graph);
    num_vertices = residual_graph.size();
    //cout<<"residual_graph"<<endl;
    //print_graph(residual_graph);
    // Residual graph indicates residual capacity of edge
    

    int parents[num_vertices]; // This array is filled by BFS and to
                // store path

    int max_flow = 0; // There is no flow initially

    // Augment the flow while there is path from source to
    // sink
    while (find_Path_From_Source_BFS(residual_graph, s, t, parents)) {
        // Find minimum residual capacity that is bottleneck 
        // of the edges along the path filled by BFSa
        int path_flow = INT_MAX;
        
        for (v = t; v != s; v = parents[v]) {
            cout<<v<<" ";
            u = parents[v];
            path_flow = min(path_flow, residual_graph[u][v]);
        }
        cout<<endl;
        // update residual capacities of the edges and
        // reverse edges along the path
        for (v = t; v != s; v = parents[v]) {
            u = parents[v]
            residual_graph[u][v] -= path_flow;
        residual_graph[v][u] += path_flow;
    }

    // Compute the cut of the graph by running a BFS on the residual graph
    vector<bool> visited(num_vertices, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && residual_graph[u][v] > 0) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // Compute the maximum flow based on the cut of the graph
    for (int u = 0; u < num_vertices; u++) {
        for (int v = 0; v < num_vertices; v++) {
            if (visited[u] && !visited[v] && graph[u][v] > 0) {
                max_flow += graph[u][v];
            }
        }
    }
}

// Return the overall flow
return max_flow;
