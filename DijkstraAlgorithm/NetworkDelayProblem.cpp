/* Question: 
LeetCode question: 743
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        vector<int> dis(n+1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto i : times){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v,wt});
        }

        dis[0] = -1e9;
        dis[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for(auto node : adj[u]){
                int v = node.first;
                int wt = node.second;
                if(d + wt < dis[v]){
                    dis[v] =  d + wt;
                    pq.push({dis[v], v});
                }
            }
        }

        for(auto i : dis){
            if(i==1e9) 
                return -1;
        }

        return *max_element(dis.begin(), dis.end());
    }
};
