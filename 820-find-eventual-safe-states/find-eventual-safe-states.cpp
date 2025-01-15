class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(i, -1, adj, vis, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans){
        vis[node] = 1;
        for(int i=0; i<adj[node].size(); i++){
            if(vis[adj[node][i]] == 1){
                return false; // Cycle detected
            }
            else if(!vis[adj[node][i]] && !dfs(adj[node][i], node, adj, vis, ans)) 
                return false; // Any path returns false
        }
        vis[node] = 2;
        ans.push_back(node);
        return true;
    }
};