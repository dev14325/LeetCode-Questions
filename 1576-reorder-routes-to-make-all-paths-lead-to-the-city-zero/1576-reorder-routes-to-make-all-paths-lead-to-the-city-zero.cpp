class Solution {
public:

    void dfs(int v,int prevPath, vector<vector<pair<int,int>>>&adj, vector<int>&vis, vector<int>&away) {
        vis[v] = 1;
        if(prevPath == 0) {
            away[v] = 1;
        }
        for(auto child: adj[v]) {
            int child_v = child.first;
            int child_wt = child.second;
            if(vis[child_v]) continue;
            dfs(child_v, child_wt , adj, vis, away);
        }
    }


    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>vis(n,0);
        vector<int>away(n,0);
        for(auto connection: connections) {
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        dfs(0,-1, adj, vis, away);

        vector<vector<pair<int,int>>>adj1(n);
        // for(int i=0;i<n;i++) {
        //     cout<<away[i]<<" ";
        // }
        // cout<<"\n";

        for(auto connection: connections) {
            int u = connection[0];
            int v = connection[1];

            if(away[v]) {
                adj1[u].push_back({v, 1});
                adj1[v].push_back({u, 0});
            } else {
                adj1[u].push_back({v,0});
                adj1[v].push_back({u, 1});
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++) {
            ans+=away[i];
        }
        return ans;
    }
};