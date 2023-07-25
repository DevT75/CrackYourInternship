#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution{
    public:
    //Function to return list containing vertices in Topological order. 
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        // code here
        vector<int> inDegree(V,0);
        for(int i = 0;i < V;i++){
            for(auto j : adj[i]) inDegree[j]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0;i < V;i++) if(inDegree[i] == 0) q.push(i);
        while(!q.empty()){
           int node = q.front();
           ans.push_back(node);
           q.pop();
           for(auto j : adj[node]){
               inDegree[j]--;
               if(inDegree[j] == 0) q.push(j);
           }
        }
        return ans;
    }
};
int main(){
    int v,e;
    cin >> v >> e;
    vector<int> adj[v + 1];
    for(int i = 0;i < v;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    Solution s;
    vector<int> topsort = s.topoSort(v,adj);
    for(auto i : topsort) cout << i << " ";
}
