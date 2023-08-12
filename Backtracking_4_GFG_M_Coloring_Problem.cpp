#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool dfs(int node,bool graph[101][101],vector<int>&col,int m,int n){
        if(node == n) return true;
        for(int i = 1;i <= m;i++){
            if(isValid(node,col,i,graph,n)){
                col[node] = i;
                if(dfs(node + 1,graph,col,m,n)) return true;
                col[node] = 0;
            }
        }
        return false;
    }
    bool isValid(int node,vector<int>&col,int c,bool graph[101][101],int n){
        for(int i = 0;i < n;i++){
            if(i != node && (graph[node][i] || graph[i][node]) && col[i] == c) return false;
        }
        return true;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n);
        if(dfs(0,graph,color,m,n)) return true;
        return false;
    }
};
int main(){
	int t;cin >> t;
	while(t--){
		int n,m,e;cin >> n >> m >> e;
		bool graph[101][101] = {0};
		// for(int i = 0;i < n;i++) memset(graph[i],0,sizeof(graph[i]));
		for(int i = 0;i < e;i++){
			int a,b;
			cin >> a >> b;
			graph[a - 1][b - 1] = 1;
			graph[b - 1][a - 1] = 1;
		}
		Solution s;
		cout << s.graphColoring(graph,m,n) << "\n";
	}
	return 0;
}
