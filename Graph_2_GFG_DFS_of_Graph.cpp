#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void dfs(int source,vector<int> adj[],vector<bool>&visited,vector<int>& ans){
		ans.push_back(source);
		visited[source] = true;
		for(auto i : adj[source]){
			if(!visited[i]){
				visited[i] = true;
				dfs(i,adj,visited,ans);
			}
		}
	}
	vector<int> dfsTraversal(int V,vector<int> adj[]){
		vector<bool> visited(V + 1,false);
		vector<int> ans;
		dfs(0,adj,visited,ans);
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
	vector<int> dfsVector = s.dfsTraversal(v,adj);
	for(auto i : dfsVector) cout << i << " ";
}