#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _z ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap; //creating heap to store minimum weight
        vector<bool> arr(n);
        heap.push({ 0, 0 });
        int mincost = 0;
        int remaning = 0;
        while (remaning < n) {
            pair<int, int> topElement = heap.top();
            heap.pop();
            
            int weight = topElement.first;
            int currNode = topElement.second;
            if(arr[currNode]){
                continue;
            }
            
            arr[currNode] = true;
            mincost += weight;
            remaning++;
            
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                if (!arr[nextNode]) {
                    int nextWeight = abs(points[currNode][0] - points[nextNode][0]) + 
                                     abs(points[currNode][1] - points[nextNode][1]);
                    
                    heap.push({ nextWeight, nextNode });
                }
            }
        }
        
        return mincost;
    }
};

/* EXPLANATION:

1. Initialize necessary variables and data structures:
   - `n`: The total number of points.
   - `heap`: A priority queue (min-heap) to store pairs of weights and corresponding nodes in ascending order of weights. This heap will help select the edge with the minimum weight.
   - `arr`: A boolean vector to track which nodes have been processed.
   - Initialize `heap` with a pair `{0, 0}`, representing the starting node (point) with weight 0.
   - Initialize `mincost` as 0 to store the total minimum cost.
   - Initialize `remaning` as 0 to track the number of processed nodes.

2. Start a while loop that continues until all nodes are processed (`remaning` is equal to `n`).

3. Get the top element (pair) from the heap using `heap.top()`. This element represents the edge with the minimum weight.

4. Remove the top element from the heap using `heap.pop()`.

5. Extract the weight and the current node from the top element.

6. Check if the current node has already been processed (`arr[currNode] == true`). If so, continue to the next iteration of the loop.

7. Mark the current node as processed by setting `arr[currNode]` to `true`.

8. Add the weight of the current edge to the `mincost`.

9. Increment the `remaning` counter to indicate that a node has been processed.

10. Iterate over all the nodes in the graph (`nextNode`), excluding the already processed nodes.

11. Calculate the weight of the edge between the current node (`currNode`) and the next node (`nextNode`). The weight is calculated as the Manhattan distance between the x-coordinates and the y-coordinates of the two points.

12. Push a new pair `{nextWeight, nextNode}` into the heap, representing the weight and the next node to consider.

13. After the while loop, all nodes have been processed, and the minimum cost to connect all points has been calculated.

14. Return the `mincost`.

The solution uses a greedy approach by iteratively selecting the edge with the minimum weight and connecting the unprocessed nodes. The priority queue (min-heap) helps to efficiently select the edge with the smallest weight at each iteration, ensuring the minimum cost to connect all points.



*/



int main(){
    
    return 0;
}