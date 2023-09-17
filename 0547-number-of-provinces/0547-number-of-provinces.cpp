class Solution {
public:
void traverse( vector<int> adj[],int visited[],int node){
        visited[node]=1;
        for(auto it : adj[node]){
            if(!visited[it]){
                traverse(adj,visited,it);
            }
        }
    }
    

    int findCircleNum(vector<vector<int>>& m) {
        int n=m.size();
        vector<int> v[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]==1 && i!=j){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        int visited[n];
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                traverse(v,visited,i);
            }
        }
        return count;
    }
};