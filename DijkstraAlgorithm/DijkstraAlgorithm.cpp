#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;  // pair of node and distance

void dijkstra(vector<vector<pii>>& graph, int source, int target) {
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    vector<int> previous(n, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distances[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == target) {
            break;  // Target node reached, exit the loop
        }

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            int newDistance = distances[u] + weight;
            if (newDistance < distances[v]) {
                distances[v] = newDistance;
                previous[v] = u;
                pq.push(make_pair(newDistance, v));
            }
        }
    }

    if (distances[target] == INT_MAX) {
        cout << "No path found from source to target." << endl;
    } else {
        cout << "Shortest path distance: " << distances[target] << endl;
        cout << "Shortest path: ";
        int node = target;
        vector<int> path;
        while (node != -1) {
            path.push_back(node);
            node = previous[node];
        }
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 6;  // Number of nodes
    vector<vector<pii>> graph(n);

    // Add edges and weights to the graph
    graph[0].push_back(make_pair(1, 5));
    graph[0].push_back(make_pair(2, 3));
    graph[1].push_back(make_pair(3, 6));
    graph[1].push_back(make_pair(2, 2));
    graph[2].push_back(make_pair(4, 4));
    graph[2].push_back(make_pair(5, 2));
    graph[2].push_back(make_pair(3, 7));
    graph[3].push_back(make_pair(4, -1));
    graph[4].push_back(make_pair(5, -2));

    int source = 0;    // Source node
    int target = 5;    // Target node

    dijkstra(graph, source, target);

    return 0;
}
