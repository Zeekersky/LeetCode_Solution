class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> dfs;
        vector<int> empt;
        vector<int> vis(numCourses, 0);
        bool cycle;
        vector<vector<int>> adj(numCourses);
        for (auto& it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        for(int i=numCourses-1; i>=0; i--){
            if(!vis[i])
                dfsG(i, adj, dfs, vis, cycle);
            if(cycle) return empt;
        }
        return dfs;
    }

    void dfsG(int node, vector<vector<int>>& adj, vector<int>& dfs, vector<int>& vis, bool& cycle) {
        if (cycle) return;

        vis[node] = 1;
        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                dfsG(it, adj, dfs, vis, cycle);
            } else if (vis[it] == 1) {
                cycle = true;
                return;
            }
        }
        vis[node] = 2;
        dfs.push_back(node);
    }

};