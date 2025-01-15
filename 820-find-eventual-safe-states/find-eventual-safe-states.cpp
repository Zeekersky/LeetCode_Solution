class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(i, adj, vis, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(vis[it] == 1) return false; // Cycle detected
            if(!vis[it] && !dfs(it, adj, vis, ans)) return false; // Any path returns false
        }
        vis[node] = 2;
        ans.push_back(node);
        return true;
    }
};