#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

class Solution{
public:
	bool isBipartite(int v,vector<int> adj[],vector<int>&col){
		queue<int> q;
		q.push(0);
		col[0] = 1;
		while(!q.empty()){
			int node = q.front();q.pop();
			for(auto i : adj[node]){
				if(col[i] == col[node]) return false;
				else{
					if(col[i] != -1) continue;
					col[i] = 1 - col[node];
				}
			}
		}
	return true;
	}
};

int main(){
	int v,e;cin >> v >> e;
	vector<int> adj[v];
	for(int i = 0;i < e;i++){
		int a,b;cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> col(v,-1);
	Solution s;
	cout << (s.isBipartite(v,adj,col) ? "yes" : "no");
	return 0;
}
