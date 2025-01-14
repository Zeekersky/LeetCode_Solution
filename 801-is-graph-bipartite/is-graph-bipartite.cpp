class Solution {
public:
    bool isBipartite(vector<vector<int>>&adj) {
        int n=adj.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while(!q.empty()){
                    for(int k=q.size(); k>0; k--){
                        int node = q.front();
                        q.pop();
                        for(int j=0; j<adj[node].size(); j++){
                            if(color[adj[node][j]]==-1){
                                q.push(adj[node][j]);
                                color[adj[node][j]] = color[node]==0?1:0;
                            }
                            else{
                                if(color[adj[node][j]] == color[node]) return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};