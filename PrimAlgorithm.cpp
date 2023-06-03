#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define V 5

int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, min_index;
    for(int v=0; v<V; v++){
        if(mstSet[v]==false && key[v] < min)
            min = key[v], min_index = v;
    }
    return min_index;
    
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
 

void primMST(int graph[V][V]){
    int parent[V];

    int key[V];

    bool mstSet[V];

    for(int i=0; i<V; i++){
        key[i] = INT_MAX, mstSet[i] = false;
    }
    key[0]=0;
    parent[0] = -1;

    for(int count = 0; count < V-1; count++){
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for(int v=0; v<V; v++){
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}
/*
Algorithm explanation:
The given code is an implementation of Prim's algorithm for finding the Minimum Spanning Tree (MST) of a weighted undirected graph. Here's a step-by-step explanation of what the code does:

1. Initialize necessary variables and data structures:
   - `parent`: An array to store the parent (predecessor) of each vertex in the MST.
   - `key`: An array to store the key value (minimum weight) of each vertex.
   - `mstSet`: A boolean array to track whether a vertex is included in the MST or not.

2. Initialize the `key` array with a maximum value (INT_MAX) and the `mstSet` array with `false` for all vertices. This indicates that no vertices have been included in the MST yet.

3. Set the key value of the first vertex (0) as 0, indicating it as the starting vertex. Also, set its parent as -1 to mark it as the root of the MST.

4. Run a loop `V-1` times, where `V` is the total number of vertices in the graph. This loop will select `V-1` edges to construct the MST.

5. Find the vertex `u` with the minimum key value among the vertices not yet included in the MST. The `minKey` function is assumed to return the index of the minimum key value.

6. Mark vertex `u` as included in the MST by setting `mstSet[u] = true`.

7. Iterate over all the vertices `v` in the graph.

8. For each vertex `v`, check if it is adjacent to `u` (`graph[u][v] != 0`) and if it is not already included in the MST (`mstSet[v] == false`). Additionally, check if the weight of the edge between `u` and `v` is less than the current key value of `v`.

9. If the conditions are satisfied, update `parent[v]` to store `u` as its parent and update `key[v]` with the weight of the edge `graph[u][v]`.

10. After the loop, the MST has been constructed. Call the `printMST` function to display the MST, passing the `parent` array and the original graph as parameters.

It's worth noting that the code you provided assumes the existence of a `minKey` function and a `printMST` function, which are not shown in the provided code snippet. These functions would be responsible for finding the vertex with the minimum key value and printing the MST, respectively.
*/

int main(){
    
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 

    primMST(graph);


    return 0;
}