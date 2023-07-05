#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	vector<int> bfs(int V,vector<int> adj[]){
		vector<int> ans;
		queue<int> q;
		vector<bool> visited(V + 1,false);
		q.push(0);
		while(!q.empty()){
			int temp = q.front();
			q.pop();
			ans.push_back(temp);
			visited[temp] = true;
			for(auto i : adj[temp]){
				if(!visited[i]){
					q.push(i);
					visited[i] = true;
				}
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
	vector<int> bfsVector = s.bfs(v,adj);
	for(auto i : bfsVector) cout << i << " ";
}