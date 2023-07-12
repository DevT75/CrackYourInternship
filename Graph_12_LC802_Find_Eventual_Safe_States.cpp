class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int src,vector<bool>&vis,vector<bool>&recVis,vector<bool>&check){
        vis[src] = true;
        recVis[src] = true;
        check[src] = false;
        for(auto i : graph[src]){
            if(!vis[i] && dfs(graph,i,vis,recVis,check)){
                check[src] = false;
                return true;
            }
            else if(recVis[i]){
                check[src] = false;
                return true;
            }
        }
        check[src] = true;
        recVis[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<bool> vis(v,false),pathVis(v,false),check(v,false);
        vector<int> ans;
        for(int i = 0;i < v;i++){
            if(!vis[i]){
                dfs(graph,i,vis,pathVis,check);
            }
        }
        for(int i = 0;i < v;i++){
            if(check[i] == true) ans.push_back(i);
        }
        return ans;
    }
};