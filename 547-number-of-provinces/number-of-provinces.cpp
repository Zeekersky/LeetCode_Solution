class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(), cnt = 0;
        vector<bool> vis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsG(i, isConnected, vis);
                cnt++;
            }
        }
        return cnt;
    }
    void dfsG(int node, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = 1;
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i] && !vis[i]) dfsG(i, adj, vis);
        }
    }
};